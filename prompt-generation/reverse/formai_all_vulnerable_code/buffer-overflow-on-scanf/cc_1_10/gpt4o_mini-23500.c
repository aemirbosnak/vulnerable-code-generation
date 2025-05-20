//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void promptMatrix(int matrix[MAX][MAX], int rows, int cols, const char *name) {
    printf("Enter elements for %s (size %dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int aRows, int aCols, int bCols) {
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            c[i][j] = 0;
            for (int k = 0; k < aCols; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            b[j][i] = a[i][j];
        }
    }
}

void menu() {
    printf("Matrix Operations Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Multiply Matrices\n");
    printf("3. Transpose a Matrix\n");
    printf("4. Exit\n");
}

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int transposed[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Adding Matrices!\n");
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &rowsA, &colsA);
                printf("Enter rows and columns for Matrix B (must be the same as A): ");
                scanf("%d %d", &rowsB, &colsB);
                if (rowsA != rowsB || colsA != colsB) {
                    printf("Matrix dimensions do not match for addition!\n");
                    break;
                }
                promptMatrix(matrixA, rowsA, colsA, "Matrix A");
                promptMatrix(matrixB, rowsB, colsB, "Matrix B");
                addMatrices(matrixA, matrixB, result, rowsA, colsA);
                printMatrix(result, rowsA, colsA);
                break;

            case 2:
                printf("Multiplying Matrices!\n");
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &rowsA, &colsA);
                printf("Enter rows and columns for Matrix B (num of rows should match A's cols): ");
                scanf("%d %d", &rowsB, &colsB);
                if (colsA != rowsB) {
                    printf("Matrix dimensions do not match for multiplication!\n");
                    break;
                }
                promptMatrix(matrixA, rowsA, colsA, "Matrix A");
                promptMatrix(matrixB, rowsB, colsB, "Matrix B");
                multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
                printMatrix(result, rowsA, colsB);
                break;

            case 3:
                printf("Transposing a Matrix!\n");
                printf("Enter rows and columns for the matrix: ");
                scanf("%d %d", &rowsA, &colsA);
                promptMatrix(matrixA, rowsA, colsA, "Matrix A");
                transposeMatrix(matrixA, transposed, rowsA, colsA);
                printMatrix(transposed, colsA, rowsA);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please select from the menu.\n");
        }
    }
    return 0;
}