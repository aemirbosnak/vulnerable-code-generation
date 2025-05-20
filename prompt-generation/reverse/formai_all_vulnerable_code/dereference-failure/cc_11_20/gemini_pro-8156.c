//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define the size of the matrices
  int n = 3;

  // Allocate memory for the matrices
  int **a = (int **)malloc(n * sizeof(int *));
  int **b = (int **)malloc(n * sizeof(int *));
  int **c = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(n * sizeof(int));
    b[i] = (int *)malloc(n * sizeof(int));
    c[i] = (int *)malloc(n * sizeof(int));
  }

  // Initialize the matrices
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand() % 10;
      b[i][j] = rand() % 10;
      c[i][j] = 0;
    }
  }

  // Print the matrices
  printf("Matrix A:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix B:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }

  // Multiply the matrices
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Print the result matrix
  printf("\nResult Matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < n; i++) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }
  free(a);
  free(b);
  free(c);

  return 0;
}