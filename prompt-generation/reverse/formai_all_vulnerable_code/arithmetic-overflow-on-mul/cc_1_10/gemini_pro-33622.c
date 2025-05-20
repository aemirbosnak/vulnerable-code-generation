//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// A matrix is a rectangular array of numbers.
// A vector is a special case of a matrix with only one row or column.
// In this program, we will perform some basic matrix operations,
// such as addition, subtraction, multiplication, and transposition.

// Define the size of the matrices and vectors.
#define M 2
#define N 3

// Define the matrices and vectors.
int A[M][N] = {{1, 2, 3}, {4, 5, 6}};
int B[M][N] = {{7, 8, 9}, {10, 11, 12}};
int C[M][N];
int v1[M] = {1, 2};
int v2[M] = {3, 4};
int v3[M];

// Define the functions to perform the matrix operations.
void addMatrices(int A[][N], int B[][N], int C[][N]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

void subtractMatrices(int A[][N], int B[][N], int C[][N]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
}

void multiplyMatrices(int A[][N], int B[][N], int C[][N]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      C[i][j] = 0;
      for (int k = 0; k < N; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void transposeMatrix(int A[][N], int C[][N]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      C[j][i] = A[i][j];
    }
  }
}

// Define the main function.
int main() {
  // Add the matrices A and B.
  addMatrices(A, B, C);

  // Print the sum of the matrices A and B.
  printf("The sum of the matrices A and B is:\n");
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  // Subtract the matrices A and B.
  subtractMatrices(A, B, C);

  // Print the difference of the matrices A and B.
  printf("The difference of the matrices A and B is:\n");
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  // Multiply the matrices A and B.
  multiplyMatrices(A, B, C);

  // Print the product of the matrices A and B.
  printf("The product of the matrices A and B is:\n");
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  // Transpose the matrix A.
  transposeMatrix(A, C);

  // Print the transpose of the matrix A.
  printf("The transpose of the matrix A is:\n");
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}