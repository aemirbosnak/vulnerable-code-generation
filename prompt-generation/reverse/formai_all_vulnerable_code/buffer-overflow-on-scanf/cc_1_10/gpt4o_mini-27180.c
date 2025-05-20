//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void getMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int aRows, int aCols, int bCols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    printf("Matrix Operations Program\n");
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rowsA, &colsA);
    getMatrix(a, rowsA, colsA);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rowsB, &colsB);
    getMatrix(b, rowsB, colsB);

    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrices must have the same dimensions for addition and subtraction.\n");
    } else {
        do {
            printf("\nChoose an operation:\n");
            printf("1. Add Matrices\n");
            printf("2. Subtract Matrices\n");
            printf("3. Multiply Matrices\n");
            printf("4. Transpose First Matrix\n");
            printf("5. Transpose Second Matrix\n");
            printf("6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    addMatrices(a, b, result, rowsA, colsA);
                    printf("Result of Addition:\n");
                    printMatrix(result, rowsA, colsA);
                    break;
                case 2:
                    subtractMatrices(a, b, result, rowsA, colsA);
                    printf("Result of Subtraction:\n");
                    printMatrix(result, rowsA, colsA);
                    break;
                case 3:
                    if (colsA != rowsB) {
                        printf("Number of columns of first matrix must equal number of rows of second matrix for multiplication.\n");
                    } else {
                        multiplyMatrices(a, b, result, rowsA, colsA, colsB);
                        printf("Result of Multiplication:\n");
                        printMatrix(result, rowsA, colsB);
                    }
                    break;
                case 4:
                    transposeMatrix(a, result, rowsA, colsA);
                    printf("Transpose of First Matrix:\n");
                    printMatrix(result, colsA, rowsA);
                    break;
                case 5:
                    transposeMatrix(b, result, rowsB, colsB);
                    printf("Transpose of Second Matrix:\n");
                    printMatrix(result, colsB, rowsB);
                    break;
                case 6:
                    printf("Exiting the program.\n");
                    break;
                default:
                    printf("Invalid choice. Please choose again.\n");
            }
        } while (choice != 6);
    }

    return 0;
}

void getMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
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