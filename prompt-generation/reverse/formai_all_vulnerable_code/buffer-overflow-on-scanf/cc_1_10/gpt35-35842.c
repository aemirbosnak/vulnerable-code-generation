//FormAI DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int m, int n, int matrix[m][n]) {
  printf("Enter the matrix elements row-wise(comma-separated):\n");
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

void printMatrix(int m, int n, int matrix[m][n]) {
  printf("The matrix is:\n");
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void addMatrix(int m, int n, int A[m][n], int B[m][n], int result[m][n]) {
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      result[i][j] = A[i][j] + B[i][j];
    }
  }
}

void multiplyMatrix(int m1, int n1, int A[m1][n1], int m2, int n2, int B[m2][n2], int result[m1][n2]) {
  if(n1 != m2) {
    printf("Matrix multiplication is not possible with given matrices.");
    return;
  }

  for(int i = 0; i < m1; i++) {
    for(int j = 0; j < n2; j++) {
      result[i][j] = 0;
      for(int k = 0; k < n1; k++) {
        result[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

int main() {
  int m, n;
  printf("Enter the number of rows and columns of matrix A: ");
  scanf("%d %d", &m, &n);

  int A[m][n], B[m][n], sum[m][n], product[m][n];

  inputMatrix(m, n, A);
  inputMatrix(m, n, B);

  printf("\n");

  printMatrix(m, n, A);
  printf("\n");
  printMatrix(m, n, B);
  printf("\n");

  addMatrix(m, n, A, B, sum);
  printf("The sum of the matrices is:\n");
  printMatrix(m, n, sum);
  printf("\n");

  int p, q;
  printf("Enter the number of rows and columns of matrix B: ");
  scanf("%d %d", &p, &q);

  int C[p][q];

  inputMatrix(p, q, C);
  printf("\n");
  printMatrix(p, q, C);

  multiplyMatrix(m, n, A, p, q, C, product);
  printf("\nThe product of the matrices is:\n");
  printMatrix(m, q, product);

  return 0;
}