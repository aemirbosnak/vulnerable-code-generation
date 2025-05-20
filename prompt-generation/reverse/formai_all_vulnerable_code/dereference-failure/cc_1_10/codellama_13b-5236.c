//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: safe
// A safe matrix operations example program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a matrix
Matrix *create_matrix(int rows, int cols) {
    Matrix *mat = malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(rows * cols * sizeof(int));
    return mat;
}

// Function to print a matrix
void print_matrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix *add_matrices(Matrix *mat1, Matrix *mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        fprintf(stderr, "Error: matrices have different dimensions\n");
        return NULL;
    }
    Matrix *result = create_matrix(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix *multiply_matrices(Matrix *mat1, Matrix *mat2) {
    if (mat1->cols != mat2->rows) {
        fprintf(stderr, "Error: matrices cannot be multiplied\n");
        return NULL;
    }
    Matrix *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            for (int k = 0; k < mat1->cols; k++) {
                result->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix *transpose_matrix(Matrix *mat) {
    Matrix *result = create_matrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[j][i] = mat->data[i][j];
        }
    }
    return result;
}

// Function to invert a matrix
Matrix *invert_matrix(Matrix *mat) {
    Matrix *result = create_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i][j] = 1.0 / mat->data[i][j];
        }
    }
    return result;
}

// Example usage of the functions
int main() {
    Matrix *mat1 = create_matrix(2, 3);
    mat1->data[0][0] = 1;
    mat1->data[0][1] = 2;
    mat1->data[0][2] = 3;
    mat1->data[1][0] = 4;
    mat1->data[1][1] = 5;
    mat1->data[1][2] = 6;

    Matrix *mat2 = create_matrix(2, 3);
    mat2->data[0][0] = 7;
    mat2->data[0][1] = 8;
    mat2->data[0][2] = 9;
    mat2->data[1][0] = 10;
    mat2->data[1][1] = 11;
    mat2->data[1][2] = 12;

    Matrix *result = add_matrices(mat1, mat2);
    print_matrix(result);

    result = multiply_matrices(mat1, mat2);
    print_matrix(result);

    result = transpose_matrix(mat1);
    print_matrix(result);

    result = invert_matrix(mat1);
    print_matrix(result);

    return 0;
}