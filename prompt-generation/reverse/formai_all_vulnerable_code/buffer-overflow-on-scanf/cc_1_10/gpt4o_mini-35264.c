//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  // Define a constant for maximum matrix size

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    // Input dimensions for matrix A
    printf("Enter number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    
    // Input matrix A
    printf("Input matrix A (%dx%d):\n", rowsA, colsA);
    inputMatrix(matrixA, rowsA, colsA);

    // Input dimensions for matrix B
    printf("Enter number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    
    // Input matrix B
    printf("Input matrix B (%dx%d):\n", rowsB, colsB);
    inputMatrix(matrixB, rowsB, colsB);

    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrices must have the same dimensions for addition and subtraction.\n");
    } else {
        // Add matrices
        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of A + B:\n");
        displayMatrix(result, rowsA, colsA);
        
        // Subtract matrices
        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of A - B:\n");
        displayMatrix(result, rowsA, colsA);
    }

    if (colsA != rowsB) {
        printf("Matrices cannot be multiplied as the column of A does not equal the row of B.\n");
    } else {
        // Multiply matrices
        multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
        printf("Result of A * B:\n");
        displayMatrix(result, rowsA, colsB);
    }

    // Transpose matrix A
    transposeMatrix(matrixA, result, rowsA, colsA);
    printf("Transpose of matrix A:\n");
    displayMatrix(result, colsA, rowsA);

    // Transpose matrix B
    transposeMatrix(matrixB, result, rowsB, colsB);
    printf("Transpose of matrix B:\n");
    displayMatrix(result, colsB, rowsB);

    return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
}