//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main() {
  int n, i, j, k;
  double **A, **L, **U;
  printf("Enter the order of the matrix: ");
  scanf("%d", &n);
  A = (double **)malloc(n * sizeof(double *));
  for (i = 0; i < n; i++) {
    A[i] = (double *)malloc(n * sizeof(double));
  }
  printf("Enter the elements of the matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%lf", &A[i][j]);
    }
  }
  L = (double **)malloc(n * sizeof(double *));
  for (i = 0; i < n; i++) {
    L[i] = (double *)malloc(n * sizeof(double));
  }
  U = (double **)malloc(n * sizeof(double *));
  for (i = 0; i < n; i++) {
    U[i] = (double *)malloc(n * sizeof(double));
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        L[i][j] = 1;
      } else {
        L[i][j] = 0;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i <= j) {
        U[i][j] = A[i][j];
      } else {
        U[i][j] = 0;
      }
    }
  }
  for (k = 0; k < n; k++) {
    for (i = k + 1; i < n; i++) {
      L[i][k] = A[i][k] / U[k][k];
      for (j = k; j < n; j++) {
        U[i][j] = A[i][j] - L[i][k] * U[k][j];
      }
    }
  }
  printf("The LU decomposition of the matrix is:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%lf\t", L[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%lf\t", U[i][j]);
    }
    printf("\n");
  }
  return 0;
}