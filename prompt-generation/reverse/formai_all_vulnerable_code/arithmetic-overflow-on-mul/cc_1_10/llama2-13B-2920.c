//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5
#define N 4

// Matrix Operations
void matrix_add(int mat[M][N], int a, int b) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      mat[i][j] = mat[i][j] + a + b;
    }
  }
}

void matrix_subtract(int mat[M][N], int a, int b) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      mat[i][j] = mat[i][j] - a - b;
    }
  }
}

void matrix_multiply(int mat[M][N], int a, int b) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      int sum = 0;
      for (int k = 0; k < N; k++) {
        sum += mat[i][k] * a + mat[k][j] * b;
      }
      mat[i][j] = sum;
    }
  }
}

void matrix_transpose(int mat[M][N]) {
  int temp[N][M];
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      temp[j][i] = mat[i][j];
    }
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      mat[i][j] = temp[j][i];
    }
  }
}

int main() {
  int mat1[M][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };

  int mat2[M][N] = {
    {17, 18, 19, 20},
    {21, 22, 23, 24},
    {25, 26, 27, 28},
    {29, 30, 31, 32}
  };

  int result[M][N];

  // Matrix addition
  matrix_add(mat1, 2, 3);
  matrix_add(mat1, 4, 5);
  matrix_add(mat1, 1, 6);

  // Matrix subtraction
  matrix_subtract(mat1, 2, 3);
  matrix_subtract(mat1, 4, 5);
  matrix_subtract(mat1, 1, 6);

  // Matrix multiplication
  matrix_multiply(mat1, 2, 3);
  matrix_multiply(mat1, 4, 5);
  matrix_multiply(mat1, 1, 6);

  // Matrix transpose
  matrix_transpose(mat1);

  // Matrix multiplication with a scalar
  matrix_multiply(mat1, 2, 3 * 4);

  // Matrix addition with a scalar
  matrix_add(mat1, 2, 3 * 4);

  // Print the result
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}