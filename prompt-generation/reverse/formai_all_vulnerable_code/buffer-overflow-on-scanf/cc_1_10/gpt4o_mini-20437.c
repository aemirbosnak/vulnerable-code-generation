//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2);

// Main function - where the magic happens
int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    
    // Welcome message
    printf("Welcome to the Enchanted Matrix Operation Realm!\n");
    printf("Let us conjure two mystical matrices and perform operations on them.\n");
    
    // User input for Matrix A
    printf("Enter the dimensions of Matrix A (rows columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Now, enter the elements of Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    // User input for Matrix B
    printf("Enter the dimensions of Matrix B (rows columns): ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Now, enter the elements of Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }
    
    // Matrix addition - only if dimensions match
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("The result of Matrix A + Matrix B is:\n");
        displayMatrix(result, rowsA, colsA);
    } else {
        printf("Alas! The dimensions do not match for addition.\n");
    }

    // Matrix multiplication - only if the columns of A equals rows of B
    if (colsA == rowsB) {
        multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, rowsB, colsB);
        printf("The result of Matrix A x Matrix B is:\n");
        displayMatrix(result, rowsA, colsB);
    } else {
        printf("Alas! The shapes are not aligned for multiplication.\n");
    }

    printf("Thank you for visiting the Enchanted Matrix Operation Realm!\n");
    return 0;
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    // Initialize the result matrix
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialise to zero
        }
    }
    
    // Perform multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}