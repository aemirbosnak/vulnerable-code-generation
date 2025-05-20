//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
  #include <stdlib.h>
  #include <math.h>

  #define MATRIX_SIZE 10

  typedef struct {
    int rows;
    int cols;
    double **data;
  } Matrix;

  Matrix* create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * cols * sizeof(double));
    return matrix;
  }

  void destroy_matrix(Matrix *matrix) {
    free(matrix->data);
    free(matrix);
  }

  void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
      for (int j = 0; j < matrix->cols; j++) {
        printf("%f ", matrix->data[i][j]);
      }
      printf("\n");
    }
  }

  void add_matrix(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
      printf("Matrices must be of the same size to add them.");
      return;
    }
    for (int i = 0; i < matrix1->rows; i++) {
      for (int j = 0; j < matrix1->cols; j++) {
        matrix1->data[i][j] += matrix2->data[i][j];
      }
    }
  }

  void multiply_matrix(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->cols != matrix2->rows) {
      printf("Matrices cannot be multiplied.");
      return;
    }
    Matrix *result = create_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->cols; j++) {
        double sum = 0;
        for (int k = 0; k < matrix1->cols; k++) {
          sum += matrix1->data[i][k] * matrix2->data[k][j];
        }
        result->data[i][j] = sum;
      }
    }
    destroy_matrix(matrix1);
    destroy_matrix(matrix2);
    matrix1 = result;
  }

  int main() {
    Matrix *matrix1 = create_matrix(3, 3);
    Matrix *matrix2 = create_matrix(3, 3);
    Matrix *matrix3 = create_matrix(3, 3);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        matrix1->data[i][j] = i + j;
        matrix2->data[i][j] = 2 * i + j;
      }
    }
    print_matrix(matrix1);
    print_matrix(matrix2);
    add_matrix(matrix1, matrix2);
    print_matrix(matrix1);
    multiply_matrix(matrix1, matrix2);
    print_matrix(matrix1);
    destroy_matrix(matrix1);
    destroy_matrix(matrix2);
    destroy_matrix(matrix3);
    return 0;
  }