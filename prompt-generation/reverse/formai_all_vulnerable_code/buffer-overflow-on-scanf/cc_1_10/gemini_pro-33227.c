//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to read a matrix from the user
void readMatrix(int matrix[][10], int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("Enter element [%d, %d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }
}

// Function to print a matrix
void printMatrix(int matrix[][10], int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
void addMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

// Function to subtract two matrices
void subtractMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int rows1, int columns1, int rows2, int columns2) {
  if (columns1 != rows2) {
    printf("Matrices cannot be multiplied\n");
    return;
  }

  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < columns2; j++) {
      result[i][j] = 0;
      for (int k = 0; k < columns1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

// Function to find the determinant of a matrix
int determinant(int matrix[][10], int n) {
  int det = 0;
  int submatrix[10][10];

  if (n == 2) {
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
  } else {
    for (int i = 0; i < n; i++) {
      int subi = 0;
      for (int j = 1; j < n; j++) {
        int subj = 0;
        for (int k = 0; k < n; k++) {
          if (k == i) {
            continue;
          }
          submatrix[subi][subj] = matrix[j][k];
          subj++;
        }
        subi++;
      }
      det += pow(-1, i) * matrix[0][i] * determinant(submatrix, n - 1);
    }
  }

  return det;
}

// Function to find the inverse of a matrix
void inverse(int matrix[][10], int inverse[][10], int n) {
  int det = determinant(matrix, n);

  if (det == 0) {
    printf("Matrix is not invertible\n");
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int submatrix[10][10];

      int subi = 0;
      for (int k = 0; k < n; k++) {
        if (k == i) {
          continue;
        }
        int subj = 0;
        for (int l = 0; l < n; l++) {
          if (l == j) {
            continue;
          }
          submatrix[subi][subj] = matrix[k][l];
          subj++;
        }
        subi++;
      }

      inverse[i][j] = pow(-1, i + j) * determinant(submatrix, n - 1) / det;
    }
  }
}

// Function to find the transpose of a matrix
void transpose(int matrix[][10], int transpose[][10], int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      transpose[i][j] = matrix[j][i];
    }
  }
}

// Main function
int main() {
  int matrix1[10][10], matrix2[10][10], result[10][10];
  int rows1, columns1, rows2, columns2;

  printf("Enter the number of rows and columns of the first matrix: ");
  scanf("%d %d", &rows1, &columns1);

  printf("Enter the elements of the first matrix:\n");
  readMatrix(matrix1, rows1, columns1);

  printf("Enter the number of rows and columns of the second matrix: ");
  scanf("%d %d", &rows2, &columns2);

  printf("Enter the elements of the second matrix:\n");
  readMatrix(matrix2, rows2, columns2);

  // Add the two matrices
  addMatrices(matrix1, matrix2, result, rows1, columns1);

  // Print the addition result
  printf("The addition result is:\n");
  printMatrix(result, rows1, columns1);

  // Subtract the two matrices
  subtractMatrices(matrix1, matrix2, result, rows1, columns1);

  // Print the subtraction result
  printf("The subtraction result is:\n");
  printMatrix(result, rows1, columns1);

  // Multiply the two matrices
  multiplyMatrices(matrix1, matrix2, result, rows1, columns1, rows2, columns2);

  // Print the multiplication result
  printf("The multiplication result is:\n");
  printMatrix(result, rows1, columns2);

  // Find the determinant of the first matrix
  int det = determinant(matrix1, rows1);

  // Print the determinant
  printf("The determinant of the first matrix is: %d\n", det);

  // Find the inverse of the first matrix
  if (rows1 == columns1) {
    inverse(matrix1, result, rows1);

    // Print the inverse
    printf("The inverse of the first matrix is:\n");
    printMatrix(result, rows1, columns1);
  } else {
    printf("Matrix is not square\n");
  }

  // Find the transpose of the first matrix
  transpose(matrix1, result, rows1, columns1);

  // Print the transpose
  printf("The transpose of the first matrix is:\n");
  printMatrix(result, rows1, columns1);

  return 0;
}