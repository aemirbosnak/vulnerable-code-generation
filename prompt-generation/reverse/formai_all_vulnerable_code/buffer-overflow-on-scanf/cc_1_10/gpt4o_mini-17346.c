//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
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

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int choice, a[MAX][MAX], b[MAX][MAX], result[MAX][MAX], rowsA, colsA, rowsB, colsB;

    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Multiply Matrices\n");
        printf("3. Transpose a Matrix\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter dimensions for Matrix A (rows, columns): ");
                scanf("%d %d", &rowsA, &colsA);
                inputMatrix(a, rowsA, colsA);
                
                printf("Enter dimensions for Matrix B (rows, columns): ");
                scanf("%d %d", &rowsB, &colsB);
                if (rowsA != rowsB || colsA != colsB) {
                    printf("Matrices must have the same dimensions for addition!\n");
                    break;
                }
                inputMatrix(b, rowsB, colsB);
                
                addMatrices(a, b, result, rowsA, colsA);
                printf("Result of Matrix Addition:\n");
                displayMatrix(result, rowsA, colsA);
                break;

            case 2:
                printf("Enter dimensions for Matrix A (rows, columns): ");
                scanf("%d %d", &rowsA, &colsA);
                inputMatrix(a, rowsA, colsA);
                
                printf("Enter dimensions for Matrix B (rows, columns): ");
                scanf("%d %d", &rowsB, &colsB);
                if (colsA != rowsB) {
                    printf("Number of columns in Matrix A must equal number of rows in Matrix B!\n");
                    break;
                }
                inputMatrix(b, rowsB, colsB);
                
                multiplyMatrices(a, b, result, rowsA, colsA, colsB);
                printf("Result of Matrix Multiplication:\n");
                displayMatrix(result, rowsA, colsB);
                break;

            case 3:
                printf("Enter dimensions for Matrix (rows, columns): ");
                scanf("%d %d", &rowsA, &colsA);
                inputMatrix(a, rowsA, colsA);
                
                transposeMatrix(a, result, rowsA, colsA);
                printf("Result of Matrix Transposition:\n");
                displayMatrix(result, colsA, rowsA);
                break;

            case 4:
                printf("Exiting... Goodbye!\n");
                break;

            default:
                printf("Invalid option! Please choose a valid operation.\n");
        }
    } while (choice != 4);

    return 0;
}