//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generateMatrix(int matrix[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[ROWS][COLS], int transpose[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[ROWS][COLS], int matrix2[COLS][ROWS], int result[ROWS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < ROWS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROWS][COLS];
    int matrix2[COLS][ROWS];
    int transpose[COLS][ROWS];
    int result[ROWS][ROWS];

    generateMatrix(matrix1);
    generateMatrix(matrix2);

    printf("Matrix 1:\n");
    printMatrix(matrix1);

    printf("Matrix 2:\n");
    printMatrix(matrix2);

    transposeMatrix(matrix1, transpose);
    printf("Transpose of Matrix 1:\n");
    printMatrix(transpose);

    multiplyMatrices(matrix1, matrix2, result);
    printf("Product of Matrices:\n");
    printMatrix(result);

    return 0;
}