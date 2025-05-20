//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: unmistakable
// Matrix operations example program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 3 // rows
#define N 4 // cols

// Function to display a matrix
void display_matrix(int m[M][N]) {
  int i, j;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
void add_matrices(int a[M][N], int b[M][N], int c[M][N]) {
  int i, j;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
}

// Function to multiply two matrices
void multiply_matrices(int a[M][N], int b[M][N], int c[M][N]) {
  int i, j, k;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      c[i][j] = 0;
      for (k = 0; k < N; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

// Function to transpose a matrix
void transpose_matrix(int a[M][N], int b[N][M]) {
  int i, j;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      b[j][i] = a[i][j];
    }
  }
}

// Function to inverse a matrix
void inverse_matrix(int a[M][N], int b[M][N]) {
  int i, j, k, det;
  det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
        a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
        a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
  if (det == 0) {
    printf("Matrix is not invertible.\n");
    return;
  }
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      b[i][j] = a[i][j] / det;
    }
  }
}

// Function to multiply a matrix by a scalar
void scalar_multiply(int a[M][N], int b, int c[M][N]) {
  int i, j;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      c[i][j] = a[i][j] * b;
    }
  }
}

int main() {
  int a[M][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int b[M][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int c[M][N] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int d[M][N] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int e[M][N] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int f[M][N] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int g[M][N] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int h[M][N] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int i = 2;
  int j = 3;
  add_matrices(a, b, c);
  display_matrix(c);
  multiply_matrices(a, b, d);
  display_matrix(d);
  transpose_matrix(a, e);
  display_matrix(e);
  inverse_matrix(a, f);
  display_matrix(f);
  scalar_multiply(a, i, g);
  display_matrix(g);
  return 0;
}