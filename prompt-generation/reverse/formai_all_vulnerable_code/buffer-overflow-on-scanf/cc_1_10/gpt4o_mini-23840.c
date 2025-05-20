//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    // Input for first matrix
    printf("Enter number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Input Matrix A:\n");
    inputMatrix(matrixA, rowsA, colsA);
    
    // Input for second matrix
    printf("Enter number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Input Matrix B:\n");
    inputMatrix(matrixB, rowsB, colsB);

    // Check matrix operations
    if (rowsA == rowsB && colsA == colsB) {
        printf("\nMatrix Addition:\n");
        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        displayMatrix(result, rowsA, colsA);

        printf("\nMatrix Subtraction:\n");
        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
        displayMatrix(result, rowsA, colsA);
    } else {
        printf("Matrix Addition and Subtraction not possible due to dimension mismatch.\n");
    }

    if (colsA == rowsB) {
        printf("\nMatrix Multiplication:\n");
        multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, rowsB, colsB);
        displayMatrix(result, rowsA, colsB);
    } else {
        printf("Matrix Multiplication not possible due to dimension mismatch.\n");
    }

    // Transpose Matrix A
    printf("\nTransposing Matrix A:\n");
    transposeMatrix(matrixA, transposed, rowsA, colsA);
    displayMatrix(transposed, colsA, rowsA);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}