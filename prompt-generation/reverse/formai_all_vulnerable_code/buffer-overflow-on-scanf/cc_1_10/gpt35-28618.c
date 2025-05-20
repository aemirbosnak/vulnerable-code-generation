//FormAI DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>

/* Declare matrix dimensions */
#define ROWS 3
#define COLS 3

/* Declare functions for matrix operations */
void add_matrices(int m1[][COLS], int m2[][COLS], int result[][COLS]);
void subtract_matrices(int m1[][COLS], int m2[][COLS], int result[][COLS]);
void multiply_matrices(int m1[][COLS], int m2[][COLS], int result[][COLS]);
void print_matrix(int matrix[][COLS]);

/* Main Function */
int main()
{
  /* Initialize matrices */
  int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result[ROWS][COLS];

  /* Input elements of matrix1 */
  printf("Enter elements of matrix1\n");
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      scanf("%d", &matrix1[i][j]);
    }
  }

  /* Input elements of matrix2 */
  printf("Enter elements of matrix2\n");
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      scanf("%d", &matrix2[i][j]);
    }
  }

  /* Add matrices */
  add_matrices(matrix1, matrix2, result);
  printf("Matrix1 + Matrix2 = \n");
  print_matrix(result);

  /* Subtract matrices */
  subtract_matrices(matrix1, matrix2, result);
  printf("Matrix1 - Matrix2 = \n");
  print_matrix(result);

  /* Multiply matrices */
  multiply_matrices(matrix1, matrix2, result);
  printf("Matrix1 * Matrix2 = \n");
  print_matrix(result);

  return 0;
}

/* Function to add two matrices */
void add_matrices(int m1[][COLS], int m2[][COLS], int result[][COLS])
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      result[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

/* Function to subtract two matrices */
void subtract_matrices(int m1[][COLS], int m2[][COLS], int result[][COLS])
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      result[i][j] = m1[i][j] - m2[i][j];
    }
  }
}

/* Function to multiply two matrices */
void multiply_matrices(int m1[][COLS], int m2[][COLS], int result[][COLS])
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < COLS; k++)
      {
        result[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}

/* Function to print the matrix */
void print_matrix(int matrix[][COLS])
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}