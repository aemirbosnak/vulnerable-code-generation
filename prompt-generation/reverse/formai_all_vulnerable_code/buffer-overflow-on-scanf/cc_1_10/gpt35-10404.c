//FormAI DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>

void matrix_print(int n, int m, int matrix[n][m]) {
  int i, j;
  printf("\n");
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d\t", matrix[i][j]);
    }
    
    printf("\n");
  }
}

void matrix_add(int n, int m, int matrix1[n][m], int matrix2[n][m], int result[n][m]) {
  int i, j;
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void matrix_subtract(int n, int m, int matrix1[n][m], int matrix2[n][m], int result[n][m]) {
  int i, j;
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}

void matrix_multiply(int n1, int m1, int matrix1[n1][m1], int n2, int m2, int matrix2[n2][m2], int result[n1][m2]) {
  int i, j, k, sum;
  
  for (i = 0; i < n1; i++) {
    for (j = 0; j < m2; j++) {
      sum = 0;
      
      for (k = 0; k < n2; k++) {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      
      result[i][j] = sum;
    }
  }
}

int matrix_determinant(int n, int m, int matrix[n][m]) {
  int i, j, k, sign = 1, det = 0, size = n;
  int submatrix[size][size];
  
  if (n != m) {
    printf("Error: Matrix is not square.\n");
    return -1;
  }
  
  if (n == 1) {
    return matrix[0][0];
  } else if (n == 2) {
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
  }
  
  for (i = 0; i < n; i++) {
    k = 0;
    for (j = 1; j < n; j++) {
      int l;
      for (l = 0; l < n; l++) {
        if (l != i) {
          submatrix[k][l] = matrix[j][l];
        }
      }
      
      k++;
    }
    
    det += sign * matrix[0][i] * matrix_determinant(n - 1, n - 1, submatrix);
    sign = -sign;
  }
  
  return det;
}

int main() {
  int n = 3;
  int m = 3;
  int matrix1[n][m], matrix2[n][m], result[n][m];
  int i, j;
  
  printf("Enter values for matrix1:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }
  
  printf("Enter values for matrix2:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }
  
  printf("Matrix 1:\n");
  matrix_print(n, m, matrix1);
  
  printf("Matrix 2:\n");
  matrix_print(n, m, matrix2);
  
  printf("Matrix 1 + Matrix 2:\n");
  matrix_add(n, m, matrix1, matrix2, result);
  matrix_print(n, m, result);
  
  printf("Matrix 1 - Matrix 2:\n");
  matrix_subtract(n, m, matrix1, matrix2, result);
  matrix_print(n, m, result);
  
  printf("Matrix 1 * Matrix 2:\n");
  matrix_multiply(n, m, matrix1, m, n, matrix2, result);
  matrix_print(n, m, result);
  
  printf("Determinant of Matrix 1: %d\n", matrix_determinant(n, m, matrix1));
  
  return 0;
}