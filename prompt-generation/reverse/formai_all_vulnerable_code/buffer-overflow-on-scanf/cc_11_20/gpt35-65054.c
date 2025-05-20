//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i, j, k, n;
  printf("Enter n for [n x n] matrix: ");
  scanf("%d", &n);

  int **A = (int**)malloc(n*sizeof(int*));
  for (i = 0; i < n; i++)
    A[i] = (int*)malloc(n*sizeof(int));

  int **B = (int**)malloc(n*sizeof(int*));
  for (i = 0; i < n; i++)
    B[i] = (int*)malloc(n*sizeof(int));

  int **C = (int**)malloc(n*sizeof(int*));
  for (i = 0; i < n; i++)
    C[i] = (int*)malloc(n*sizeof(int));

  printf("\nEnter elements of matrix A: ");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &A[i][j]);

  printf("\nEnter elements of matrix B: ");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &B[i][j]);

  printf("\nMatrix A is:\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
      printf("%d ", A[i][j]);
    printf("\n");
  }

  printf("\nMatrix B is:\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
      printf("%d ", B[i][j]);
    printf("\n");
  }

  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < n; ++j)
    {
      C[i][j] = 0;
      for (k = 0; k < n; ++k)
        C[i][j] += A[i][k] * B[k][j];
    }
  }

  printf("\nProduct of A and B is:\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
      printf("%d ", C[i][j]);
    printf("\n");
  }

  for (i = 0; i < n; i++)
  {
    free(A[i]);
    free(B[i]);
    free(C[i]);
  }
  free(A);
  free(B);
  free(C);

  return 0;
}