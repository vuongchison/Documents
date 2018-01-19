#include <stdio.h>
#include <time.h>
int* A;
int n;

long maxSubseq()
{
	long max = A[0]; 
	for(int i = 0; i < n; i++)
	{
		int s = 0;
		for(int j = i; j < n; j++)
		{
			s += A[j];			
			if (s > max)
				max = s;
		}
	}
	return max;
}

void readFile(char* fn)
{
	FILE* f = fopen(fn, "r");
	fscanf(f, "%d", &n);
	A = new int[n];
	for(int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &A[i]);
	}
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Syntax Error\n%s inputFile\n", argv[0]);
		return 1;
	}
	
	
	readFile(argv[1]);
	
	time_t t = clock();
	printf("Max Weight: %ld\n", maxSubseq());
	printf("Time: %.2f\n", (float)(clock() - t)/CLOCKS_PER_SEC);
	
	delete A;
	return 0;
}