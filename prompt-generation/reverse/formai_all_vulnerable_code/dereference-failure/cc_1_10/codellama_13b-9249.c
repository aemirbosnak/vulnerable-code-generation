//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 100

typedef struct {
  int rows;
  int cols;
  double *data;
} Matrix;

void print_matrix(Matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      printf("%f ", m->data[i * m->cols + j]);
    }
    printf("\n");
  }
}

Matrix *create_matrix(int rows, int cols) {
  Matrix *m = malloc(sizeof(Matrix));
  m->rows = rows;
  m->cols = cols;
  m->data = malloc(rows * cols * sizeof(double));
  return m;
}

void free_matrix(Matrix *m) {
  free(m->data);
  free(m);
}

void matrix_add(Matrix *m1, Matrix *m2, Matrix *res) {
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->cols; j++) {
      res->data[i * res->cols + j] = m1->data[i * m1->cols + j] + m2->data[i * m2->cols + j];
    }
  }
}

void matrix_multiply(Matrix *m1, Matrix *m2, Matrix *res) {
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m2->cols; j++) {
      double sum = 0;
      for (int k = 0; k < m1->cols; k++) {
        sum += m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j];
      }
      res->data[i * res->cols + j] = sum;
    }
  }
}

void matrix_transpose(Matrix *m, Matrix *res) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      res->data[j * res->cols + i] = m->data[i * m->cols + j];
    }
  }
}

int main() {
  Matrix *m1 = create_matrix(3, 3);
  Matrix *m2 = create_matrix(3, 3);
  Matrix *res = create_matrix(3, 3);

  m1->data[0] = 1;
  m1->data[1] = 2;
  m1->data[2] = 3;
  m1->data[3] = 4;
  m1->data[4] = 5;
  m1->data[5] = 6;
  m1->data[6] = 7;
  m1->data[7] = 8;
  m1->data[8] = 9;

  m2->data[0] = 1;
  m2->data[1] = 2;
  m2->data[2] = 3;
  m2->data[3] = 4;
  m2->data[4] = 5;
  m2->data[5] = 6;
  m2->data[6] = 7;
  m2->data[7] = 8;
  m2->data[8] = 9;

  matrix_add(m1, m2, res);
  print_matrix(res);

  matrix_multiply(m1, m2, res);
  print_matrix(res);

  matrix_transpose(m1, res);
  print_matrix(res);

  free_matrix(m1);
  free_matrix(m2);
  free_matrix(res);

  return 0;
}