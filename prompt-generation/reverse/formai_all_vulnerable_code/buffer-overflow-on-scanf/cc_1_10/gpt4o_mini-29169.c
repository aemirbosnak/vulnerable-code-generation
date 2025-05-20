//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("\nMatrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void subtractMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

void multiplyMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int matA[MAX_SIZE][MAX_SIZE], matB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    // Matrix A input
    printf("Matrix A:\n");
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rowsA, &colsA);
    inputMatrix(matA, rowsA, colsA);
    displayMatrix(matA, rowsA, colsA);

    // Matrix B input
    printf("\nMatrix B:\n");
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rowsB, &colsB);
    inputMatrix(matB, rowsB, colsB);
    displayMatrix(matB, rowsB, colsB);

    if (rowsA == rowsB && colsA == colsB) {
        // Matrix addition
        int addResult[MAX_SIZE][MAX_SIZE];
        addMatrices(matA, matB, addResult, rowsA, colsA);
        displayMatrix(addResult, rowsA, colsA);

        // Matrix subtraction
        int subResult[MAX_SIZE][MAX_SIZE];
        subtractMatrices(matA, matB, subResult, rowsA, colsA);
        displayMatrix(subResult, rowsA, colsA);
    } else {
        printf("Matrices must be of the same dimensions for addition and subtraction!\n");
    }

    if (colsA == rowsB) {
        // Matrix multiplication
        int multResult[MAX_SIZE][MAX_SIZE] = {0};
        multiplyMatrices(matA, matB, multResult, rowsA, colsA, colsB);
        displayMatrix(multResult, rowsA, colsB);
    } else {
        printf("Matrices cannot be multiplied! The number of columns in A must equal the number of rows in B.\n");
    }

    return 0;
}