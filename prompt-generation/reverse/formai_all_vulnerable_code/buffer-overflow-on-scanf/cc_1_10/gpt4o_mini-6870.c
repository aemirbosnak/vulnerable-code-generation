//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void addMatrices(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols);
void subtractMatrices(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols);
void multiplyMatrices(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rowsA, int colsA, int rowsB, int colsB);

int main() {
    int A[MAX_ROWS][MAX_COLS], B[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("Enter matrix A (%dx%d):\n", rowsA, colsA);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    printf("Enter matrix B (%dx%d):\n", rowsB, colsB);
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    int choice;
    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Print Matrices\n");
        printf("5. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Addition:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrix dimensions do not match for addition.\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Subtraction:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrix dimensions do not match for subtraction.\n");
                }
                break;

            case 3:
                if (colsA == rowsB) {
                    multiplyMatrices(A, B, result, rowsA, colsA, rowsB, colsB);
                    printf("Result of Multiplication:\n");
                    printMatrix(result, rowsA, colsB);
                } else {
                    printf("Matrix dimensions do not match for multiplication.\n");
                }
                break;

            case 4:
                printf("Matrix A:\n");
                printMatrix(A, rowsA, colsA);
                printf("Matrix B:\n");
                printMatrix(B, rowsB, colsB);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}