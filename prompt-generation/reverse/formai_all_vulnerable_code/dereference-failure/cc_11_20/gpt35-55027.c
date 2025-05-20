//FormAI DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  // Initializing the matrix dimensions
  int rows = 3, cols = 3;
  
  // Creating the matrices A, B and C
  int **A = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++)
    A[i] = (int *)malloc(cols * sizeof(int));

  int **B = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++)
    B[i] = (int *)malloc(cols * sizeof(int));

  int **C = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++)
    C[i] = (int *)malloc(cols * sizeof(int));
  
  // Initializing matrix A with random values
  printf("Matrix A:\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      A[i][j] = rand() % 10;
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  
  // Initializing matrix B with random values
  printf("\nMatrix B:\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      B[i][j] = rand() % 10;
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }
  
  // Performing matrix addition and storing the results in matrix C
  printf("\nMatrix C (Addition of matrix A and B):\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      C[i][j] = A[i][j] + B[i][j];
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  
  // Performing matrix multiplication and storing the results in matrix C
  printf("\nMatrix C (Multiplication of matrix A and B):\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      C[i][j] = 0;
      for(int k = 0; k < cols; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  
  // Freeing the matrices
  for(int i = 0; i < rows; i++) {
    free(A[i]);
    free(B[i]);
    free(C[i]);
  }
  free(A);
  free(B);
  free(C);

  return 0;
}