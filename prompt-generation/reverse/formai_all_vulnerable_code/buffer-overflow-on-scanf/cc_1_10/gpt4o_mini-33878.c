//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0; // Set to 0 before accumulation
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    // Matrix A Input
    printf("Enter dimensions for matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    inputMatrix(A, rowsA, colsA);
    
    // Matrix B Input
    printf("Enter dimensions for matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrices A and B must be of same dimensions for addition/subtraction.\n");
        return 1;
    }
    inputMatrix(B, rowsB, colsB);

    // Matrix Addition
    addMatrices(A, B, C, rowsA, colsA);
    printf("\nAddition of matrices A and B:\n");
    printMatrix(C, rowsA, colsA);

    // Matrix Subtraction
    subtractMatrices(A, B, C, rowsA, colsA);
    printf("\nSubtraction of matrices A and B:\n");
    printMatrix(C, rowsA, colsA);

    // Matrix Multiplication
    if (colsA != rowsB) {
        printf("Number of columns of A must equal number of rows of B for multiplication.\n");
        return 1;
    }
    multiplyMatrices(A, B, C, rowsA, colsA, colsB);
    printf("\nMultiplication of matrices A and B:\n");
    printMatrix(C, rowsA, colsB);

    // Matrix Transposition
    transposeMatrix(A, transposed, rowsA, colsA);
    printf("\nTransposition of matrix A:\n");
    printMatrix(transposed, colsA, rowsA);

    return 0;
}