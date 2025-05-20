//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void print_matrix(int *m, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", m[i * n + j]);
    }
    printf("\n");
  }
}

int *create_matrix(int n) {
  int *m = malloc(sizeof(int) * n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      m[i * n + j] = rand() % 100;
    }
  }
  return m;
}

int *matrix_transpose(int *m, int n) {
  int *t = malloc(sizeof(int) * n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      t[i * n + j] = m[j * n + i];
    }
  }
  return t;
}

int *matrix_multiply(int *m1, int *m2, int n) {
  int *p = malloc(sizeof(int) * n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int sum = 0;
      for (int k = 0; k < n; k++) {
        sum += m1[i * n + k] * m2[k * n + j];
      }
      p[i * n + j] = sum;
    }
  }
  return p;
}

int main() {
  srand(time(NULL));
  int *m1 = create_matrix(N);
  int *m2 = create_matrix(N);
  print_matrix(m1, N);
  printf("Transpose of matrix 1:\n");
  print_matrix(matrix_transpose(m1, N), N);
  printf("Matrix 1 x Matrix 2:\n");
  print_matrix(matrix_multiply(m1, m2, N), N);
  free(m1);
  free(m2);
  return 0;
}