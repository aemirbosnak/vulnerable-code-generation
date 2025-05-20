//FormAI DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

// Function to print matrix
void printMatrix(int matrix[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix addition
void addMatrices(int matrix1[][COLS], int matrix2[][COLS], int rows) {
    int result[ROWS][COLS];
    printf("Matrix Addition Result: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printMatrix(result, rows);
}

// Function to perform matrix multiplication
void multiplyMatrices(int matrix1[][COLS], int matrix2[][COLS], int rows) {
    int result[ROWS][COLS];
    printf("Matrix Multiplication Result: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printMatrix(result, rows);
}

// Function to perform matrix subtraction
void subtractMatrices(int matrix1[][COLS], int matrix2[][COLS], int rows) {
    int result[ROWS][COLS];
    printf("Matrix Subtraction Result: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printMatrix(result, rows);
}

int main() {
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS];
    printf("Enter elements of first Matrix: \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter elements of second Matrix: \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("Matrix1: \n");
    printMatrix(matrix1, ROWS);
    printf("Matrix2: \n");
    printMatrix(matrix2, ROWS);
    addMatrices(matrix1, matrix2, ROWS);
    subtractMatrices(matrix1, matrix2, ROWS);
    multiplyMatrices(matrix1, matrix2, ROWS);
    return 0;
}