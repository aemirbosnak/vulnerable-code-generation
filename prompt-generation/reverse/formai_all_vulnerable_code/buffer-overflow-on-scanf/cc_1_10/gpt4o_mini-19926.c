//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int columns) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int columns) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int columnsA, int columnsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columnsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int rowsA, columnsA, rowsB, columnsB;
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];

    printf("Enter dimensions for the first matrix (rows columns): ");
    scanf("%d %d", &rowsA, &columnsA);

    inputMatrix(matrixA, rowsA, columnsA);
    printMatrix(matrixA, rowsA, columnsA);

    printf("Enter dimensions for the second matrix (rows columns): ");
    scanf("%d %d", &rowsB, &columnsB);

    // Check if matrices can be added
    if (rowsA == rowsB && columnsA == columnsB) {
        inputMatrix(matrixB, rowsB, columnsB);
        printMatrix(matrixB, rowsB, columnsB);

        addMatrices(matrixA, matrixB, result, rowsA, columnsA);
        printf("The sum of the matrices is:\n");
        printMatrix(result, rowsA, columnsA);
    } else {
        printf("Matrices cannot be added due to dimension mismatch!\n");
    }

    // Check if matrices can be multiplied
    if (columnsA == rowsB) {
        multiplyMatrices(matrixA, matrixB, result, rowsA, columnsA, columnsB);
        printf("The product of the matrices is:\n");
        printMatrix(result, rowsA, columnsB);
    } else {
        printf("Matrices cannot be multiplied due to dimension mismatch!\n");
    }

    return 0;
}