//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 10
#define NUM_COLS 10

int main() {
    int matrixA[NUM_ROWS][NUM_COLS] = {{0}};
    int matrixB[NUM_ROWS][NUM_COLS] = {{0}};
    int matrixC[NUM_ROWS][NUM_COLS] = {{0}};

    // Fill matrices with random numbers
    srand(time(NULL));
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            matrixA[i][j] = rand() % 100;
            matrixB[i][j] = rand() % 100;
        }
    }

    // Perform matrix multiplication using bitwise operations
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            int sum = 0;
            for (int k = 0; k < NUM_COLS; k++) {
                sum += (matrixA[i][k] & matrixB[k][j]) << (k * 8);
            }
            matrixC[i][j] = sum;
        }
    }

    // Print results
    printf("Matrix A:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix C:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    return 0;
}