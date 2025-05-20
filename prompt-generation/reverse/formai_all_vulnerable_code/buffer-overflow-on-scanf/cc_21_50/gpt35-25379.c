//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int row, column;
  printf("Welcome to the Matrix Operations Calculator!\n");
  printf("Please enter the number of rows and columns for your matrix:\n");
  scanf("%d %d", &row, &column);

  int **matrix = (int **)malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++)
  {
    matrix[i] = (int *)malloc(column * sizeof(int));
  }

  printf("Please enter the elements of your matrix:\n");

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("\nYour matrix:\n");
  for (int i = 0; i < row; i++)
  {
    printf("| ");
    for (int j = 0; j < column; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("|\n");
  }

  printf("\nNow, choose an operation:\n");
  printf("1. Transpose\n");
  printf("2. Multiply by scalar\n");
  printf("3. Add to another matrix\n");
  printf("4. Exit\n");

  int choice;
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("\nTranspose of your matrix:\n");
      for (int i = 0; i < column; i++)
      {
        printf("| ");
        for (int j = 0; j < row; j++)
        {
          printf("%d ", matrix[j][i]);
        }
        printf("|\n");
      }
      break;
    case 2:
      printf("\nEnter a scalar to multiply your matrix with: ");
      int scalar;
      scanf("%d", &scalar);

      printf("\nResult of multiplying your matrix by %d:\n", scalar);
      for (int i = 0; i < row; i++)
      {
        printf("| ");
        for (int j = 0; j < column; j++)
        {
          printf("%d ", matrix[i][j] * scalar);
        }
        printf("|\n");
      }
      break;
    case 3:
      printf("\nPlease enter another matrix with %d rows and %d columns:\n", row, column);

      int **matrix2 = (int **)malloc(row * sizeof(int *));
      for (int i = 0; i < row; i++)
      {
        matrix2[i] = (int *)malloc(column * sizeof(int));
      }

      printf("Please enter the elements of your second matrix:\n");

      for (int i = 0; i < row; i++)
      {
        for (int j = 0; j < column; j++)
        {
          printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
          scanf("%d", &matrix2[i][j]);
        }
      }

      printf("\nYour second matrix:\n");
      for (int i = 0; i < row; i++)
      {
        printf("| ");
        for (int j = 0; j < column; j++)
        {
          printf("%d ", matrix2[i][j]);
        }
        printf("|\n");
      }

      printf("\nResult of adding your two matrices:\n");
      for (int i = 0; i < row; i++)
      {
        printf("| ");
        for (int j = 0; j < column; j++)
        {
          printf("%d ", matrix[i][j] + matrix2[i][j]);
        }
        printf("|\n");
      }
      break;
    case 4:
      printf("\nGoodbye!\n");
      break;
    default:
      printf("\nInvalid choice! Please choose a number from 1 to 4.\n");
      break;
  }

  for (int i = 0; i < row; i++)
  {
    free(matrix[i]);
  }

  free(matrix);

  return 0;
}