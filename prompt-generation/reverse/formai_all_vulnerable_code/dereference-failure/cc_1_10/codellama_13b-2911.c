//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: light-weight
void print_matrix(int rows, int cols, int mat[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}

void transpose_matrix(int rows, int cols, int mat[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int temp = mat[i][j];
      mat[i][j] = mat[j][i];
      mat[j][i] = temp;
    }
  }
}

void sum_matrix(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
}

void sub_matrix(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = mat1[i][j] - mat2[i][j];
    }
  }
}

void mul_matrix(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = 0;
      for (int k = 0; k < cols; k++) {
        result[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
}

int main() {
  int mat1[2][2] = {{1, 2}, {3, 4}};
  int mat2[2][2] = {{5, 6}, {7, 8}};
  int result[2][2];

  print_matrix(2, 2, mat1);
  printf("\n");
  print_matrix(2, 2, mat2);
  printf("\n");

  transpose_matrix(2, 2, mat1);
  printf("\n");
  print_matrix(2, 2, mat1);
  printf("\n");

  sum_matrix(2, 2, mat1, mat2, result);
  printf("\n");
  print_matrix(2, 2, result);
  printf("\n");

  sub_matrix(2, 2, mat1, mat2, result);
  printf("\n");
  print_matrix(2, 2, result);
  printf("\n");

  mul_matrix(2, 2, mat1, mat2, result);
  printf("\n");
  print_matrix(2, 2, result);
  printf("\n");

  return 0;
}