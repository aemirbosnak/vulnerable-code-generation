//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void matrix_operations()
{
  int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
  int i, j, k, r, s;

  printf("Enter the number of rows and columns for the matrices:");
  scanf("%d %d", &r, &s);

  printf("Enter the elements of the first matrix:");
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < s; j++)
    {
      scanf("%d ", &a[i][j]);
    }
  }

  printf("Enter the elements of the second matrix:");
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < s; j++)
    {
      scanf("%d ", &b[i][j]);
    }
  }

  // Calculate the product of the two matrices
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < s; j++)
    {
      c[i][j] = 0;
      for (k = 0; k < MAX; k++)
      {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Print the product matrix
  printf("The product of the two matrices is:");
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < s; j++)
    {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  matrix_operations();

  return 0;
}