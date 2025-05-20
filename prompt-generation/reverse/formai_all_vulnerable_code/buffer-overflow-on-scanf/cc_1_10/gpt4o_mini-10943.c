//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    if (rows > MAX_SIZE || cols > MAX_SIZE) {
        printf("Size exceeds maximum limit!\n");
        return;
    }
    srand(time(NULL)); // Seeding for randomness
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // Random values from 0 to 99
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initializing result cell
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j]; // Matrix multiplication
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j]; // Transposing the matrix
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE], D[MAX_SIZE][MAX_SIZE];
    
    int rowsA, colsA, rowsB, colsB;

    printf("Enter dimensions of Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("Enter dimensions of Matrix B (should have same dimensions as A for addition): ");
    scanf("%d %d", &rowsB, &colsB);
    
    // Sanity check for matrix dimensions
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrix addition requires same dimensions!\n");
        return 1; // Error
    }

    fillMatrix(A, rowsA, colsA);
    fillMatrix(B, rowsB, colsB);

    printMatrix(A, rowsA, colsA);
    printMatrix(B, rowsB, colsB);
    
    addMatrices(A, B, C, rowsA, colsA);
    printMatrix(C, rowsA, colsA);
    
    printf("Now, let's multiply Matrix A with a valid Matrix B that has matching columns as A's rows! Provide dimensions:\n");
    
    printf("Enter dimensions of Matrix B (for multiplication with A): ");
    scanf("%d %d", &rowsB, &colsB);
    
    if (colsA != rowsB) {
        printf("Matrix multiplication requires that the number of columns in A matches the number of rows in B!\n");
        return 1; // Error
    }

    fillMatrix(B, rowsB, colsB); // Reuse B because it has been defined

    printMatrix(B, rowsB, colsB);
    
    multiplyMatrices(A, B, D, rowsA, colsA, colsB);
    printMatrix(D, rowsA, colsB);
    
    printf("Transposing Matrix A...\n");
    int transpose[MAX_SIZE][MAX_SIZE];
    transposeMatrix(A, transpose, rowsA, colsA);
    printMatrix(transpose, colsA, rowsA);

    printf("All operations completed, matrix manipulations concluded with precision!\n");
    return 0; // Success
}