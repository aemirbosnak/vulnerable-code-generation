//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_ROWS 1000
#define NUM_COLS 1000

int main() {
    int i, j;
    double **matrix;
    double sum = 0;
    double start_time = 0, end_time = 0;
    int iter = 0;

    // Allocate memory for the matrix
    matrix = (double **) malloc(NUM_ROWS * sizeof(double *));
    for (i = 0; i < NUM_ROWS; i++) {
        matrix[i] = (double *) malloc(NUM_COLS * sizeof(double));
    }

    // Initialize the matrix
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // Start the timer
    start_time = clock();

    // Perform matrix multiplication
    for (iter = 0; iter < 10; iter++) {
        for (i = 0; i < NUM_ROWS; i++) {
            for (j = 0; j < NUM_COLS; j++) {
                sum += matrix[i][j] * matrix[i][j];
            }
        }
    }

    // Stop the timer
    end_time = clock();

    // Calculate the time taken
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Print the result
    printf("Time taken: %.6f seconds\n", cpu_time_used);

    // Free the memory allocated for the matrix
    for (i = 0; i < NUM_ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}