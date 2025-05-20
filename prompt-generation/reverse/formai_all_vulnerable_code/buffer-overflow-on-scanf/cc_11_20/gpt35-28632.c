//FormAI DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int rows, columns, i, j;
  printf("Enter the number of rows of the matrix: ");
  scanf("%d", &rows);
  printf("Enter the number of columns of the matrix: ");
  scanf("%d", &columns);

  int **matrix1 = malloc(rows * sizeof(int *));
  int **matrix2 = malloc(rows * sizeof(int *));
  int **result_matrix = malloc(rows * sizeof(int *));
  for(i=0; i<rows; i++){
      matrix1[i] = malloc(columns * sizeof(int));
      matrix2[i] = malloc(columns * sizeof(int));
      result_matrix[i] = malloc(columns * sizeof(int));
  }

  printf("\nEnter the elements of the first matrix:\n");
  for(i=0; i<rows; i++){
    for(j=0; j<columns; j++){
      scanf("%d", &matrix1[i][j]);
    }
  }

  printf("\nEnter the elements of the second matrix:\n");
  for(i=0; i<rows; i++){
    for(j=0; j<columns; j++){
      scanf("%d", &matrix2[i][j]);
    }
  }

  printf("\nMatrix 1:\n");
  for(i=0; i<rows; i++){
    for(j=0; j<columns; j++){
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix 2:\n");
  for(i=0; i<rows; i++){
    for(j=0; j<columns; j++){
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix Addition:\n");
  for(i=0; i<rows; i++){
    for(j=0; j<columns; j++){
      result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
      printf("%d ", result_matrix[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix Subtraction:\n");
  for(i=0; i<rows; i++){
    for(j=0; j<columns; j++){
      result_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
      printf("%d ", result_matrix[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix Multiplication:\n");
  for(i=0; i<rows; i++){
    for(j=0; j<columns; j++){
      result_matrix[i][j] = 0;
      for(int k=0; k<rows; k++){
        result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
      printf("%d ", result_matrix[i][j]);
    }
    printf("\n");
  }

  for(i=0; i<rows; i++){
      free(matrix1[i]);
      free(matrix2[i]);
      free(result_matrix[i]);
  }
  free(matrix1);
  free(matrix2);
  free(result_matrix);

  return 0;
}