//FormAI DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Initialize matrix dimensions
  int m1, n1, m2, n2;
  printf("Enter dimensions of matrix A: ");
  scanf("%d %d", &m1, &n1);
  printf("Enter dimensions of matrix B: ");
  scanf("%d %d", &m2, &n2);

  // Ensure valid matrix dimensions
  if (n1 != m2) {
    printf("Matrices are not compatible for multiplication. Exiting program.");
    return 0;
  }

  // Allocate memory for matrix A and B
  int **A = (int**)malloc(m1 * sizeof(int*));
  int **B = (int**)malloc(m2 * sizeof(int*));
  for (int i = 0; i < m1; i++) {
    A[i] = (int*)malloc(n1 * sizeof(int));
  }
  for (int i = 0; i < m2; i++) {
    B[i] = (int*)malloc(n2 * sizeof(int));
  }

  // Fill matrix A and B with user input
  printf("Enter values for matrix A row-by-row:\n");
  for (int i = 0; i < m1; i++) {
    for (int j = 0; j < n1; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  printf("Enter values for matrix B row-by-row:\n");
  for (int i = 0; i < m2; i++) {
    for (int j = 0; j < n2; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  // Allocate memory for matrix C
  int **C = (int**)malloc(m1 * sizeof(int*));
  for (int i = 0; i < m1; i++) {
    C[i] = (int*)malloc(n2 * sizeof(int));
  }

  // Compute matrix multiplication
  for (int i = 0; i < m1; i++) {
    for (int j = 0; j < n2; j++) {
      int sum = 0;
      for (int k = 0; k < n1; k++) {
        sum += A[i][k] * B[k][j];
      }
      C[i][j] = sum;
    }
  }

  // Print matrix C
  printf("\nMatrix C = A * B:\n");
  for (int i = 0; i < m1; i++) {
    for (int j = 0; j < n2; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  // Free memory allocated for matrices
  for (int i = 0; i < m1; i++) {
    free(A[i]);
    free(C[i]);
  }
  for (int i = 0; i < m2; i++) {
    free(B[i]);
  }
  free(A);
  free(B);
  free(C);

  return 0;
}