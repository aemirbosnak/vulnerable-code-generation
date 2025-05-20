//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 5

typedef struct {
    int row;
    int col;
    double *data;
} Matrix;

Matrix *create_matrix(int row, int col) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->row = row;
    matrix->col = col;
    matrix->data = malloc(row * col * sizeof(double));
    return matrix;
}

void fill_matrix(Matrix *matrix, double value) {
    for (int i = 0; i < matrix->row; i++) {
        for (int j = 0; j < matrix->col; j++) {
            matrix->data[i * matrix->col + j] = value;
        }
    }
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->row; i++) {
        for (int j = 0; j < matrix->col; j++) {
            printf("%.2f ", matrix->data[i * matrix->col + j]);
        }
        printf("\n");
    }
}

void free_matrix(Matrix *matrix) {
    free(matrix->data);
    free(matrix);
}

Matrix *add_matrix(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->row != matrix2->row || matrix1->col != matrix2->col) {
        return NULL;
    }
    Matrix *result = create_matrix(matrix1->row, matrix1->col);
    for (int i = 0; i < matrix1->row; i++) {
        for (int j = 0; j < matrix1->col; j++) {
            result->data[i * matrix1->col + j] = matrix1->data[i * matrix1->col + j] + matrix2->data[i * matrix2->col + j];
        }
    }
    return result;
}

Matrix *multiply_matrix(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->col != matrix2->row) {
        return NULL;
    }
    Matrix *result = create_matrix(matrix1->row, matrix2->col);
    for (int i = 0; i < matrix1->row; i++) {
        for (int j = 0; j < matrix2->col; j++) {
            double sum = 0;
            for (int k = 0; k < matrix1->col; k++) {
                sum += matrix1->data[i * matrix1->col + k] * matrix2->data[k * matrix2->col + j];
            }
            result->data[i * result->col + j] = sum;
        }
    }
    return result;
}

int main() {
    srand(time(NULL));

    Matrix *matrix1 = create_matrix(MATRIX_SIZE, MATRIX_SIZE);
    fill_matrix(matrix1, 1.0);
    print_matrix(matrix1);

    Matrix *matrix2 = create_matrix(MATRIX_SIZE, MATRIX_SIZE);
    fill_matrix(matrix2, 2.0);
    print_matrix(matrix2);

    Matrix *result = add_matrix(matrix1, matrix2);
    if (result != NULL) {
        print_matrix(result);
    }

    Matrix *result2 = multiply_matrix(matrix1, matrix2);
    if (result2 != NULL) {
        print_matrix(result2);
    }

    free_matrix(matrix1);
    free_matrix(matrix2);
    free_matrix(result);
    free_matrix(result2);

    return 0;
}