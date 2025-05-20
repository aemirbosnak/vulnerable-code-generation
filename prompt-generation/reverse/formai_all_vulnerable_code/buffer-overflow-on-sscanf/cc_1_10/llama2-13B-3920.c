//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    double *data;
} Matrix;

// Function to create a matrix from a string
Matrix* create_matrix(const char* str) {
    // Parse the string as a matrix specification
    int rows, cols;
    char *endptr;
    int i, j;
    double value;

    sscanf(str, "%dx%d", &rows, &cols);
    Matrix* matrix = (Matrix*) calloc(1, sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double*) calloc(rows * cols, sizeof(double));

    // Parse the string for the matrix elements
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            value = strtol(strchr(str, ' '), &endptr, 10);
            if (*endptr != '\0') {
                printf("Error: invalid matrix element %c\n", *endptr);
                return NULL;
            }
            matrix->data[i * cols + j] = value;
            strchr(str, ' '); // Advance past the current character
        }
    }

    return matrix;
}

// Function to perform matrix multiplication
Matrix* multiply_matrices(Matrix* a, Matrix* b) {
    // Check for invalid matrix sizes
    if (a->rows != b->cols) {
        printf("Error: matrices must have the same number of columns\n");
        return NULL;
    }

    // Create the result matrix
    int result_rows = a->rows;
    int result_cols = b->cols;
    Matrix* result = (Matrix*) calloc(1, sizeof(Matrix));
    result->rows = result_rows;
    result->cols = result_cols;
    result->data = (double*) calloc(result_rows * result_cols, sizeof(double));

    // Perform matrix multiplication
    for (int i = 0; i < result_rows; i++) {
        for (int j = 0; j < result_cols; j++) {
            double sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }

    return result;
}

// Example program
int main() {
    // Create a matrix from a string
    Matrix* a = create_matrix("3 4\n1 2 3 4\n2 3 4 5");
    if (a == NULL) {
        printf("Error: failed to create matrix\n");
        return 1;
    }

    // Create another matrix from a string
    Matrix* b = create_matrix("4 5\n2 3 4 5\n1 2 3 4");
    if (b == NULL) {
        printf("Error: failed to create matrix\n");
        return 1;
    }

    // Perform matrix multiplication
    Matrix* result = multiply_matrices(a, b);
    if (result == NULL) {
        printf("Error: failed to perform matrix multiplication\n");
        return 1;
    }

    // Print the result matrix
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            printf("%.2f ", result->data[i * result->cols + j]);
        }
        printf("\n");
    }

    return 0;
}