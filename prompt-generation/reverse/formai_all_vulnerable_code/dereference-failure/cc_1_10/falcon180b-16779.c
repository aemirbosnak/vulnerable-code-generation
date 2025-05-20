//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846

void generate_matrix(double **matrix, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(double **matrix, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%5.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of the matrix (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    double **matrix = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double *)malloc(size * sizeof(double));
    }

    generate_matrix(matrix, size);
    printf("Generated matrix:\n");
    print_matrix(matrix, size);

    double **transposed_matrix = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        transposed_matrix[i] = (double *)malloc(size * sizeof(double));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }

    printf("\nTransposed matrix:\n");
    print_matrix(transposed_matrix, size);

    double **scaled_matrix = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        scaled_matrix[i] = (double *)malloc(size * sizeof(double));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scaled_matrix[i][j] = matrix[i][j] * 2;
        }
    }

    printf("\nScaled matrix:\n");
    print_matrix(scaled_matrix, size);

    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < size; i++) {
        free(transposed_matrix[i]);
    }
    free(transposed_matrix);

    for (int i = 0; i < size; i++) {
        free(scaled_matrix[i]);
    }
    free(scaled_matrix);

    return 0;
}