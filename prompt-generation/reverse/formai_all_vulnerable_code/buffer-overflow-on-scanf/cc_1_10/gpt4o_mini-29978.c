//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initializeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Random values between 0-9
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize result element
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE], product[MAX_SIZE][MAX_SIZE];

    printf("Enter rows and columns for first matrix (A): ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("Enter rows and columns for second matrix (B): ");
    scanf("%d %d", &rowsB, &colsB);
    
    // Validate dimensions for addition
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrices must have the same dimensions for addition.\n");
        return 1;
    }
    
    // Validate dimensions for multiplication
    if (colsA != rowsB) {
        printf("Number of columns in A must equal number of rows in B for multiplication.\n");
        return 1;
    }

    // Initialize matrices A and B
    initializeMatrix(matrixA, rowsA, colsA);
    initializeMatrix(matrixB, rowsB, colsB);

    printf("\nMatrix A:\n");
    displayMatrix(matrixA, rowsA, colsA);
    
    printf("\nMatrix B:\n");
    displayMatrix(matrixB, rowsB, colsB);

    // Addition of matrices
    addMatrices(matrixA, matrixB, sum, rowsA, colsA);
    printf("\nSum of A and B:\n");
    displayMatrix(sum, rowsA, colsA);

    // Multiplication of matrices
    multiplyMatrices(matrixA, matrixB, product, rowsA, colsA, colsB);
    printf("\nProduct of A and B:\n");
    displayMatrix(product, rowsA, colsB);

    return 0;
}