//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *) malloc(cols * sizeof(int));
    }
    return matrix;
}

void destroy_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *add_matrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix *result = create_matrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

Matrix *subtract_matrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix *result = create_matrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }
    return result;
}

Matrix *multiply_matrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix *result = create_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < matrix2->rows; k++) {
                sum += matrix1->data[i][k] * matrix2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

int main() {
    Matrix *matrix1 = create_matrix(3, 3);
    Matrix *matrix2 = create_matrix(3, 3);
    Matrix *result;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix1->data[i][j] = i + j;
            matrix2->data[i][j] = i - j;
        }
    }

    result = add_matrices(matrix1, matrix2);
    printf("Addition:\n");
    print_matrix(result);

    result = subtract_matrices(matrix1, matrix2);
    printf("Subtraction:\n");
    print_matrix(result);

    result = multiply_matrices(matrix1, matrix2);
    printf("Multiplication:\n");
    print_matrix(result);

    destroy_matrix(matrix1);
    destroy_matrix(matrix2);
    destroy_matrix(result);

    return 0;
}