//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
    int rows, cols;
    
    printf("Enter number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Input first matrix
    inputMatrix(matrix1, rows, cols);
    // Input second matrix
    inputMatrix(matrix2, rows, cols);

    // Addition of matrices
    addMatrices(matrix1, matrix2, result, rows, cols);
    printf("\nResult of Addition:\n");
    displayMatrix(result, rows, cols);
    
    // Subtraction of matrices
    subtractMatrices(matrix1, matrix2, result, rows, cols);
    printf("\nResult of Subtraction:\n");
    displayMatrix(result, rows, cols);
    
    // Multiplication of matrices
    printf("Enter number of columns for second matrix (for multiplication): ");
    int cols2;
    scanf("%d", &cols2);
    
    int matrix3[MAX][MAX];
    inputMatrix(matrix3, cols, cols2);
    multiplyMatrices(matrix1, matrix3, result, rows, cols, cols2);
    printf("\nResult of Multiplication:\n");
    displayMatrix(result, rows, cols2);
    
    // Transpose of the first matrix
    int transpose[MAX][MAX];
    transposeMatrix(matrix1, transpose, rows, cols);
    printf("\nTranspose of the First Matrix:\n");
    displayMatrix(transpose, cols, rows);
    
    return 0;
}