//FormAI DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#define ROWS 3
#define COLS 3

int main() {

    int matrixA[ROWS][COLS], matrixB[ROWS][COLS], matrixC[ROWS][COLS];

    // initialize matrix A
    printf("Enter values for matrix A:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("A[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // initialize matrix B
    printf("Enter values for matrix B:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("B[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // add matrix A and B
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // print matrix C
    printf("Matrix C = A + B:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    // multiply matrix A and B
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrixC[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // print matrix C
    printf("Matrix C = A * B:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    return 0;
}