//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 1000
#define NUM_COLS 1000

int main(int argc, char *argv[]) {
    int **matrix;
    int i, j;

    // Allocate memory for matrix
    matrix = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (i = 0; i < NUM_ROWS; i++) {
        matrix[i] = (int *)malloc(NUM_COLS * sizeof(int));
    }

    // Initialize matrix with random values
    srand(time(NULL));
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Perform matrix multiplication
    int **result = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (i = 0; i < NUM_ROWS; i++) {
        result[i] = (int *)malloc(NUM_COLS * sizeof(int));
    }

    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            int sum = 0;
            for (int k = 0; k < NUM_COLS; k++) {
                sum += matrix[i][k] * matrix[k][j];
            }
            result[i][j] = sum;
        }
    }

    // Print result matrix
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < NUM_ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (i = 0; i < NUM_ROWS; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}