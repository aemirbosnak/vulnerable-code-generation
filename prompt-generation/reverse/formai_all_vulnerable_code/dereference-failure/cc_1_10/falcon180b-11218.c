//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    int **mat;
} Matrix;

Matrix *matrix_create(int rows, int cols) {
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->mat[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}

void matrix_destroy(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->mat[i]);
    }
    free(mat->mat);
    free(mat);
}

void matrix_print(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
}

Matrix *matrix_add(Matrix *mat1, Matrix *mat2) {
    Matrix *res = matrix_create(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            res->mat[i][j] = mat1->mat[i][j] + mat2->mat[i][j];
        }
    }
    return res;
}

Matrix *matrix_subtract(Matrix *mat1, Matrix *mat2) {
    Matrix *res = matrix_create(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            res->mat[i][j] = mat1->mat[i][j] - mat2->mat[i][j];
        }
    }
    return res;
}

Matrix *matrix_multiply(Matrix *mat1, Matrix *mat2) {
    Matrix *res = matrix_create(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            res->mat[i][j] = 0;
            for (int k = 0; k < mat1->cols; k++) {
                res->mat[i][j] += mat1->mat[i][k] * mat2->mat[k][j];
            }
        }
    }
    return res;
}

int main() {
    Matrix *mat1 = matrix_create(3, 3);
    Matrix *mat2 = matrix_create(3, 3);
    Matrix *res;

    matrix_print(mat1);
    matrix_print(mat2);

    res = matrix_add(mat1, mat2);
    matrix_print(res);

    res = matrix_subtract(mat1, mat2);
    matrix_print(res);

    res = matrix_multiply(mat1, mat2);
    matrix_print(res);

    matrix_destroy(mat1);
    matrix_destroy(mat2);
    matrix_destroy(res);

    return 0;
}