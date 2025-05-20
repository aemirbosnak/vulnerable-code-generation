//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int row, col, i, j;
  int **a = NULL, **b = NULL, **c = NULL;

  printf("Enter the number of rows for the matrices: ");
  scanf("%d", &row);

  printf("Enter the number of columns for the matrices: ");
  scanf("%d", &col);

  a = (int**)malloc(row * sizeof(int*));
  b = (int**)malloc(row * sizeof(int*));
  c = (int**)malloc(row * sizeof(int*));

  for (i = 0; i < row; i++)
  {
    a[i] = (int*)malloc(col * sizeof(int));
    b[i] = (int*)malloc(col * sizeof(int));
    c[i] = (int*)malloc(col * sizeof(int));
  }

  printf("Enter the elements of the first matrix (a):\n");
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the elements of the second matrix (b):\n");
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      scanf("%d", &b[i][j]);
    }
  }

  c = matrixMultiplication(a, b, row, col);

  printf("The product of the matrices (c) is:\n");
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  free(a);
  free(b);
  free(c);

  return 0;
}

int matrixMultiplication(int **a, int **b, int row, int col)
{
  int **c = NULL;
  int i, j, k;

  c = (int**)malloc(row * sizeof(int*));
  for (i = 0; i < row; i++)
  {
    c[i] = (int*)malloc(col * sizeof(int));
  }

  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      c[i][j] = 0;
      for (k = 0; k < col; k++)
      {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return c;
}