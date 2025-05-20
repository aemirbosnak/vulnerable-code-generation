//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Max dimension for the matrices

void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize result element
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX], transposed[MAX][MAX];

    printf("Enter the number of rows and columns for matrix A:\n");
    scanf("%d %d", &rowsA, &colsA);
    readMatrix(a, rowsA, colsA);
    printMatrix(a, rowsA, colsA);

    printf("Enter the number of rows and columns for matrix B:\n");
    scanf("%d %d", &rowsB, &colsB);
    readMatrix(b, rowsB, colsB);
    printMatrix(b, rowsB, colsB);

    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(a, b, result, rowsA, colsA);
        printf("Result of addition:\n");
        printMatrix(result, rowsA, colsA);

        subtractMatrices(a, b, result, rowsA, colsA);
        printf("Result of subtraction:\n");
        printMatrix(result, rowsA, colsA);
    } else {
        printf("Addition and subtraction not possible due to dimension mismatch.\n");
    }

    if (colsA == rowsB) {
        multiplyMatrices(a, b, result, rowsA, colsA, colsB);
        printf("Result of multiplication:\n");
        printMatrix(result, rowsA, colsB);
    } else {
        printf("Multiplication not possible due to dimension mismatch.\n");
    }

    transposeMatrix(a, transposed, rowsA, colsA);
    printf("Transposed matrix A:\n");
    printMatrix(transposed, colsA, rowsA);

    return 0;
}