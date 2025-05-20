//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    int i, j, n;
    int **matrix1, **matrix2, **result;

    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix1[i][j] = rand() % 100;
        }
    }

    printf("Matrix 1:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix2[i][j] = rand() % 100;
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    result = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        result[i] = (int *)malloc(COLS * sizeof(int));
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nResult:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < ROWS; i++) {
        free(result[i]);
    }
    free(result);
    return 0;
}