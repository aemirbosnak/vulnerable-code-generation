//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: happy
// A Happy Matrix Operations Program in C
#include <stdio.h>
#include <stdlib.h>

// Define a matrix struct
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Define a function to create a matrix
Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

// Define a function to print a matrix
void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Define a function to add two matrices
Matrix *add_matrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix *result = create_matrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

// Define a function to multiply two matrices
Matrix *multiply_matrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix *result = create_matrix(matrix1->rows, matrix2->cols);
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

// Define a function to transpose a matrix
Matrix *transpose_matrix(Matrix *matrix) {
    Matrix *result = create_matrix(matrix->cols, matrix->rows);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[j][i] = matrix->data[i][j];
        }
    }
    return result;
}

int main() {
    // Create two matrices
    Matrix *matrix1 = create_matrix(2, 3);
    Matrix *matrix2 = create_matrix(3, 2);

    // Fill the matrices with values
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            matrix1->data[i][j] = i * j;
        }
    }
    for (int i = 0; i < matrix2->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            matrix2->data[i][j] = i + j;
        }
    }

    // Print the matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    print_matrix(matrix2);

    // Perform matrix operations
    Matrix *result = add_matrices(matrix1, matrix2);
    printf("Matrix 1 + Matrix 2:\n");
    print_matrix(result);
    result = multiply_matrices(matrix1, matrix2);
    printf("Matrix 1 * Matrix 2:\n");
    print_matrix(result);
    result = transpose_matrix(matrix1);
    printf("Transpose of Matrix 1:\n");
    print_matrix(result);

    // Free the memory allocated for the matrices
    free(matrix1->data);
    free(matrix2->data);
    free(matrix1);
    free(matrix2);
    free(result->data);
    free(result);

    return 0;
}