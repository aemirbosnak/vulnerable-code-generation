//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void populateMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int rowsB, int colsB);

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    // Welcome to the mind-bending world of matrix operations!
    printf("Welcome to the Matrix Operations Wonderland! 🌌\n");

    // User input for matrix A
    printf("Enter dimensions for Matrix A (rows followed by columns, max %d): ", MAX);
    scanf("%d %d", &rowsA, &colsA);
    populateMatrix(A, rowsA, colsA);
    printf("Matrix A:\n");
    printMatrix(A, rowsA, colsA);

    // User input for matrix B
    printf("Enter dimensions for Matrix B (rows followed by columns, max %d): ", MAX);
    scanf("%d %d", &rowsB, &colsB);
    populateMatrix(B, rowsB, colsB);
    printf("Matrix B:\n");
    printMatrix(B, rowsB, colsB);

    // Adding matrices
    if (rowsA == rowsB && colsA == colsB) {
        printf("Adding matrices together...\n");
        addMatrices(A, B, result, rowsA, colsA);
        printf("Result of A + B:\n");
        printMatrix(result, rowsA, colsA);
    } else {
        printf("Dimensions do not match for addition!\n");
    }

    // Subtracting matrices
    if (rowsA == rowsB && colsA == colsB) {
        printf("Subtracting matrices...\n");
        subtractMatrices(A, B, result, rowsA, colsA);
        printf("Result of A - B:\n");
        printMatrix(result, rowsA, colsA);
    } else {
        printf("Dimensions do not match for subtraction!\n");
    }

    // Multiplying matrices
    if (colsA == rowsB) {
        printf("Multiplying matrices...\n");
        multiplyMatrices(A, B, result, rowsA, colsA, rowsB, colsB);
        printf("Result of A * B:\n");
        printMatrix(result, rowsA, colsB);
    } else {
        printf("Dimensions do not match for multiplication!\n");
    }

    printf("Thank you for visiting the Matrix Operations Wonderland! 🎉\n");
    return 0;
}

void populateMatrix(int matrix[MAX][MAX], int rows, int cols) {
    srand(time(0)); // Seed for randomness
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Random numbers between 0-9
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}