//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

// Function prototypes
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB);

int main() {
    // In the neon-lit shadows of a cyberpunk city, we fork matrices
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    
    // Seed random number generator for matrix creations
    srand(time(NULL));

    printf("Enter the rows and columns for Matrix A (max %d x %d): ", MAX_SIZE, MAX_SIZE);
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the rows and columns for Matrix B (max %d x %d): ", MAX_SIZE, MAX_SIZE);
    scanf("%d %d", &rowsB, &colsB);
    
    // Dimensions compatibility check for addition and multiplication
    if (rowsB != rowsA || colsB != colsA) {
        printf("Matrix dimensions do not match for addition or subtraction!\n");
        return 1;
    }

    if (colsA != rowsB) {
        printf("Matrix dimensions do not match for multiplication!\n");
        return 1;
    }

    // Generate matrices A and B with random values
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            matrixA[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
    
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            matrixB[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
    
    printf("Matrix A:\n");
    printMatrix(matrixA, rowsA, colsA);
    
    printf("Matrix B:\n");
    printMatrix(matrixB, rowsB, colsB);

    // Matrix addition
    addMatrices(matrixA, matrixB, result, rowsA, colsA);
    printf("Addition of Matrix A and B:\n");
    printMatrix(result, rowsA, colsA);
    
    // Matrix subtraction
    subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
    printf("Subtraction of Matrix A from B:\n");
    printMatrix(result, rowsA, colsA);
    
    // Matrix multiplication
    multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
    printf("Multiplication of Matrix A and B:\n");
    printMatrix(result, rowsA, colsB);

    return 0;
}

// Function implementations
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

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize result element
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}