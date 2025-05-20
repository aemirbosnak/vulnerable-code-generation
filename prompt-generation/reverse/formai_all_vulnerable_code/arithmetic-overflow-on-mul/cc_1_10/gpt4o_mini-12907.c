//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements for the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int rowsA, int colsA, int matrixA[rowsA][colsA], int rowsB, int colsB, int matrixB[rowsB][colsB], int result[rowsA][colsB]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Welcome to the Matrix Operations Program!\n");
    printf("Let's explore two matrices.\n");

    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    int matrixA[rowsA][colsA];

    printf("Enter the dimensions for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    int matrixB[rowsB][colsB];

    if (rowsA != rowsB || colsA != colsB) {
        printf("For addition and subtraction, both matrices must have the same dimensions.\n");
    } else {
        inputMatrix(rowsA, colsA, matrixA);
        inputMatrix(rowsB, colsB, matrixB);

        int resultAdd[rowsA][colsA];
        int resultSub[rowsA][colsA];

        printf("\nExciting! Let’s add the matrices together:\n");
        addMatrices(rowsA, colsA, matrixA, matrixB, resultAdd);
        printMatrix(rowsA, colsA, resultAdd);

        printf("\nNow, let's explore the subtraction of these matrices:\n");
        subtractMatrices(rowsA, colsA, matrixA, matrixB, resultSub);
        printMatrix(rowsA, colsA, resultSub);
    }

    if (colsA != rowsB) {
        printf("For multiplication, the number of columns in Matrix A must match the number of rows in Matrix B.\n");
    } else {
        int resultMul[rowsA][colsB];
        printf("\nLet's multiply these matrices together:\n");
        multiplyMatrices(rowsA, colsA, matrixA, rowsB, colsB, matrixB, resultMul);
        printMatrix(rowsA, colsB, resultMul);
    }

    printf("Thank you for exploring matrix operations with us!\n");
    return 0;
}