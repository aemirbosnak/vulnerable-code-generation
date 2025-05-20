//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: relaxed
/*
 * Matrix operations example program in C
 *
 * This program performs matrix operations such as addition,
 * subtraction, multiplication, and transposition.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
struct Matrix {
    int rows;
    int cols;
    int **data;
};

// Function to create a matrix
struct Matrix* create_matrix(int rows, int cols) {
    struct Matrix *matrix = malloc(sizeof(struct Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(sizeof(int) * cols);
    }
    return matrix;
}

// Function to free a matrix
void free_matrix(struct Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Function to print a matrix
void print_matrix(struct Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
struct Matrix* add_matrices(struct Matrix *matrix1, struct Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrices must have the same dimensions\n");
        return NULL;
    }
    struct Matrix *result = create_matrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
struct Matrix* subtract_matrices(struct Matrix *matrix1, struct Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrices must have the same dimensions\n");
        return NULL;
    }
    struct Matrix *result = create_matrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
struct Matrix* multiply_matrices(struct Matrix *matrix1, struct Matrix *matrix2) {
    if (matrix1->cols != matrix2->rows) {
        printf("Matrices must have compatible dimensions\n");
        return NULL;
    }
    struct Matrix *result = create_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
struct Matrix* transpose_matrix(struct Matrix *matrix) {
    struct Matrix *result = create_matrix(matrix->cols, matrix->rows);
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = matrix->data[j][i];
        }
    }
    return result;
}

int main() {
    // Initialize two matrices
    struct Matrix *matrix1 = create_matrix(2, 3);
    struct Matrix *matrix2 = create_matrix(2, 3);

    // Fill matrices with random values
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            matrix1->data[i][j] = rand() % 10;
            matrix2->data[i][j] = rand() % 10;
        }
    }

    // Perform matrix operations
    struct Matrix *result = add_matrices(matrix1, matrix2);
    print_matrix(result);

    result = subtract_matrices(matrix1, matrix2);
    print_matrix(result);

    result = multiply_matrices(matrix1, matrix2);
    print_matrix(result);

    result = transpose_matrix(matrix1);
    print_matrix(result);

    // Free matrices
    free_matrix(matrix1);
    free_matrix(matrix2);
    free_matrix(result);

    return 0;
}