//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: safe
// A safe C program that performs matrix operations

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a matrix
struct Matrix {
    int rows;
    int cols;
    int** data;
};

// Create a matrix with the specified dimensions
struct Matrix* create_matrix(int rows, int cols) {
    struct Matrix* matrix = malloc(sizeof(struct Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * cols * sizeof(int));
    return matrix;
}

// Free the memory allocated for a matrix
void free_matrix(struct Matrix* matrix) {
    free(matrix->data);
    free(matrix);
}

// Print the elements of a matrix
void print_matrix(struct Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Add two matrices
struct Matrix* add_matrices(struct Matrix* matrix1, struct Matrix* matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        return NULL;
    }
    struct Matrix* result = create_matrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

// Multiply two matrices
struct Matrix* multiply_matrices(struct Matrix* matrix1, struct Matrix* matrix2) {
    if (matrix1->cols != matrix2->rows) {
        return NULL;
    }
    struct Matrix* result = create_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}

int main() {
    struct Matrix* matrix1 = create_matrix(2, 2);
    struct Matrix* matrix2 = create_matrix(2, 2);
    struct Matrix* result = add_matrices(matrix1, matrix2);
    print_matrix(result);
    free_matrix(result);
    free_matrix(matrix1);
    free_matrix(matrix2);
    return 0;
}