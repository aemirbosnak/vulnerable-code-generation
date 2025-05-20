//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: imaginative
// Imaginative Matrix Operations Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 10

// Struct for a matrix
typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

// Function to create a matrix
Matrix* create_matrix(int rows, int cols) {
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int*)malloc(cols * sizeof(int));
    }
    return mat;
}

// Function to free a matrix
void free_matrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

// Function to print a matrix
void print_matrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix addition
Matrix* add_matrices(Matrix* mat1, Matrix* mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        return NULL;
    }
    Matrix* result = create_matrix(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

// Function to perform matrix multiplication
Matrix* multiply_matrices(Matrix* mat1, Matrix* mat2) {
    if (mat1->cols != mat2->rows) {
        return NULL;
    }
    Matrix* result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < mat1->cols; k++) {
                result->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }
    return result;
}

// Function to perform matrix transpose
Matrix* transpose_matrix(Matrix* mat) {
    Matrix* result = create_matrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[j][i] = mat->data[i][j];
        }
    }
    return result;
}

// Main function
int main() {
    srand(time(NULL));

    // Create two random matrices
    Matrix* mat1 = create_matrix(MATRIX_SIZE, MATRIX_SIZE);
    Matrix* mat2 = create_matrix(MATRIX_SIZE, MATRIX_SIZE);
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            mat1->data[i][j] = rand() % 10;
            mat2->data[i][j] = rand() % 10;
        }
    }

    // Perform matrix operations
    Matrix* result1 = add_matrices(mat1, mat2);
    Matrix* result2 = multiply_matrices(mat1, mat2);
    Matrix* result3 = transpose_matrix(mat1);

    // Print the results
    printf("Matrix 1:\n");
    print_matrix(mat1);
    printf("Matrix 2:\n");
    print_matrix(mat2);
    printf("Matrix 1 + Matrix 2:\n");
    print_matrix(result1);
    printf("Matrix 1 x Matrix 2:\n");
    print_matrix(result2);
    printf("Matrix 1 transpose:\n");
    print_matrix(result3);

    // Free the matrices
    free_matrix(mat1);
    free_matrix(mat2);
    free_matrix(result1);
    free_matrix(result2);
    free_matrix(result3);

    return 0;
}