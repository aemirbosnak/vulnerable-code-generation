//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int aRows, int aCols, int bCols) {
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < aCols; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB, choice;

    printf("Matrix Operations Program\n");
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    inputMatrix(matrixA, rowsA, colsA);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    inputMatrix(matrixB, rowsB, colsB);

    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Transpose of Matrix A\n");
    printf("5. Transpose of Matrix B\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (rowsA == rowsB && colsA == colsB) {
                addMatrices(matrixA, matrixB, result, rowsA, colsA);
                printMatrix(result, rowsA, colsA);
            } else {
                printf("Error: Matrices must be of the same dimensions for addition.\n");
            }
            break;
        case 2:
            if (rowsA == rowsB && colsA == colsB) {
                subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                printMatrix(result, rowsA, colsA);
            } else {
                printf("Error: Matrices must be of the same dimensions for subtraction.\n");
            }
            break;
        case 3:
            if (colsA == rowsB) {
                multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
                printMatrix(result, rowsA, colsB);
            } else {
                printf("Error: Invalid dimensions for multiplication (colsA must equal rowsB).\n");
            }
            break;
        case 4:
            transposeMatrix(matrixA, result, rowsA, colsA);
            printMatrix(result, colsA, rowsA);
            break;
        case 5:
            transposeMatrix(matrixB, result, rowsB, colsB);
            printMatrix(result, colsB, rowsB);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}