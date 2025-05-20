//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    #define MATRIX_SIZE 3

    typedef struct {
        int rows;
        int cols;
        int** data;
    } Matrix;

    Matrix* create_matrix(int rows, int cols) {
        Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
        matrix->rows = rows;
        matrix->cols = cols;
        matrix->data = (int**)malloc(rows * sizeof(int*));
        for (int i = 0; i < rows; i++) {
            matrix->data[i] = (int*)malloc(cols * sizeof(int));
        }
        return matrix;
    }

    void print_matrix(Matrix* matrix) {
        for (int i = 0; i < matrix->rows; i++) {
            for (int j = 0; j < matrix->cols; j++) {
                printf("%d ", matrix->data[i][j]);
            }
            printf("\n");
        }
    }

    void set_matrix_element(Matrix* matrix, int row, int col, int value) {
        matrix->data[row][col] = value;
    }

    int get_matrix_element(Matrix* matrix, int row, int col) {
        return matrix->data[row][col];
    }

    Matrix* add_matrices(Matrix* matrix1, Matrix* matrix2) {
        if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
            return NULL;
        }

        Matrix* result = create_matrix(matrix1->rows, matrix1->cols);
        for (int i = 0; i < matrix1->rows; i++) {
            for (int j = 0; j < matrix1->cols; j++) {
                result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
            }
        }
        return result;
    }

    Matrix* multiply_matrices(Matrix* matrix1, Matrix* matrix2) {
        if (matrix1->cols != matrix2->rows) {
            return NULL;
        }

        Matrix* result = create_matrix(matrix1->rows, matrix2->cols);
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

    Matrix* transpose_matrix(Matrix* matrix) {
        Matrix* result = create_matrix(matrix->cols, matrix->rows);
        for (int i = 0; i < matrix->rows; i++) {
            for (int j = 0; j < matrix->cols; j++) {
                result->data[j][i] = matrix->data[i][j];
            }
        }
        return result;
    }

    void free_matrix(Matrix* matrix) {
        for (int i = 0; i < matrix->rows; i++) {
            free(matrix->data[i]);
        }
        free(matrix->data);
        free(matrix);
    }

    int main() {
        srand(time(NULL));

        Matrix* matrix1 = create_matrix(3, 3);
        Matrix* matrix2 = create_matrix(3, 3);

        for (int i = 0; i < matrix1->rows; i++) {
            for (int j = 0; j < matrix1->cols; j++) {
                set_matrix_element(matrix1, i, j, rand() % 10);
                set_matrix_element(matrix2, i, j, rand() % 10);
            }
        }

        Matrix* result1 = add_matrices(matrix1, matrix2);
        Matrix* result2 = multiply_matrices(matrix1, matrix2);
        Matrix* result3 = transpose_matrix(matrix1);

        print_matrix(result1);
        print_matrix(result2);
        print_matrix(result3);

        free_matrix(matrix1);
        free_matrix(matrix2);
        free_matrix(result1);
        free_matrix(result2);
        free_matrix(result3);

        return 0;
    }