//FormAI DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 10000
#define MAX_COLS 1000
#define MAX_NUMBERS 1000

typedef struct {
  int rows, cols;
  double data[MAX_ROWS][MAX_COLS];
} Matrix;

typedef struct {
  int n;
  double data[MAX_NUMBERS];
} Vector;

void matrix_multiply(const Matrix *a, const Matrix *b, Matrix *c)
{
  int i, j, k;

  for (i = 0; i < a->rows; i++) {
    for (j = 0; j < b->cols; j++) {
      double sum = 0;
      for (k = 0; k < a->cols; k++)
        sum += a->data[i][k] * b->data[k][j];
      c->data[i][j] = sum;
    }
  }
}

Vector *vector_from_matrix(const Matrix *a, int column)
{
  Vector *v = (Vector *) malloc(sizeof(Vector));
  int i;

  v->n = a->rows;
  for (i = 0; i < v->n; i++)
    v->data[i] = a->data[i][column];

  return v;
}

int main(int argc, char *argv[])
{
  Matrix a, b, c;
  Vector *v;
  FILE *f;

  if (argc != 3) {
    printf("Usage: %s A B\n", argv[0]);
    exit(1);
  }

  f = fopen(argv[1], "r");
  if (!f) {
    printf("Cannot open file %s\n", argv[1]);
    exit(1);
  }

  fscanf(f, "%d %d", &a.rows, &a.cols);
  if (a.rows > MAX_ROWS || a.cols > MAX_COLS) {
    printf("Matrix too large\n");
    fclose(f);
    exit(1);
  }

  int i, j;
  for (i = 0; i < a.rows; i++)
    for (j = 0; j < a.cols; j++)
      fscanf(f, "%lf", &a.data[i][j]);

  fclose(f);

  f = fopen(argv[2], "r");
  if (!f) {
    printf("Cannot open file %s\n", argv[2]);
    exit(1);
  }

  fscanf(f, "%d %d", &b.rows, &b.cols);
  if (b.rows > MAX_ROWS || b.cols > MAX_COLS) {
    printf("Matrix too large\n");
    fclose(f);
    exit(1);
  }

  for (i = 0; i < b.rows; i++)
    for (j = 0; j < b.cols; j++)
      fscanf(f, "%lf", &b.data[i][j]);

  fclose(f);

  if (a.cols != b.rows) {
    printf("Cannot multiply matrices of these sizes\n");
    exit(1);
  }

  c.rows = a.rows;
  c.cols = b.cols;

  matrix_multiply(&a, &b, &c);

  v = vector_from_matrix(&c, 0);

  for (i = 0; i < v->n; i++)
    printf("%.2f ", v->data[i]);
  printf("\n");

  free(v);

  return 0;
}