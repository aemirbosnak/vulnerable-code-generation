//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <math.h>

  #define N 1000
  #define M 1000

  void init_matrix(double** matrix, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        matrix[i][j] = (double)rand() / RAND_MAX;
      }
    }
  }

  void print_matrix(double** matrix, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        printf("%.2lf ", matrix[i][j]);
      }
      printf("\n");
    }
  }

  void add_matrices(double** matrix1, double** matrix2, double** matrix3, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
      }
    }
  }

  void multiply_matrices(double** matrix1, double** matrix2, double** matrix3, int n, int m) {
    int i, j, k;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        matrix3[i][j] = 0;
        for (k = 0; k < m; k++) {
          matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
        }
      }
    }
  }

  int main() {
    srand(time(NULL));

    double** matrix1 = malloc(N * sizeof(double*));
    double** matrix2 = malloc(N * sizeof(double*));
    double** matrix3 = malloc(N * sizeof(double*));
    int i, j;
    for (i = 0; i < N; i++) {
      matrix1[i] = malloc(M * sizeof(double));
      matrix2[i] = malloc(M * sizeof(double));
      matrix3[i] = malloc(M * sizeof(double));
    }

    init_matrix(matrix1, N, M);
    init_matrix(matrix2, N, M);

    print_matrix(matrix1, N, M);
    print_matrix(matrix2, N, M);

    add_matrices(matrix1, matrix2, matrix3, N, M);
    print_matrix(matrix3, N, M);

    multiply_matrices(matrix1, matrix2, matrix3, N, M);
    print_matrix(matrix3, N, M);

    for (i = 0; i < N; i++) {
      free(matrix1[i]);
      free(matrix2[i]);
      free(matrix3[i]);
    }
    free(matrix1);
    free(matrix2);
    free(matrix3);

    return 0;
  }