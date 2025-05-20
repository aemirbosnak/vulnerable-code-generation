//FormAI DATASET v1.0 Category: Matrix operations ; Style: curious
#include <stdio.h>

int main() {
  int num_rows, num_cols;
  printf("Welcome to the Matrix Operations Calculator\n");
  printf("Please enter the number of rows in your matrix:\n");
  scanf("%d", &num_rows);
  printf("Please enter the number of columns in your matrix:\n");
  scanf("%d", &num_cols);

  int matrix[num_rows][num_cols];

  printf("Great, now let's fill up your matrix with some numbers:\n");

  // Populate matrix with user input
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      printf("Enter a value for matrix[%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }

  // Display original matrix
  printf("Here is your original matrix:\n");
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Calculate the transpose of the matrix
  int transposed_matrix[num_cols][num_rows];
  for (int i = 0; i < num_cols; i++) {
    for (int j = 0; j < num_rows; j++) {
      transposed_matrix[i][j] = matrix[j][i];
    }
  }

  // Display transposed matrix
  printf("Here is the transpose of your matrix:\n");
  for (int i = 0; i < num_cols; i++) {
    for (int j = 0; j < num_rows; j++) {
      printf("%d ", transposed_matrix[i][j]);
    }
    printf("\n");
  }

  // Calculate the determinant of the matrix
  if (num_rows != 3 || num_cols != 3) {
    printf("Sorry, we can only calculate the determinant of a 3x3 matrix.");
  } else {
    int determinant =
        matrix[0][0] * matrix[1][1] * matrix[2][2] +
        matrix[0][1] * matrix[1][2] * matrix[2][0] +
        matrix[0][2] * matrix[1][0] * matrix[2][1] -
        matrix[0][0] * matrix[1][2] * matrix[2][1] -
        matrix[0][1] * matrix[1][0] * matrix[2][2] -
        matrix[0][2] * matrix[1][1] * matrix[2][0];
    printf("The determinant of your matrix is: %d", determinant);
  }

  return 0;
}