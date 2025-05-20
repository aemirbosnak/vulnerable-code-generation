//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);
void fillMatrixRandom(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    // Initialize random number generator
    srand(time(0));

    printf("Enter dimensions for the first matrix (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter dimensions for the second matrix (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    // Ensure valid dimensions for addition and multiplication
    if (rowsA > MAX_SIZE || colsA > MAX_SIZE || rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        printf("Dimensions exceed maximum size (%d x %d).\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }
    
    if (colsA != rowsB) {
        printf("Matrix multiplication not possible! Columns in first matrix must equal Rows in second matrix.\n");
        return 1;
    }
    
    // Filling matrices with random values
    fillMatrixRandom(matrix1, rowsA, colsA);
    fillMatrixRandom(matrix2, rowsB, colsB);

    printf("Matrix 1 (%d x %d):\n", rowsA, colsA);
    printMatrix(matrix1, rowsA, colsA);
    
    printf("Matrix 2 (%d x %d):\n", rowsB, colsB);
    printMatrix(matrix2, rowsB, colsB);

    // Addition of matrices
    if (rowsA == rowsB && colsA == colsB) {
        printf("Result of Matrix Addition:\n");
        addMatrices(matrix1, matrix2, result, rowsA, colsA);
        printMatrix(result, rowsA, colsA);
    } else {
        printf("Addition not possible, matrices must be of the same dimensions.\n");
    }

    // Multiplication of matrices
    printf("Result of Matrix Multiplication:\n");
    multiplyMatrices(matrix1, matrix2, result, rowsA, colsA, rowsB, colsB);
    printMatrix(result, rowsA, colsB);

    return 0;
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            res[i][j] = 0; // Initialize result cell
            for (int k = 0; k < colsA; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void fillMatrixRandom(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 20; // Random values between 0 and 19
        }
    }
}