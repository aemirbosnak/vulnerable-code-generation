//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10  // Maximum size for the matrices

// Function Prototypes
void initializeMatrix(double matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);
void transposeMatrix(double matrix[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int rowsA, colsA, rowsB, colsB;
    double matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("=== Quantum Matrix Operations Interface ===\n");
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    initializeMatrix(matrixA, rowsA, colsA);
    printMatrix(matrixA, rowsA, colsA);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    initializeMatrix(matrixB, rowsB, colsB);
    printMatrix(matrixB, rowsB, colsB);
    
    // Matrix Addition
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of A + B:\n");
        printMatrix(result, rowsA, colsA);
    } else {
        printf("Cannot add matrices of different dimensions.\n");
    }

    // Matrix Subtraction
    if (rowsA == rowsB && colsA == colsB) {
        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of A - B:\n");
        printMatrix(result, rowsA, colsA);
    } else {
        printf("Cannot subtract matrices of different dimensions.\n");
    }

    // Matrix Multiplication
    if (colsA == rowsB) {
        multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, rowsB, colsB);
        printf("Result of A * B:\n");
        printMatrix(result, rowsA, colsB);
    } else {
        printf("Cannot multiply the matrices: columns of A must match rows of B.\n");
    }

    // Matrix Transpose
    double transposed[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrixA, transposed, rowsA, colsA);
    printf("Transpose of Matrix A:\n");
    printMatrix(transposed, colsA, rowsA);

    return 0;
}

void initializeMatrix(double matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Entering values for the matrix (%d x %d).\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Enter value for [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("=== Matrix (%dx%d) ===\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("=====================\n");
}

void addMatrices(double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(double matrix[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
}