//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Define matrix dimensions
    int rows = 3;
    int cols = 3;

    // Allocate memory for matrix
    float **matrix = (float **) malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (float *) malloc(cols * sizeof(float));
    }

    // Populate matrix with values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;
        }
    }

    // Print matrix
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }

    // Perform matrix addition
    float **result = (float **) malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        result[i] = (float *) malloc(cols * sizeof(float));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] + matrix[i][j];
        }
    }

    // Print result matrix
    printf("Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < rows; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}