//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

// Function Declarations
void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    // Initialize random number generator
    srand(time(NULL));

    // Input dimensions
    printf("Enter number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    if (rows > MAX_SIZE || cols > MAX_SIZE || rows <= 0 || cols <= 0) {
        printf("Invalid matrix size!\n");
        return 1;
    }

    // Fill matrices with random values
    fillMatrix(matrixA, rows, cols);
    fillMatrix(matrixB, rows, cols);

    // Display the matrices
    printf("\nMatrix A:\n");
    printMatrix(matrixA, rows, cols);
    printf("\nMatrix B:\n");
    printMatrix(matrixB, rows, cols);

    // Add matrices A and B
    addMatrices(matrixA, matrixB, result, rows, cols);
    printf("\nAddition of Matrix A and B:\n");
    printMatrix(result, rows, cols);

    // Multiply matrices A and B (if dimensions allow)
    if (rows == cols) {
        multiplyMatrices(matrixA, matrixB, result, rows, cols, cols, rows);
        printf("\nMultiplication of Matrix A and B:\n");
        printMatrix(result, rows, cols);
    } else {
        printf("\nMultiplication not possible. Rows and columns do not match.\n");
    }

    // Transpose Matrix A
    transposeMatrix(matrixA, result, rows, cols);
    printf("\nTranspose of Matrix A:\n");
    printMatrix(result, cols, rows); // rows and cols are swapped for transposed output

    return 0;
}

// Fill matrix with random numbers
void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Random number from 0 to 9
        }
    }
}

// Print the matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Add two matrices
void addMatrices(int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Multiply two matrices
void multiplyMatrices(int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize result matrix cell
            for (int k = 0; k < c1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}