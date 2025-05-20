//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void subtractMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
}

void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsFirst, int colsFirst, int colsSecond) {
    for (int i = 0; i < rowsFirst; i++) {
        for (int j = 0; j < colsSecond; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsFirst; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

int main() {
    int first[MAX_SIZE][MAX_SIZE], second[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Matrix Operations Program\n");
    printf("===========================\n");

    // Input for first matrix
    printf("Enter number of rows for first matrix: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for first matrix: ");
    scanf("%d", &cols1);
    readMatrix(first, rows1, cols1);
    printMatrix(first, rows1, cols1);

    // Input for second matrix
    printf("Enter number of rows for second matrix: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for second matrix: ");
    scanf("%d", &cols2);
    readMatrix(second, rows2, cols2);
    printMatrix(second, rows2, cols2);

    // Check for addition and subtraction compatibility
    if (rows1 == rows2 && cols1 == cols2) {
        // Addition
        addMatrices(first, second, result, rows1, cols1);
        printf("Sum of matrices:\n");
        printMatrix(result, rows1, cols1);

        // Subtraction
        subtractMatrices(first, second, result, rows1, cols1);
        printf("Difference of matrices:\n");
        printMatrix(result, rows1, cols1);
    } else {
        printf("Addition or subtraction not possible between the two matrices.\n");
    }

    // Check for multiplication compatibility
    if (cols1 == rows2) {
        // Multiplication
        multiplyMatrices(first, second, result, rows1, cols1, cols2);
        printf("Product of matrices:\n");
        printMatrix(result, rows1, cols2);
    } else {
        printf("Multiplication not possible between the two matrices.\n");
    }

    return 0;
}