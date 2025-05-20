//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void addMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void subtractMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}

void multiplyMatrices(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
  if (cols1 != rows2) {
    printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
    return;
  }

  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols2; j++) {
      result[i][j] = 0;
      for (int k = 0; k < cols1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

int main() {
  int rows1, cols1, rows2, cols2;

  printf("Enter the number of rows and columns for the first matrix: ");
  scanf("%d %d", &rows1, &cols1);

  int matrix1[rows1][cols1];

  printf("Enter the elements of the first matrix:\n");
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }

  printf("Enter the number of rows and columns for the second matrix: ");
  scanf("%d %d", &rows2, &cols2);

  int matrix2[rows2][cols2];

  printf("Enter the elements of the second matrix:\n");
  for (int i = 0; i < rows2; i++) {
    for (int j = 0; j < cols2; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }

  int result[rows1][cols2];

  addMatrices(rows1, cols1, matrix1, matrix2, result);

  printf("The sum of the two matrices is:\n");
  printMatrix(rows1, cols2, result);

  subtractMatrices(rows1, cols1, matrix1, matrix2, result);

  printf("The difference of the two matrices is:\n");
  printMatrix(rows1, cols2, result);

  multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

  printf("The product of the two matrices is:\n");
  printMatrix(rows1, cols2, result);

  return 0;
}