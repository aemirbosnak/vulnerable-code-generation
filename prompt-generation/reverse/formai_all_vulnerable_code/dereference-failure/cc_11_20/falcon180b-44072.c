//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    int i, j;
    int **matrix1 = (int **)malloc(ROWS * sizeof(int *));
    int **matrix2 = (int **)malloc(ROWS * sizeof(int *));
    int **result = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        matrix1[i] = (int *)malloc(COLS * sizeof(int));
        matrix2[i] = (int *)malloc(COLS * sizeof(int));
        result[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Fill matrices with random values
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    // Add matrices
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print matrices
    printf("Matrix 1:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix 2:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("Result:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < ROWS; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}