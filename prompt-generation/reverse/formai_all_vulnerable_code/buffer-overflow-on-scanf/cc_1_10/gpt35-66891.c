//FormAI DATASET v1.0 Category: Matrix operations ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

void matrix_addition(int **a, int **b, int **result, int rows, int columns);
void matrix_transpose(int **matrix, int rows, int columns);
void matrix_multiplication(int **a, int **b, int **result, int rows_a, int columns_a, int rows_b, int columns_b);

int main()
{
    int rows_a, columns_a, rows_b, columns_b;

    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &rows_a);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &columns_a);

    int **a = (int **)malloc(rows_a * sizeof(int *));
    for(int i=0; i<rows_a; i++)
    {
        a[i] = (int *)malloc(columns_a * sizeof(int));
        for(int j=0; j<columns_a; j++)
        {
            printf("Enter A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &rows_b);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &columns_b);

    int **b = (int **)malloc(rows_b * sizeof(int *));
    for(int i=0; i<rows_b; i++)
    {
        b[i] = (int *)malloc(columns_b * sizeof(int));
        for(int j=0; j<columns_b; j++)
        {
            printf("Enter B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nMatrix A:\n");
    for(int i=0; i<rows_a; i++)
    {
        for(int j=0; j<columns_a; j++)
        {
            printf("%d ", a[i][j]);
        }

        printf("\n");
    }

    printf("\nMatrix B:\n");
    for(int i=0; i<rows_b; i++)
    {
        for(int j=0; j<columns_b; j++)
        {
            printf("%d ", b[i][j]);
        }

        printf("\n");
    }

    if(rows_a == rows_b && columns_a == columns_b)
    {
        int **result_addition = (int **)malloc(rows_a * sizeof(int *));
        for(int i=0; i<rows_a; i++)
        {
            result_addition[i] = (int *)malloc(columns_a * sizeof(int));
        }

        matrix_addition(a, b, result_addition, rows_a, columns_a);

        printf("\nMatrix A + B:\n");
        for(int i=0; i<rows_a; i++)
        {
            for(int j=0; j<columns_a; j++)
            {
                printf("%d ", result_addition[i][j]);
            }

            printf("\n");
        }

        for(int i=0; i<rows_a; i++)
        {
            free(result_addition[i]);
        }

        free(result_addition);
    }

    if(columns_a == rows_b)
    {
        int **result_multiplication = (int **)malloc(rows_a * sizeof(int *));
        for(int i=0; i<rows_a; i++)
        {
            result_multiplication[i] = (int *)malloc(columns_b * sizeof(int));
        }

        matrix_multiplication(a, b, result_multiplication, rows_a, columns_a, rows_b, columns_b);

        printf("\nMatrix A * B:\n");
        for(int i=0; i<rows_a; i++)
        {
            for(int j=0; j<columns_b; j++)
            {
                printf("%d ", result_multiplication[i][j]);
            }

            printf("\n");
        }

        for(int i=0; i<rows_a; i++)
        {
            free(result_multiplication[i]);
        }

        free(result_multiplication);
    }

    printf("\nTranspose of Matrix A:\n");
    matrix_transpose(a, rows_a, columns_a);

    printf("\nTranspose of Matrix B:\n");
    matrix_transpose(b, rows_b, columns_b);

    for(int i=0; i<rows_a; i++)
    {
        free(a[i]);
    }

    for(int i=0; i<rows_b; i++)
    {
        free(b[i]);
    }

    free(a);
    free(b);

    return 0;
}

void matrix_addition(int **a, int **b, int **result, int rows, int columns)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrix_transpose(int **matrix, int rows, int columns)
{
    int **transpose = (int **)malloc(columns * sizeof(int *));
    for(int i=0; i<columns; i++)
    {
        transpose[i] = (int *)malloc(rows * sizeof(int));
        for(int j=0; j<rows; j++)
        {
            transpose[i][j] = matrix[j][i];
            printf("%d ", transpose[i][j]);
        }

        printf("\n");
    }

    for(int i=0; i<columns; i++)
    {
        free(transpose[i]);
    }

    free(transpose);
}

void matrix_multiplication(int **a, int **b, int **result, int rows_a, int columns_a, int rows_b, int columns_b)
{
    for(int i=0; i<rows_a; i++)
    {
        for(int j=0; j<columns_b; j++)
        {
            int sum = 0;
            for(int k=0; k<columns_a; k++)
            {
                sum += a[i][k] * b[k][j];
            }

            result[i][j] = sum;
        }
    }
}