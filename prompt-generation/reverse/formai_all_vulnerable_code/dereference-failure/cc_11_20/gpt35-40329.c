//FormAI DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

int main() {
  int rows, cols;
  printf("Enter the number of rows in the matrix: ");
  scanf("%d", &rows);
  printf("Enter the number of columns in the matrix: ");
  scanf("%d", &cols);

  int **matrix;
  matrix = (int **)malloc(rows * sizeof(int *));
  for(int i = 0; i < rows; i++) {
      matrix[i] = (int *)malloc(cols *sizeof(int));
  }

  // initializing matrix
  for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
          printf("Enter the element at matrix[%d][%d]: ", i, j);
          scanf("%d", &matrix[i][j]);
      }
  }

  // printing matrix
  printf("The matrix you entered is:\n");
  for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
          printf("%d\t", matrix[i][j]);
      }
      printf("\n");
  }

  // calculation of sum of elements
  int sum = 0;
  for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
          sum += matrix[i][j];
      }
  }
  printf("The sum of all the elements of the matrix is: %d\n", sum);
  
  // calculation of transpose of matrix
  int **transpose;
  transpose = (int **)malloc(cols * sizeof(int *));
  for(int i = 0; i < cols; i++) {
      transpose[i] = (int *)malloc(rows * sizeof(int));
  }

  for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
          transpose[j][i] = matrix[i][j];
      }
  }
  
  // printing transpose of matrix
  printf("The transpose of the matrix is:\n");
  for(int i=0; i<cols; i++){
      for(int j=0; j<rows; j++){
          printf("%d\t", transpose[i][j]);
      }
      printf("\n");
  }

  // deallocation of memory
  for(int i = 0; i < rows; i++) {
      free(matrix[i]);
  }
  free(matrix);

  for(int i = 0; i < cols; i++) {
      free(transpose[i]);
  }
  free(transpose);

  return 0;
}