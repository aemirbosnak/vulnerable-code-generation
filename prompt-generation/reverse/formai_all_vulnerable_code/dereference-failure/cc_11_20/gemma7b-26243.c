//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a = 5;
  int b = 3;
  int c = 2;

  int **matrixA = (int **)malloc(a * sizeof(int *));
  for (int i = 0; i < a; i++)
  {
    matrixA[i] = (int *)malloc(b * sizeof(int));
  }

  int **matrixB = (int **)malloc(c * sizeof(int *));
  for (int i = 0; i < c; i++)
  {
    matrixB[i] = (int *)malloc(b * sizeof(int));
  }

  // Matrix A initialization
  matrixA[0][0] = 1;
  matrixA[0][1] = 2;
  matrixA[1][0] = 3;
  matrixA[1][1] = 4;

  // Matrix B initialization
  matrixB[0][0] = 5;
  matrixB[0][1] = 6;
  matrixB[1][0] = 7;
  matrixB[1][1] = 8;

  // Matrix multiplication
  int **matrixC = (int **)malloc((a + c) * sizeof(int *));
  for (int i = 0; i < a + c; i++)
  {
    matrixC[i] = (int *)malloc(b * sizeof(int));
  }

  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < c; j++)
    {
      for (int k = 0; k < b; k++)
      {
        int sum = 0;
        for (int l = 0; l < b; l++)
        {
          sum += matrixA[i][l] * matrixB[l][j];
        }
        matrixC[i][j] = sum;
      }
    }
  }

  // Printing matrix C
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < c; j++)
    {
      printf("%d ", matrixC[i][j]);
    }
    printf("\n");
  }

  // Memory deallocation
  for (int i = 0; i < a; i++)
  {
    free(matrixA[i]);
  }
  free(matrixA);

  for (int i = 0; i < c; i++)
  {
    free(matrixB[i]);
  }
  free(matrixB);

  free(matrixC);

  return 0;
}