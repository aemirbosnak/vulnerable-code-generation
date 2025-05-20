//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m, i, j;
  int **a, **b, **c;

  printf("Enter the dimensions of the matrices (n x m): ");
  scanf("%d %d", &n, &m);

  a = (int **)malloc(n * sizeof(int *));
  b = (int **)malloc(n * sizeof(int *));
  c = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    a[i] = (int *)malloc(m * sizeof(int));
    b[i] = (int *)malloc(m * sizeof(int));
    c[i] = (int *)malloc(m * sizeof(int));
  }

  printf("Enter the elements of matrix A:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the elements of matrix B:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  // Add the two matrices
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }

  // Print the resulting matrix
  printf("The sum of the two matrices is:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  // Free the allocated memory
  for (i = 0; i < n; i++) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }
  free(a);
  free(b);
  free(c);

  return 0;
}