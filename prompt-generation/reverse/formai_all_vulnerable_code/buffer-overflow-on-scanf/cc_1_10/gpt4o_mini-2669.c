//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function to input a matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Main program
int main() {
    int first[MAX_SIZE][MAX_SIZE], second[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Enter dimensions for the first matrix (rows columns): ");
    scanf("%d %d", &rows1, &cols1);
    inputMatrix(first, rows1, cols1);

    printf("Enter dimensions for the second matrix (rows columns): ");
    scanf("%d %d", &rows2, &cols2);
    inputMatrix(second, rows2, cols2);
    
    // Display both matrices
    displayMatrix(first, rows1, cols1);
    displayMatrix(second, rows2, cols2);

    // Addition
    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(first, second, result, rows1, cols1);
        printf("Result of addition:\n");
        displayMatrix(result, rows1, cols1);
    } else {
        printf("Cannot add matrices; dimensions mismatch.\n");
    }

    // Subtraction
    if (rows1 == rows2 && cols1 == cols2) {
        subtractMatrices(first, second, result, rows1, cols1);
        printf("Result of subtraction:\n");
        displayMatrix(result, rows1, cols1);
    } else {
        printf("Cannot subtract matrices; dimensions mismatch.\n");
    }

    // Multiplication
    if (cols1 == rows2) {
        multiplyMatrices(first, second, result, rows1, cols1, cols2);
        printf("Result of multiplication:\n");
        displayMatrix(result, rows1, cols2);
    } else {
        printf("Cannot multiply matrices; dimensions mismatch.\n");
    }

    // Transpose
    printf("Transpose of the first matrix:\n");
    transposeMatrix(first, result, rows1, cols1);
    displayMatrix(result, cols1, rows1);

    printf("Transpose of the second matrix:\n");
    transposeMatrix(second, result, rows2, cols2);
    displayMatrix(result, cols2, rows2);

    return 0;
}