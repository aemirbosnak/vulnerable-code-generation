//FormAI DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// function prototypes
int **allocate_matrix(int rows, int cols);
void populate_matrix(int **matrix, int rows, int cols);
void display_matrix(int **matrix, int rows, int cols);
void multiply_matrices(int **matrix1, int **matrix2, int rows1, int cols1, int cols2);

int main()
{
    printf("Welcome to the Matrix Operations Program!\n\n");

    // declare variables
    int rows1, cols1, rows2, cols2;
    int **matrix1, **matrix2;

    // get matrix1 dimensions from user
    printf("Please enter the number of rows in matrix 1: ");
    scanf("%d", &rows1);
    printf("Please enter the number of columns in matrix 1: ");
    scanf("%d", &cols1);

    // allocate and populate matrix1
    matrix1 = allocate_matrix(rows1, cols1);
    printf("\nPlease enter the elements of matrix 1:\n");
    populate_matrix(matrix1, rows1, cols1);
    printf("\nMatrix 1:\n");
    display_matrix(matrix1, rows1, cols1);

    // get matrix2 dimensions from user
    printf("\nPlease enter the number of rows in matrix 2: ");
    scanf("%d", &rows2);
    printf("Please enter the number of columns in matrix 2: ");
    scanf("%d", &cols2);

    // allocate and populate matrix2
    matrix2 = allocate_matrix(rows2, cols2);
    printf("\nPlease enter the elements of matrix 2:\n");
    populate_matrix(matrix2, rows2, cols2);
    printf("\nMatrix 2:\n");
    display_matrix(matrix2, rows2, cols2);

    // multiply matrices and display result
    printf("\nMatrix 1 multiplied by matrix 2:\n");
    multiply_matrices(matrix1, matrix2, rows1, cols1, cols2);

    // deallocate memory
    free(matrix1);
    free(matrix2);

    return 0;
}

// function to allocate memory for a matrix
int **allocate_matrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));
    return matrix;
}

// function to populate a matrix with user input
void populate_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// function to display a matrix
void display_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to multiply two matrices
void multiply_matrices(int **matrix1, int **matrix2, int rows1, int cols1, int cols2)
{
    int **result = allocate_matrix(rows1, cols2);
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free(result);
}