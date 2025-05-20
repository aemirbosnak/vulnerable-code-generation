//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: intelligent
// A unique C Matrix operations example program in an intelligent style
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a matrix struct
typedef struct {
    int rows;
    int cols;
    double *data;
} Matrix;

// Function to initialize a matrix
void init_matrix(Matrix *matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double *)malloc(rows * cols * sizeof(double));
}

// Function to print a matrix
void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%lf ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix add_matrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix result;
    init_matrix(&result, matrix1->rows, matrix1->cols);

    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result.data[i * matrix1->cols + j] = matrix1->data[i * matrix1->cols + j] + matrix2->data[i * matrix2->cols + j];
        }
    }

    return result;
}

// Function to multiply two matrices
Matrix multiply_matrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix result;
    init_matrix(&result, matrix1->rows, matrix2->cols);

    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            double sum = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                sum += matrix1->data[i * matrix1->cols + k] * matrix2->data[k * matrix2->cols + j];
            }
            result.data[i * matrix2->cols + j] = sum;
        }
    }

    return result;
}

// Function to transpose a matrix
Matrix transpose_matrix(Matrix *matrix) {
    Matrix result;
    init_matrix(&result, matrix->cols, matrix->rows);

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result.data[j * matrix->rows + i] = matrix->data[i * matrix->cols + j];
        }
    }

    return result;
}

int main() {
    // Initialize two matrices
    Matrix matrix1, matrix2;
    init_matrix(&matrix1, 2, 3);
    init_matrix(&matrix2, 3, 2);

    // Fill the matrices with data
    matrix1.data[0] = 1;
    matrix1.data[1] = 2;
    matrix1.data[2] = 3;
    matrix1.data[3] = 4;
    matrix1.data[4] = 5;
    matrix1.data[5] = 6;

    matrix2.data[0] = 7;
    matrix2.data[1] = 8;
    matrix2.data[2] = 9;
    matrix2.data[3] = 10;
    matrix2.data[4] = 11;
    matrix2.data[5] = 12;

    // Add two matrices
    Matrix result = add_matrices(&matrix1, &matrix2);
    print_matrix(&result);

    // Multiply two matrices
    result = multiply_matrices(&matrix1, &matrix2);
    print_matrix(&result);

    // Transpose a matrix
    result = transpose_matrix(&matrix1);
    print_matrix(&result);

    return 0;
}