//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include<stdio.h>

int main() {
  int matrixA[3][3], matrixB[3][3];
  int result[3][3];

  // input matrix A
  printf("Enter values for Matrix A:\n");
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      scanf("%d",&matrixA[i][j]);
    }
  }

  // input matrix B
  printf("Enter values for Matrix B:\n");
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      scanf("%d",&matrixB[i][j]);
    }
  }

  // addition of matrix A and matrix B
  printf("\n\nAddition of Matrix A and Matrix B:\n");
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      result[i][j] = matrixA[i][j] + matrixB[i][j];
      printf("%d ",result[i][j]);
    }
    printf("\n");
  }

  // subtraction of matrix A and matrix B
  printf("\n\nSubtraction of Matrix A and Matrix B:\n");
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      result[i][j] = matrixA[i][j] - matrixB[i][j];
      printf("%d ",result[i][j]);
    }
    printf("\n");
  }

  // multiplication of matrix A and matrix B
  printf("\n\nMultiplication of Matrix A and Matrix B:\n");
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      result[i][j] = 0;
      for(int k=0;k<3;k++) {
        result[i][j] += matrixA[i][k] * matrixB[k][j];
      }
      printf("%d ",result[i][j]);
    }
    printf("\n");
  }

  // transpose of matrix A
  printf("\n\nTranspose of Matrix A:\n");
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      result[i][j] = matrixA[j][i];
      printf("%d ",result[i][j]);
    }
    printf("\n");
  }

  return 0;
}