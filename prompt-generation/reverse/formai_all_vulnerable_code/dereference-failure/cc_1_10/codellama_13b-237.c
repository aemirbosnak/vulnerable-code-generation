//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
/*
 * Matrix operations example program in the style of Donald Knuth
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROWS 3
#define MATRIX_COLS 3

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

void print_matrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(Matrix* mat1, Matrix* mat2, Matrix* result) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
}

void matrix_sub(Matrix* mat1, Matrix* mat2, Matrix* result) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
        }
    }
}

void matrix_mul(Matrix* mat1, Matrix* mat2, Matrix* result) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            for (int k = 0; k < mat1->cols; k++) {
                result->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }
}

int main() {
    Matrix mat1 = {MATRIX_ROWS, MATRIX_COLS, (int**)malloc(MATRIX_ROWS * sizeof(int*))};
    Matrix mat2 = {MATRIX_ROWS, MATRIX_COLS, (int**)malloc(MATRIX_ROWS * sizeof(int*))};
    Matrix result = {MATRIX_ROWS, MATRIX_COLS, (int**)malloc(MATRIX_ROWS * sizeof(int*))};

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            mat1.data[i][j] = i * j;
            mat2.data[i][j] = i - j;
        }
    }

    print_matrix(&mat1);
    print_matrix(&mat2);

    matrix_add(&mat1, &mat2, &result);
    printf("Matrix Addition:\n");
    print_matrix(&result);

    matrix_sub(&mat1, &mat2, &result);
    printf("Matrix Subtraction:\n");
    print_matrix(&result);

    matrix_mul(&mat1, &mat2, &result);
    printf("Matrix Multiplication:\n");
    print_matrix(&result);

    free(mat1.data);
    free(mat2.data);
    free(result.data);

    return 0;
}