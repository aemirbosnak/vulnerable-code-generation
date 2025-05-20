//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the size of the matrices
#define ROWS 3
#define COLUMNS 3

// Declare the matrices
int matrix1[ROWS][COLUMNS];
int matrix2[ROWS][COLUMNS];
int resultMatrix[ROWS][COLUMNS];

// Function to read the matrix from the user
void readMatrix(int matrix[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS], int resultMatrix[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS], int resultMatrix[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS], int resultMatrix[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < COLUMNS; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Driver code
int main() {
    // Read the first matrix
    printf("Enter the elements of the first matrix:\n");
    readMatrix(matrix1);

    // Read the second matrix
    printf("Enter the elements of the second matrix:\n");
    readMatrix(matrix2);

    // Add the two matrices
    addMatrices(matrix1, matrix2, resultMatrix);

    // Print the result matrix
    printf("The sum of the two matrices is:\n");
    printMatrix(resultMatrix);

    // Subtract the two matrices
    subtractMatrices(matrix1, matrix2, resultMatrix);

    // Print the result matrix
    printf("The difference of the two matrices is:\n");
    printMatrix(resultMatrix);

    // Multiply the two matrices
    multiplyMatrices(matrix1, matrix2, resultMatrix);

    // Print the result matrix
    printf("The product of the two matrices is:\n");
    printMatrix(resultMatrix);

    return 0;
}