//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (k = 0; k < COLS; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matrixA[ROWS][COLS], matrixB[ROWS][COLS], resultA[ROWS][COLS], resultB[ROWS][COLS], resultC[ROWS][COLS];

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    printf("\nMatrix A:\n");
    printMatrix(matrixA);

    printf("\nMatrix B:\n");
    printMatrix(matrixB);

    // Addition
    addMatrices(matrixA, matrixB, resultA);
    printf("\nSum of Matrix A and Matrix B:\n");
    printMatrix(resultA);

    // Subtraction
    subtractMatrices(matrixA, matrixB, resultB);
    printf("\nDifference of Matrix A and Matrix B:\n");
    printMatrix(resultB);

    // Multiplication
    multiplyMatrices(matrixA, matrixB, resultC);
    printf("\nProduct of Matrix A and Matrix B:\n");
    printMatrix(resultC);

    return 0;
}