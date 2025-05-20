//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

void printMatrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int **createMatrix(int rows, int cols) {
  int **matrix = (int **)malloc(sizeof(int *) * rows);
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(sizeof(int) * cols);
  }
  return matrix;
}

void freeMatrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int **transposeMatrix(int **matrix, int rows, int cols) {
  int **transposedMatrix = createMatrix(cols, rows);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      transposedMatrix[j][i] = matrix[i][j];
    }
  }
  return transposedMatrix;
}

int **multiplyMatrices(int **matrixA, int rowsA, int colsA, int **matrixB, int rowsB,
                       int colsB) {
  if (colsA != rowsB) {
    printf("Matrices cannot be multiplied\n");
    return NULL;
  }
  int **resultMatrix = createMatrix(rowsA, colsB);
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsB; j++) {
      int sum = 0;
      for (int k = 0; k < colsA; k++) {
        sum += matrixA[i][k] * matrixB[k][j];
      }
      resultMatrix[i][j] = sum;
    }
  }
  return resultMatrix;
}

int main() {
  int rowsA, colsA, rowsB, colsB;
  printf("Enter the number of rows and columns of matrix A: ");
  scanf("%d %d", &rowsA, &colsA);
  int **matrixA = createMatrix(rowsA, colsA);
  printf("Enter the elements of matrix A:\n");
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      scanf("%d", &matrixA[i][j]);
    }
  }
  printf("Enter the number of rows and columns of matrix B: ");
  scanf("%d %d", &rowsB, &colsB);
  int **matrixB = createMatrix(rowsB, colsB);
  printf("Enter the elements of matrix B:\n");
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      scanf("%d", &matrixB[i][j]);
    }
  }
  printf("Matrix A:\n");
  printMatrix(matrixA, rowsA, colsA);
  printf("Matrix B:\n");
  printMatrix(matrixB, rowsB, colsB);
  int **transposedMatrixA = transposeMatrix(matrixA, rowsA, colsA);
  printf("Transposed Matrix A:\n");
  printMatrix(transposedMatrixA, colsA, rowsA);
  int **resultMatrix = multiplyMatrices(matrixA, rowsA, colsA, matrixB, rowsB, colsB);
  if (resultMatrix != NULL) {
    printf("Result Matrix:\n");
    printMatrix(resultMatrix, rowsA, colsB);
  }
  freeMatrix(matrixA, rowsA);
  freeMatrix(matrixB, rowsB);
  freeMatrix(transposedMatrixA, colsA);
  freeMatrix(resultMatrix, rowsA);
  return 0;
}