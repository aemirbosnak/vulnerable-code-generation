//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define the dimensions of the matrices
  int n1, m1, n2, m2;
  printf("Enter the number of rows and columns in the first matrix: ");
  scanf("%d %d", &n1, &m1);
  printf("Enter the number of rows and columns in the second matrix: ");
  scanf("%d %d", &n2, &m2);

  // Check if the matrices can be multiplied
  if (m1 != n2) {
    printf("The matrices cannot be multiplied.\n");
    return 1;
  }

  // Allocate memory for the matrices
  int **a = (int **)malloc(n1 * sizeof(int *));
  int **b = (int **)malloc(n2 * sizeof(int *));
  int **c = (int **)malloc(n1 * sizeof(int *));
  for (int i = 0; i < n1; i++) {
    a[i] = (int *)malloc(m1 * sizeof(int));
    b[i] = (int *)malloc(m2 * sizeof(int));
    c[i] = (int *)malloc(m2 * sizeof(int));
  }

  // Get the elements of the first matrix
  printf("Enter the elements of the first matrix:\n");
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < m1; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  // Get the elements of the second matrix
  printf("Enter the elements of the second matrix:\n");
  for (int i = 0; i < n2; i++) {
    for (int j = 0; j < m2; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  // Multiply the matrices
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < m2; j++) {
      c[i][j] = 0;
      for (int k = 0; k < m1; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Print the result matrix
  printf("The product of the two matrices is:\n");
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < m2; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  // Free the allocated memory
  for (int i = 0; i < n1; i++) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }
  free(a);
  free(b);
  free(c);

  return 0;
}