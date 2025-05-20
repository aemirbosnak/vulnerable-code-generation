//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int **p, **q;
  int i, j, m, n;

  printf("Enter the number of rows and columns for matrix 1: ");
  scanf("%d %d", &m, &n);

  // Allocate memory for matrix 1
  p = (int **)malloc(m * sizeof(int *));
  for (i = 0; i < m; i++) {
    p[i] = (int *)malloc(n * sizeof(int));
  }

  // Read the elements of matrix 1
  printf("Enter the elements of matrix 1:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &p[i][j]);
    }
  }

  printf("Enter the number of rows and columns for matrix 2: ");
  scanf("%d %d", &m, &n);

  // Allocate memory for matrix 2
  q = (int **)malloc(m * sizeof(int *));
  for (i = 0; i < m; i++) {
    q[i] = (int *)malloc(n * sizeof(int));
  }

  // Read the elements of matrix 2
  printf("Enter the elements of matrix 2:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &q[i][j]);
    }
  }

  // Add the two matrices
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      p[i][j] += q[i][j];
    }
  }

  // Print the resulting matrix
  printf("The resulting matrix is:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }

  // Free the allocated memory
  for (i = 0; i < m; i++) {
    free(p[i]);
  }
  free(p);

  for (i = 0; i < m; i++) {
    free(q[i]);
  }
  free(q);

  return 0;
}