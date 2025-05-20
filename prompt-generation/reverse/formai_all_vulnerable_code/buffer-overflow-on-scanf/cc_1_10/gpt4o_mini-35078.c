//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int rows2, int cols2);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;

    // Input dimensions and matrices
    printf("Enter dimensions of first matrix (rows and columns): ");
    scanf("%d %d", &rows1, &cols1);
    printf("Input first matrix (%d x %d):\n", rows1, cols1);
    inputMatrix(matrix1, rows1, cols1);

    printf("Enter dimensions of second matrix (rows and columns): ");
    scanf("%d %d", &rows2, &cols2);
    printf("Input second matrix (%d x %d):\n", rows2, cols2);
    inputMatrix(matrix2, rows2, cols2);

    // Addition of matrices
    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(matrix1, matrix2, result, rows1, cols1);
        printf("Sum of the two matrices:\n");
        printMatrix(result, rows1, cols1);
    } else {
        printf("Matrices cannot be added due to different dimensions!\n");
    }

    // Multiplication of matrices
    if (cols1 == rows2) {
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
        printf("Product of the two matrices:\n");
        printMatrix(result, rows1, cols2);
    } else {
        printf("Matrices cannot be multiplied due to incompatible dimensions!\n");
    }

    // Transpose of the first matrix
    transposeMatrix(matrix1, result, rows1, cols1);
    printf("Transpose of the first matrix:\n");
    printMatrix(result, cols1, rows1);
    
    return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize result[i][j]
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}