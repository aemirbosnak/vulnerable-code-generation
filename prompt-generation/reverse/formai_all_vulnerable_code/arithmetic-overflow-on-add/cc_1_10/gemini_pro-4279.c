//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

void printMatrix(int matrix[ROWS][COLS]);
void addMatrices(int firstMatrix[ROWS][COLS], int secondMatrix[ROWS][COLS], int resultMatrix[ROWS][COLS]);
void subtractMatrices(int firstMatrix[ROWS][COLS], int secondMatrix[ROWS][COLS], int resultMatrix[ROWS][COLS]);
void multiplyMatrices(int firstMatrix[ROWS][COLS], int secondMatrix[COLS][ROWS], int resultMatrix[ROWS][COLS]);

int main() {
    // Initialize the first matrix
    int firstMatrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Initialize the second matrix
    int secondMatrix[ROWS][COLS] = {
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };

    // Initialize the result matrix
    int resultMatrix[ROWS][COLS];

    // Print the first matrix
    printf("First matrix:\n");
    printMatrix(firstMatrix);

    // Print the second matrix
    printf("Second matrix:\n");
    printMatrix(secondMatrix);

    // Add the two matrices
    addMatrices(firstMatrix, secondMatrix, resultMatrix);

    // Print the result matrix
    printf("Result of addition:\n");
    printMatrix(resultMatrix);

    // Subtract the two matrices
    subtractMatrices(firstMatrix, secondMatrix, resultMatrix);

    // Print the result matrix
    printf("Result of subtraction:\n");
    printMatrix(resultMatrix);

    // Multiply the two matrices
    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix);

    // Print the result matrix
    printf("Result of multiplication:\n");
    printMatrix(resultMatrix);

    return 0;
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int firstMatrix[ROWS][COLS], int secondMatrix[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
}

void subtractMatrices(int firstMatrix[ROWS][COLS], int secondMatrix[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
        }
    }
}

void multiplyMatrices(int firstMatrix[ROWS][COLS], int secondMatrix[COLS][ROWS], int resultMatrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}