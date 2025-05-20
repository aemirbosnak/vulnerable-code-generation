//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  // Maximum size for the matrices

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                 int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                      int C[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, 
                      int colsB);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    // Input for the first matrix
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the elements of Matrix A:\n");
    inputMatrix(A, rowsA, colsA);
    
    // Input for the second matrix
    printf("Enter the number of rows and columns for Matrix B (should be the same as A for addition): ");
    scanf("%d %d", &rowsB, &colsB);
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrix dimensions do not match for addition!\n");
        return 1;
    }
    printf("Enter the elements of Matrix B:\n");
    inputMatrix(B, rowsB, colsB);
    
    // Addition of matrices
    addMatrices(A, B, C, rowsA, colsA);
    printf("Result of Matrix A + Matrix B:\n");
    printMatrix(C, rowsA, colsA);

    // Input for multiplication
    printf("Enter the number of columns for Matrix B (for multiplication): ");
    scanf("%d", &colsB);
    if (colsA != rowsB) {
        printf("Matrix dimensions do not allow multiplication!\n");
        return 1;
    }

    // Allocate space for the result of multiplication
    int D[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(A, B, D, rowsA, colsA, colsB);
    printf("Result of Matrix A * Matrix B:\n");
    printMatrix(D, rowsA, colsB);

    return 0;
}

// Function for inputting a matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function for printing a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for adding two matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                 int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for multiplying two matrices
void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                      int C[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, 
                      int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;  // Initialize the resulting matrix element
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];  // Perform multiplication
            }
        }
    }
}