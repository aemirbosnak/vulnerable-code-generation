//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Matrix struct
typedef struct {
  int rows;
  int cols;
  int **data;
} Matrix;

// Matrix operations
Matrix *matrix_create(int rows, int cols) {
  Matrix *m = malloc(sizeof(Matrix));
  m->rows = rows;
  m->cols = cols;
  m->data = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    m->data[i] = malloc(cols * sizeof(int));
  }
  return m;
}

void matrix_destroy(Matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    free(m->data[i]);
  }
  free(m->data);
  free(m);
}

void matrix_print(Matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      printf("%d ", m->data[i][j]);
    }
    printf("\n");
  }
}

Matrix *matrix_add(Matrix *m1, Matrix *m2) {
  if (m1->rows != m2->rows || m1->cols != m2->cols) {
    printf("Cannot add matrices of different sizes\n");
    return NULL;
  }
  Matrix *m3 = matrix_create(m1->rows, m1->cols);
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->cols; j++) {
      m3->data[i][j] = m1->data[i][j] + m2->data[i][j];
    }
  }
  return m3;
}

int main() {
  Matrix *m1 = matrix_create(2, 2);
  m1->data[0][0] = 1;
  m1->data[0][1] = 2;
  m1->data[1][0] = 3;
  m1->data[1][1] = 4;

  Matrix *m2 = matrix_create(2, 2);
  m2->data[0][0] = 5;
  m2->data[0][1] = 6;
  m2->data[1][0] = 7;
  m2->data[1][1] = 8;

  Matrix *m3 = matrix_add(m1, m2);
  matrix_print(m3);
  matrix_destroy(m1);
  matrix_destroy(m2);
  matrix_destroy(m3);
  return 0;
}