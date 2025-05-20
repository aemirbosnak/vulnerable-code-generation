//Falcon-180B DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 1000000
#define DIMENSIONS 3

typedef struct {
    double *data;
    int rows;
    int cols;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->data = (double *) malloc(rows * cols * sizeof(double));
    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

void destroy_matrix(Matrix *matrix) {
    free(matrix->data);
    free(matrix);
}

void fill_matrix(Matrix *matrix, double value) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            matrix->data[i * matrix->cols + j] = value;
        }
    }
}

void print_matrix(Matrix *matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%lf ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int num_points = rand() % MAX_POINTS + 1;
    int dimensions = rand() % DIMENSIONS + 1;

    double **data = (double **) malloc(num_points * sizeof(double *));
    for (int i = 0; i < num_points; i++) {
        data[i] = (double *) malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            data[i][j] = rand() % 100;
        }
    }

    Matrix *matrix = create_matrix(num_points, dimensions);
    fill_matrix(matrix, 0);

    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < dimensions; j++) {
            matrix->data[i * matrix->cols + j] = data[i][j];
        }
    }

    print_matrix(matrix);

    destroy_matrix(matrix);

    for (int i = 0; i < num_points; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}