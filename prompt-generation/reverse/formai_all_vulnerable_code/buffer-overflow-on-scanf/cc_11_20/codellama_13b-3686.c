//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
  #include <stdlib.h>
  #include <math.h>

  int main() {
      int n, m, i, j, k;
      float a[100][100], b[100][100], c[100][100];

      printf("Enter the order of the matrix: ");
      scanf("%d%d", &n, &m);

      printf("Enter the elements of matrix A:\n");
      for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
              scanf("%f", &a[i][j]);
          }
      }

      printf("Enter the elements of matrix B:\n");
      for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
              scanf("%f", &b[i][j]);
          }
      }

      // Matrix addition
      for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
              c[i][j] = a[i][j] + b[i][j];
          }
      }

      printf("Matrix addition:\n");
      for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
              printf("%.2f ", c[i][j]);
          }
          printf("\n");
      }

      // Matrix multiplication
      for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
              c[i][j] = 0;
              for (k = 0; k < m; k++) {
                  c[i][j] += a[i][k] * b[k][j];
              }
          }
      }

      printf("Matrix multiplication:\n");
      for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
              printf("%.2f ", c[i][j]);
          }
          printf("\n");
      }

      return 0;
  }