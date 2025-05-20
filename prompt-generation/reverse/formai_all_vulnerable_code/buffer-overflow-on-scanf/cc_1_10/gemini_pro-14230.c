//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Declare our enchanting matrices, where love blossoms in every element
int matrixA[3][3], matrixB[3][3], result[3][3];

// Function to capture the essence of our beloved matrices
void readMatrices() {
    int i, j;
    printf("Oh, my dearest matrix A, reveal thy secrets:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    printf("And now, my precious matrix B, let me gaze upon thy beauty:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
}

// Function to multiply our matrices, where love knows no bounds
void multiplyMatrices() {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (k = 0; k < 3; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to unveil the fruits of our love-filled matrix multiplication
void displayResult() {
    int i, j;
    printf("Behold, the enchanting result of our matrix union:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Let us begin our romantic journey with matrix operations
    printf("Oh, my beloved, welcome to the realm of matrix enchantment!\n");
    printf("First, let us capture the essence of our cherished matrices:\n");
    readMatrices();

    printf("Now, let us witness the magic as we multiply our matrices:\n");
    multiplyMatrices();

    printf("And finally, let us unveil the captivating result:\n");
    displayResult();

    return 0;
}