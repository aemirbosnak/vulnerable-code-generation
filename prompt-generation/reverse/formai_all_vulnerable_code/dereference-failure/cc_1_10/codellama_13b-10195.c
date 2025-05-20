//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAT_SIZE 3

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *createMatrix(int rows, int cols) {
    Matrix *mat = malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(sizeof(int) * cols);
    }
    return mat;
}

void printMatrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

Matrix *addMatrix(Matrix *mat1, Matrix *mat2) {
    Matrix *result = createMatrix(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

Matrix *subtractMatrix(Matrix *mat1, Matrix *mat2) {
    Matrix *result = createMatrix(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
        }
    }
    return result;
}

Matrix *multiplyMatrix(Matrix *mat1, Matrix *mat2) {
    Matrix *result = createMatrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

int main() {
    Matrix *mat1 = createMatrix(MAT_SIZE, MAT_SIZE);
    Matrix *mat2 = createMatrix(MAT_SIZE, MAT_SIZE);

    // Initialize matrices with random values
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            mat1->data[i][j] = rand() % 10;
            mat2->data[i][j] = rand() % 10;
        }
    }

    // Perform matrix operations
    Matrix *result = addMatrix(mat1, mat2);
    printMatrix(result);
    freeMatrix(result);

    result = subtractMatrix(mat1, mat2);
    printMatrix(result);
    freeMatrix(result);

    result = multiplyMatrix(mat1, mat2);
    printMatrix(result);
    freeMatrix(result);

    freeMatrix(mat1);
    freeMatrix(mat2);

    return 0;
}