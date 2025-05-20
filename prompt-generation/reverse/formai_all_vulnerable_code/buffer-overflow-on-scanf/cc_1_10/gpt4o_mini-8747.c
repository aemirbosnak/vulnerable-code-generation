//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int rows;
    int cols;
    float data[MAX_SIZE][MAX_SIZE];
} Matrix;

// Function to create a new matrix with given rows and columns
Matrix create_matrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    return mat;
}

// Function to read a matrix from user input
void read_matrix(Matrix *mat) {
    printf("Enter the elements of the matrix (%d x %d):\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%f", &mat->data[i][j]);
        }
    }
}

// Function to display a matrix
void display_matrix(const Matrix *mat) {
    printf("Matrix (%d x %d):\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%.2f ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix add_matrices(const Matrix *a, const Matrix *b) {
    Matrix result = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
Matrix subtract_matrices(const Matrix *a, const Matrix *b) {
    Matrix result = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix multiply_matrices(const Matrix *a, const Matrix *b) {
    if (a->cols != b->rows) {
        fprintf(stderr, "Error: Incompatible matrix dimensions for multiplication!\n");
        exit(EXIT_FAILURE);
    }
    
    Matrix result = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix transpose_matrix(const Matrix *mat) {
    Matrix result = create_matrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result.data[j][i] = mat->data[i][j];
        }
    }
    return result;
}

int main() {
    Matrix A = create_matrix(0, 0);
    Matrix B = create_matrix(0, 0);

    printf("Enter dimensions for Matrix A (rows cols): ");
    scanf("%d %d", &A.rows, &A.cols);
    A = create_matrix(A.rows, A.cols);
    read_matrix(&A);
    display_matrix(&A);

    printf("Enter dimensions for Matrix B (rows cols): ");
    scanf("%d %d", &B.rows, &B.cols);
    B = create_matrix(B.rows, B.cols);
    read_matrix(&B);
    display_matrix(&B);

    if (A.rows == B.rows && A.cols == B.cols) {
        Matrix C_add = add_matrices(&A, &B);
        printf("\nMatrix A + Matrix B:\n");
        display_matrix(&C_add);

        Matrix C_sub = subtract_matrices(&A, &B);
        printf("\nMatrix A - Matrix B:\n");
        display_matrix(&C_sub);
    } else {
        printf("\nMatrix addition/subtraction is not possible due to dimension mismatch.\n");
    }

    if (A.cols == B.rows) {
        Matrix C_mul = multiply_matrices(&A, &B);
        printf("\nMatrix A * Matrix B:\n");
        display_matrix(&C_mul);
    } else {
        printf("\nMatrix multiplication is not possible due to dimension mismatch.\n");
    }

    Matrix C_transpose = transpose_matrix(&A);
    printf("\nTranspose of Matrix A:\n");
    display_matrix(&C_transpose);

    return 0;
}