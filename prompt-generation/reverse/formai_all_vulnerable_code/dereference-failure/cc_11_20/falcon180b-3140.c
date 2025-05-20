//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Declare variables
    int rows, cols, i, j;

    // Initialize variables
    rows = 3;
    cols = 3;

    // Allocate memory for matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize matrix with random values
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Print original matrix
    printf("Original matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose matrix
    int **transpose = (int **)malloc(cols * sizeof(int *));
    for (i = 0; i < cols; i++) {
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print transposed matrix
    printf("Transposed matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Multiply matrix by scalar
    int scalar = 2;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] *= scalar;
        }
    }

    // Print multiplied matrix
    printf("Matrix multiplied by %d:\n", scalar);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    for (i = 0; i < cols; i++) {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}