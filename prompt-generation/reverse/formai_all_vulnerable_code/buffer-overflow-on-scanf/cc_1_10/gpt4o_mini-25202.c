//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

// Function to initialize a matrix with random values
void initializeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int aRows, int aCols, int bCols) {
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < aCols; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(0));

    int rowsA, colsA, rowsB, colsB;
    printf("Enter rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("Enter rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    
    if (colsA != rowsB) {
        printf("Matrix A columns must equal Matrix B rows for multiplication.\n");
        return 1;
    }

    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];

    initializeMatrix(A, rowsA, colsA);
    printf("\nMatrix A:\n");
    printMatrix(A, rowsA, colsA);

    initializeMatrix(B, rowsB, colsB);
    printf("\nMatrix B:\n");
    printMatrix(B, rowsB, colsB);

    addMatrices(A, B, result, rowsA, colsA);
    printf("\nMatrix A + Matrix B:\n");
    printMatrix(result, rowsA, colsA);

    multiplyMatrices(A, B, result, rowsA, colsA, colsB);
    printf("\nMatrix A * Matrix B:\n");
    printMatrix(result, rowsA, colsB);

    int transposed[MAX][MAX];
    transposeMatrix(A, transposed, rowsA, colsA);
    printf("\nTransposed Matrix A:\n");
    printMatrix(transposed, colsA, rowsA);

    return 0;
}