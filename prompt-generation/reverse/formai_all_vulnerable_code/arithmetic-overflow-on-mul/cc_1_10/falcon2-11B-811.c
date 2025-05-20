//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the matrix size
#define ROWS 3
#define COLS 4

// Create the matrix
int matrix[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// Function to print the matrix
void printMatrix(int matrix[][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int matrix1[][COLS], int matrix2[][COLS], int matrix3[][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            matrix3[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int matrix1[][COLS], int matrix2[][COLS], int matrix3[][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            matrix3[row][col] = 0;
            for (int i = 0; i < COLS; i++) {
                matrix3[row][col] += matrix1[row][i] * matrix2[i][col];
            }
        }
    }
}

// Main function
int main() {
    // Create two matrices
    int matrix1[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int matrix2[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Add two matrices
    int matrix3[ROWS][COLS];
    addMatrix(matrix1, matrix2, matrix3);

    // Print the result
    printf("Matrix Addition:\n");
    printMatrix(matrix3);

    // Multiply two matrices
    int matrix4[ROWS][COLS];
    multiplyMatrix(matrix1, matrix2, matrix4);

    // Print the result
    printf("Matrix Multiplication:\n");
    printMatrix(matrix4);

    return 0;
}