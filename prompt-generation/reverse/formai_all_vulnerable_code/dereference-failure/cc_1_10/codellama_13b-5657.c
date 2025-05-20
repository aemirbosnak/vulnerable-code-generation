//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: optimized
// Matrix Operations Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Matrix Struct
typedef struct {
  int rows;
  int cols;
  double **data;
} Matrix;

// Matrix Creation Function
Matrix *createMatrix(int rows, int cols) {
  Matrix *m = malloc(sizeof(Matrix));
  m->rows = rows;
  m->cols = cols;
  m->data = malloc(rows * cols * sizeof(double));
  return m;
}

// Matrix Destruction Function
void destroyMatrix(Matrix *m) {
  free(m->data);
  free(m);
}

// Matrix Addition Function
Matrix *addMatrices(Matrix *a, Matrix *b) {
  Matrix *c = createMatrix(a->rows, a->cols);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      c->data[i][j] = a->data[i][j] + b->data[i][j];
    }
  }
  return c;
}

// Matrix Subtraction Function
Matrix *subtractMatrices(Matrix *a, Matrix *b) {
  Matrix *c = createMatrix(a->rows, a->cols);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      c->data[i][j] = a->data[i][j] - b->data[i][j];
    }
  }
  return c;
}

// Matrix Multiplication Function
Matrix *multiplyMatrices(Matrix *a, Matrix *b) {
  Matrix *c = createMatrix(a->rows, b->cols);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < b->cols; j++) {
      double sum = 0;
      for (int k = 0; k < a->cols; k++) {
        sum += a->data[i][k] * b->data[k][j];
      }
      c->data[i][j] = sum;
    }
  }
  return c;
}

// Matrix Transpose Function
Matrix *transposeMatrix(Matrix *a) {
  Matrix *b = createMatrix(a->cols, a->rows);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      b->data[j][i] = a->data[i][j];
    }
  }
  return b;
}

// Matrix Print Function
void printMatrix(Matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      printf("%lf ", m->data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Create Matrices
  Matrix *A = createMatrix(3, 3);
  Matrix *B = createMatrix(3, 3);
  Matrix *C = createMatrix(3, 3);
  Matrix *D = createMatrix(3, 3);
  Matrix *E = createMatrix(3, 3);
  Matrix *F = createMatrix(3, 3);

  // Initialize Matrices
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->cols; j++) {
      A->data[i][j] = i * A->cols + j;
      B->data[i][j] = (i + 1) * B->cols + j;
    }
  }

  // Perform Matrix Operations
  C = addMatrices(A, B);
  D = subtractMatrices(A, B);
  E = multiplyMatrices(A, B);
  F = transposeMatrix(A);

  // Print Matrices
  printf("A:\n");
  printMatrix(A);
  printf("B:\n");
  printMatrix(B);
  printf("C:\n");
  printMatrix(C);
  printf("D:\n");
  printMatrix(D);
  printf("E:\n");
  printMatrix(E);
  printf("F:\n");
  printMatrix(F);

  // Free Memory
  destroyMatrix(A);
  destroyMatrix(B);
  destroyMatrix(C);
  destroyMatrix(D);
  destroyMatrix(E);
  destroyMatrix(F);

  return 0;
}