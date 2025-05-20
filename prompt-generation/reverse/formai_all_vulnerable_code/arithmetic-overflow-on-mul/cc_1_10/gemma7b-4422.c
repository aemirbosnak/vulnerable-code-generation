//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void mx_mul(int **a, int **b, int n)
{
  int i, j, k;
  int *c = (int *)malloc(n * n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      c[i * n + j] = 0;
      for (k = 0; k < n; k++)
      {
        if (a[i][k] && b[k][j])
          c[i * n + j] += a[i][k] * b[k][j];
      }
    }
  }

  *a = c;
}

int main()
{
  int n;
  scanf("Enter the number of rows: ", &n);
  int m;
  scanf("Enter the number of columns: ", &m);

  int **a = (int *)malloc(n * m * sizeof(int));
  int **b = (int *)malloc(n * m * sizeof(int));

  printf("Enter the elements of matrix A: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d ", &a[i][j]);
    }
  }

  printf("Enter the elements of matrix B: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d ", &b[i][j]);
    }
  }

  mx_mul(&a, &b, n);

  printf("The product of the two matrices is: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  free(a);
  free(b);
  free(*a);
  free(*b);

  return 0;
}