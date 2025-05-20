//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_POINTS 1000000
#define MAX_DIMENSIONS 100

typedef struct {
    int *data;
    int rows;
    int cols;
} Matrix;

void init_matrix(Matrix *matrix, int rows, int cols) {
    matrix->data = (int *)malloc(rows * cols * sizeof(int));
    matrix->rows = rows;
    matrix->cols = cols;
}

void fill_matrix(Matrix *matrix, int value) {
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
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

void free_matrix(Matrix *matrix) {
    free(matrix->data);
}

double elapsed_time(struct timespec start, struct timespec end) {
    double seconds = end.tv_sec - start.tv_sec;
    double nanoseconds = end.tv_nsec - start.tv_nsec;
    return seconds + nanoseconds * 1e-9;
}

int main() {
    int i, j, k, n, m, p;
    Matrix A, B, C;
    struct timespec start, end;

    srand(time(NULL));

    // Initialize matrices A and B
    n = rand() % MAX_POINTS + 1;
    m = rand() % MAX_POINTS + 1;
    p = rand() % MAX_POINTS + 1;

    init_matrix(&A, n, m);
    init_matrix(&B, m, p);

    fill_matrix(&A, rand() % 10);
    fill_matrix(&B, rand() % 10);

    // Perform matrix multiplication
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            C.data[i * p + j] = 0;
            for (k = 0; k < m; k++) {
                C.data[i * p + j] += A.data[i * m + k] * B.data[k * p + j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = elapsed_time(start, end);
    printf("Time taken: %lf seconds\n", time_taken);

    // Print matrices A, B, and C
    printf("Matrix A:\n");
    print_matrix(&A);
    printf("\n");

    printf("Matrix B:\n");
    print_matrix(&B);
    printf("\n");

    printf("Matrix C:\n");
    print_matrix(&C);
    printf("\n");

    // Free memory
    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);

    return 0;
}