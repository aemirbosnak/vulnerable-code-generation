//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3

void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    printf("\nMatrix:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int matrixA[MATRIX_SIZE][MATRIX_SIZE], int matrixB[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[MATRIX_SIZE][MATRIX_SIZE], int matrixB[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i][j] = 0; // Initialize the result matrix
            for (int k = 0; k < MATRIX_SIZE; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void fillMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    printf("Fill in the matrix with numbers (%d x %d):\n", MATRIX_SIZE, MATRIX_SIZE);
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int matrixA[MATRIX_SIZE][MATRIX_SIZE];
    int matrixB[MATRIX_SIZE][MATRIX_SIZE];
    int resultAdd[MATRIX_SIZE][MATRIX_SIZE];
    int resultMultiply[MATRIX_SIZE][MATRIX_SIZE];
    int resultTranspose[MATRIX_SIZE][MATRIX_SIZE];

    // Fill the matrices using user input
    fillMatrix(matrixA);
    fillMatrix(matrixB);

    // Print both matrices
    printMatrix(matrixA);
    printMatrix(matrixB);

    // Perform and print addition of matrices
    addMatrices(matrixA, matrixB, resultAdd);
    printf("Addition of Matrices:\n");
    printMatrix(resultAdd);

    // Perform and print multiplication of matrices
    multiplyMatrices(matrixA, matrixB, resultMultiply);
    printf("Multiplication of Matrices:\n");
    printMatrix(resultMultiply);

    // Perform and print transpose of matrix A
    transposeMatrix(matrixA, resultTranspose);
    printf("Transpose of Matrix A:\n");
    printMatrix(resultTranspose);

    // Perform and print transpose of matrix B
    transposeMatrix(matrixB, resultTranspose);
    printf("Transpose of Matrix B:\n");
    printMatrix(resultTranspose);

    return 0;
}