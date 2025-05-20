//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MEMORY_SIZE (1024 * 1024) // 1MB

int main() {
    int i, j;
    double **matrix;
    double *vector;
    int size;
    int max_size = 0;
    int current_size = 0;
    int total_size = 0;

    printf("Enter the size of the matrix (maximum %d): ", MEMORY_SIZE / sizeof(double));
    scanf("%d", &size);

    matrix = (double **)malloc(size * sizeof(double *));
    for (i = 0; i < size; i++) {
        matrix[i] = (double *)malloc(size * sizeof(double));
    }

    vector = (double *)malloc(size * sizeof(double));

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    for (i = 0; i < size; i++) {
        vector[i] = rand() % 100;
    }

    current_size = size * size * sizeof(double);
    max_size = size * size * sizeof(double);

    while (current_size < max_size) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                matrix[i][j] = rand() % 100;
            }
        }
        current_size += size * size * sizeof(double);
        total_size += size * size * sizeof(double);
    }

    printf("Total size of the matrix: %.2f MB\n", total_size / (1024 * 1024));

    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(vector);

    return 0;
}