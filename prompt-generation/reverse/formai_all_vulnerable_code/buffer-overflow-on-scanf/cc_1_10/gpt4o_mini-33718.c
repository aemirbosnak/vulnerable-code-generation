//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int matrix[][10], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][10], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows1, cols1, rows2, cols2;
    
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    
    inputMatrix(matrix1, rows1, cols1);
    displayMatrix(matrix1, rows1, cols1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices must be of same dimension for addition and subtraction.\n");
        return 1;
    }

    inputMatrix(matrix2, rows2, cols2);
    displayMatrix(matrix2, rows2, cols2);

    // Addition
    addMatrices(matrix1, matrix2, result, rows1, cols1);
    printf("Sum of the matrices:\n");
    displayMatrix(result, rows1, cols1);
    
    // Subtraction
    subtractMatrices(matrix1, matrix2, result, rows1, cols1);
    printf("Difference of the matrices:\n");
    displayMatrix(result, rows1, cols1);

    // Multiplication (only if cols1 == rows2)
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible, columns of first must match rows of second.\n");
    } else {
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
        printf("Product of the matrices:\n");
        displayMatrix(result, rows1, cols2);
    }

    // Transpose of first matrix
    transposeMatrix(matrix1, result, rows1, cols1);
    printf("Transpose of the first matrix:\n");
    displayMatrix(result, cols1, rows1);
    
    // Transpose of second matrix
    transposeMatrix(matrix2, result, rows2, cols2);
    printf("Transpose of the second matrix:\n");
    displayMatrix(result, cols2, rows2);

    return 0;
}