//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int *data;
    int rows;
    int cols;
} Matrix;

void rand_matrix(Matrix *mat) {
    srand(time(NULL));
    mat->data = (int *)malloc(mat->rows * mat->cols * sizeof(int));
    for(int i=0; i<mat->rows; i++) {
        for(int j=0; j<mat->cols; j++) {
            mat->data[i*mat->cols+j] = rand() % 100;
        }
    }
}

void print_matrix(Matrix *mat) {
    for(int i=0; i<mat->rows; i++) {
        for(int j=0; j<mat->cols; j++) {
            printf("%d ", mat->data[i*mat->cols+j]);
        }
        printf("\n");
    }
}

void transpose_matrix(Matrix *mat) {
    int *temp = (int *)malloc(mat->rows * mat->cols * sizeof(int));
    for(int i=0; i<mat->rows; i++) {
        for(int j=0; j<mat->cols; j++) {
            temp[(j)*mat->rows+(i)] = mat->data[i*mat->cols+j];
        }
    }
    free(mat->data);
    mat->data = temp;
    int temp_cols = mat->rows;
    mat->rows = mat->cols;
    mat->cols = temp_cols;
}

void matrix_multiply(Matrix *mat1, Matrix *mat2, Matrix *result) {
    result->rows = mat1->rows;
    result->cols = mat2->cols;
    result->data = (int *)malloc(result->rows * result->cols * sizeof(int));
    for(int i=0; i<result->rows; i++) {
        for(int j=0; j<result->cols; j++) {
            result->data[i*result->cols+j] = 0;
            for(int k=0; k<mat1->cols; k++) {
                result->data[i*result->cols+j] += mat1->data[i*mat1->cols+k] * mat2->data[k*mat2->cols+j];
            }
        }
    }
}

void main() {
    Matrix mat1, mat2, result;
    rand_matrix(&mat1);
    rand_matrix(&mat2);
    if(mat1.cols!= mat2.rows) {
        printf("Cannot multiply matrices!\n");
        return;
    }
    matrix_multiply(&mat1, &mat2, &result);
    printf("Result:\n");
    print_matrix(&result);
}