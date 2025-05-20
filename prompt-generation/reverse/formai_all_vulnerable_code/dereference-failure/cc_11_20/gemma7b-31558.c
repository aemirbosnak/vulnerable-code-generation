//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Define the Matrix A
  int a_rows = 3;
  int a_cols = 4;
  double **a = (double**)malloc(a_rows * sizeof(double*));
  for (int i = 0; i < a_rows; i++) {
    a[i] = (double*)malloc(a_cols * sizeof(double));
  }

  // Initialize the Matrix A
  a[0][0] = 1.2;
  a[0][1] = 2.4;
  a[0][2] = 3.6;
  a[0][3] = 4.8;
  a[1][0] = 5.0;
  a[1][1] = 6.2;
  a[1][2] = 7.4;
  a[1][3] = 8.6;
  a[2][0] = 9.8;
  a[2][1] = 11.0;
  a[2][2] = 12.2;
  a[2][3] = 13.4;

  // Define the Matrix B
  int b_rows = 2;
  int b_cols = 3;
  double **b = (double**)malloc(b_rows * sizeof(double*));
  for (int i = 0; i < b_rows; i++) {
    b[i] = (double*)malloc(b_cols * sizeof(double));
  }

  // Initialize the Matrix B
  b[0][0] = 1.0;
  b[0][1] = 2.0;
  b[0][2] = 3.0;
  b[1][0] = 4.0;
  b[1][1] = 5.0;
  b[1][2] = 6.0;

  // Perform Matrix Multiplication
  int c_rows = a_rows;
  int c_cols = b_cols;
  double **c = (double**)malloc(c_rows * sizeof(double*));
  for (int i = 0; i < c_rows; i++) {
    c[i] = (double*)malloc(c_cols * sizeof(double));
  }

  for (int i = 0; i < c_rows; i++) {
    for (int j = 0; j < c_cols; j++) {
      c[i][j] = 0.0;
      for (int k = 0; k < a_cols; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Print the Matrix C
  for (int i = 0; i < c_rows; i++) {
    for (int j = 0; j < c_cols; j++) {
      printf("%f ", c[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < a_rows; i++) {
    free(a[i]);
  }
  free(a);

  for (int i = 0; i < b_rows; i++) {
    free(b[i]);
  }
  free(b);

  for (int i = 0; i < c_rows; i++) {
    free(c[i]);
  }
  free(c);

  return 0;
}