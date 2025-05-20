//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: portable
/*
 * Matrix Operations Example Program
 *
 * This program demonstrates basic matrix operations in C using a
 * portable style.
 *
 * Usage:
 *  ./matrix_ops <matrix_size>
 *
 * Examples:
 *  ./matrix_ops 3
 *  ./matrix_ops 5
 */

#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3

// Define the matrix structure
typedef struct {
    int rows;
    int cols;
    double *data;
} Matrix;

// Define the matrix operation functions
void init_matrix(Matrix *m, int rows, int cols);
void print_matrix(Matrix *m);
void free_matrix(Matrix *m);

// Matrix addition
void add_matrix(Matrix *a, Matrix *b, Matrix *c);

// Matrix multiplication
void mul_matrix(Matrix *a, Matrix *b, Matrix *c);

// Main function
int main(int argc, char *argv[]) {
    // Parse command-line arguments
    int size = atoi(argv[1]);

    // Allocate matrices
    Matrix *a = malloc(sizeof(Matrix));
    Matrix *b = malloc(sizeof(Matrix));
    Matrix *c = malloc(sizeof(Matrix));

    // Initialize matrices
    init_matrix(a, size, size);
    init_matrix(b, size, size);
    init_matrix(c, size, size);

    // Print matrices
    printf("Matrix A:\n");
    print_matrix(a);
    printf("\nMatrix B:\n");
    print_matrix(b);
    printf("\nMatrix C:\n");
    print_matrix(c);

    // Perform matrix addition
    add_matrix(a, b, c);
    printf("\nMatrix A + Matrix B:\n");
    print_matrix(c);

    // Perform matrix multiplication
    mul_matrix(a, b, c);
    printf("\nMatrix A x Matrix B:\n");
    print_matrix(c);

    // Free matrices
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);

    return 0;
}

// Initialize matrix
void init_matrix(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++) {
        m->data[i] = (double)i;
    }
}

// Print matrix
void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%.2f ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

// Free matrix
void free_matrix(Matrix *m) {
    free(m->data);
    free(m);
}

// Matrix addition
void add_matrix(Matrix *a, Matrix *b, Matrix *c) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Matrices have different dimensions\n");
        return;
    }
    for (int i = 0; i < a->rows * a->cols; i++) {
        c->data[i] = a->data[i] + b->data[i];
    }
}

// Matrix multiplication
void mul_matrix(Matrix *a, Matrix *b, Matrix *c) {
    if (a->cols != b->rows) {
        printf("Matrices have different dimensions\n");
        return;
    }
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            double sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            c->data[i * c->cols + j] = sum;
        }
    }
}