//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 3

int main() {
    int i, j, k;
    int **mat;

    // Initialize the matrix
    mat = (int **) malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        mat[i] = (int *) malloc(COLS * sizeof(int));
    }

    // Populate the matrix
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            mat[i][j] = i * COLS + j;
        }
    }

    // Print the matrix
    printf("Original Matrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // Perform matrix multiplication
    int **result = (int **) malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        result[i] = (int *) malloc(COLS * sizeof(int));
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            for (k = 0; k < COLS; k++) {
                result[i][j] += mat[i][k] * mat[k][j];
            }
        }
    }

    // Print the result
    printf("Result Matrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (i = 0; i < ROWS; i++) {
        free(result[i]);
    }
    free(result);
    for (i = 0; i < ROWS; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}