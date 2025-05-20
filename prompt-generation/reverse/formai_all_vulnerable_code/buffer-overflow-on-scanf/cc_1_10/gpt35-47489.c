//FormAI DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>

// Function to print the matrix
void printMatrix(int matrix[][100], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
}

// Function to add two matrices
void addMatrix(int matrix1[][100], int matrix2[][100], int result[][100], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

//Function to multiply two matrices
void multiplyMatrix(int matrix1[][100], int matrix2[][100], int result[][100], int row1, int col1, int col2) {
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col2; j++) {
      result[i][j] = 0;
      for (int k = 0; k < col1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

int main() {
  int matrix1[100][100], matrix2[100][100], result[100][100], row1, col1, row2, col2;
  
  printf("Enter the number of rows and columns of the first matrix: \n");
  scanf("%d %d", &row1, &col1);
  
  printf("Enter the elements of first matrix.\n");
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col1; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }
  
  printf("Enter the number of rows and columns of the second matrix: \n");
  scanf("%d %d", &row2, &col2);
  
  printf("Enter the elements of second matrix.\n");
  for (int i = 0; i < row2; i++) {
    for (int j = 0; j < col2; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }
  
  // Add matrices
  if (row1 == row2 && col1 == col2) {
    addMatrix(matrix1, matrix2, result, row1, col1);
    printf("\nThe Sum of the two matrices is : \n");
    printMatrix(result, row1, col1);
  } else {
    printf("\nCannot add matrices as their rows and columns are different!\n");
  }
  
  // Multiply matrices
  if (col1 == row2) {
    multiplyMatrix(matrix1, matrix2, result, row1, col1, col2);
    printf("\nThe Product of the two matrices is : \n");
    printMatrix(result, row1, col2);
  } else {
    printf("\nCannot multiply matrices as their columns and rows are different!\n");
  }
  
  return 0;
}