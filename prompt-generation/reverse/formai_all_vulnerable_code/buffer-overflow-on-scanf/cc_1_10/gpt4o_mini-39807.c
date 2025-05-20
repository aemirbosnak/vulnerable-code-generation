//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function Declarations
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int aRows, int aCols, int bCols);

int main() {
    int rows, cols;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // Input matrix dimensions
    printf("Enter the number of rows and columns for the matrices (max %d): ", MAX_SIZE);
    scanf("%d %d", &rows, &cols);

    if (rows > MAX_SIZE || cols > MAX_SIZE || rows <= 0 || cols <= 0) {
        printf("Invalid matrix size. Please restart and enter sizes within bounds.\n");
        return 1;
    }

    printf("Input Matrix A:\n");
    inputMatrix(matrixA, rows, cols);

    printf("Input Matrix B:\n");
    inputMatrix(matrixB, rows, cols);

    printf("\nMatrix A:\n");
    printMatrix(matrixA, rows, cols);

    printf("\nMatrix B:\n");
    printMatrix(matrixB, rows, cols);

    addMatrices(matrixA, matrixB, result, rows, cols);
    printf("\nResult of Matrix A + Matrix B:\n");
    printMatrix(result, rows, cols);

    subtractMatrices(matrixA, matrixB, result, rows, cols);
    printf("\nResult of Matrix A - Matrix B:\n");
    printMatrix(result, rows, cols);

    // Matrix multiplication should be based on compatible dimensions
    int colsB;
    printf("Enter number of columns for matrix B for multiplication (max %d): ", MAX_SIZE);
    scanf("%d", &colsB);

    if (cols != rows || colsB > MAX_SIZE || colsB <= 0) {
        printf("Matrix multiplication is not possible with given dimensions.\n");
        return 1;
    }

    int resultMult[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(matrixA, matrixB, resultMult, rows, cols, colsB);
    printf("\nResult of Matrix A x Matrix B:\n");
    printMatrix(resultMult, rows, colsB);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int aRows, int aCols, int bCols) {
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            result[i][j] = 0; // Initialize to zero
            for (int k = 0; k < aCols; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}