//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
// Matrix Operations Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_DIM 100

typedef struct {
  int rows;
  int cols;
  int** data;
} Matrix;

void matrix_init(Matrix* mat, int rows, int cols) {
  mat->rows = rows;
  mat->cols = cols;
  mat->data = malloc(sizeof(int*) * rows);
  for (int i = 0; i < rows; i++) {
    mat->data[i] = malloc(sizeof(int) * cols);
  }
}

void matrix_print(Matrix* mat) {
  for (int i = 0; i < mat->rows; i++) {
    for (int j = 0; j < mat->cols; j++) {
      printf("%d ", mat->data[i][j]);
    }
    printf("\n");
  }
}

void matrix_free(Matrix* mat) {
  for (int i = 0; i < mat->rows; i++) {
    free(mat->data[i]);
  }
  free(mat->data);
}

Matrix* matrix_add(Matrix* mat1, Matrix* mat2) {
  if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
    return NULL;
  }
  Matrix* result = malloc(sizeof(Matrix));
  matrix_init(result, mat1->rows, mat1->cols);
  for (int i = 0; i < mat1->rows; i++) {
    for (int j = 0; j < mat1->cols; j++) {
      result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
    }
  }
  return result;
}

Matrix* matrix_sub(Matrix* mat1, Matrix* mat2) {
  if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
    return NULL;
  }
  Matrix* result = malloc(sizeof(Matrix));
  matrix_init(result, mat1->rows, mat1->cols);
  for (int i = 0; i < mat1->rows; i++) {
    for (int j = 0; j < mat1->cols; j++) {
      result->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
    }
  }
  return result;
}

Matrix* matrix_mul(Matrix* mat1, Matrix* mat2) {
  if (mat1->cols != mat2->rows) {
    return NULL;
  }
  Matrix* result = malloc(sizeof(Matrix));
  matrix_init(result, mat1->rows, mat2->cols);
  for (int i = 0; i < mat1->rows; i++) {
    for (int j = 0; j < mat2->cols; j++) {
      for (int k = 0; k < mat1->cols; k++) {
        result->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
      }
    }
  }
  return result;
}

Matrix* matrix_pow(Matrix* mat, int power) {
  Matrix* result = malloc(sizeof(Matrix));
  matrix_init(result, mat->rows, mat->cols);
  for (int i = 0; i < mat->rows; i++) {
    for (int j = 0; j < mat->cols; j++) {
      result->data[i][j] = pow(mat->data[i][j], power);
    }
  }
  return result;
}

int main() {
  Matrix* mat1 = malloc(sizeof(Matrix));
  matrix_init(mat1, 2, 2);
  mat1->data[0][0] = 1;
  mat1->data[0][1] = 2;
  mat1->data[1][0] = 3;
  mat1->data[1][1] = 4;

  Matrix* mat2 = malloc(sizeof(Matrix));
  matrix_init(mat2, 2, 2);
  mat2->data[0][0] = 5;
  mat2->data[0][1] = 6;
  mat2->data[1][0] = 7;
  mat2->data[1][1] = 8;

  Matrix* result = matrix_add(mat1, mat2);
  matrix_print(result);
  matrix_free(result);

  result = matrix_sub(mat1, mat2);
  matrix_print(result);
  matrix_free(result);

  result = matrix_mul(mat1, mat2);
  matrix_print(result);
  matrix_free(result);

  result = matrix_pow(mat1, 2);
  matrix_print(result);
  matrix_free(result);

  matrix_free(mat1);
  matrix_free(mat2);
  return 0;
}