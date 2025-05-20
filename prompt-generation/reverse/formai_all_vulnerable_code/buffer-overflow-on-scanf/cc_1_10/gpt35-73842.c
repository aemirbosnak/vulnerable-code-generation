//FormAI DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#define MAX_SIZE 10

int row1, col1, row2, col2;

void matrix_addition(int m1[][MAX_SIZE], int m2[][MAX_SIZE], int result[][MAX_SIZE], int row, int col)
{
    if(row < row1 && col < col1)
    {
        result[row][col] = m1[row][col] + m2[row][col];
        matrix_addition(m1, m2, result, row + 1, col + 1);
    }
}

void matrix_multiplication(int m1[][MAX_SIZE], int m2[][MAX_SIZE], int result[][MAX_SIZE], int row, int col)
{
    int k = 0;
    
    if(row < row1 && col < col2)
    {
        result[row][col] = 0;
        for(k = 0; k < col1; k++)
        {
            result[row][col] += m1[row][k] * m2[k][col];
        }
        matrix_multiplication(m1, m2, result, row + 1, col + 1);
    }
}

void matrix_transpose(int m[][MAX_SIZE], int t[][MAX_SIZE], int row, int col)
{
    if(row < row1 && col < col1)
    {
        t[col][row] = m[row][col];
        matrix_transpose(m, t, row + 1, col + 1);
    }
}
int main()
{
    int m1[MAX_SIZE][MAX_SIZE], m2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], transpose[MAX_SIZE][MAX_SIZE];
    int i, j;
    
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter the elements of matrix 1: \n");
    for(i = 0; i < row1; i++)
    {
        for(j = 0; j < col1; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d", &row2, &col2);

    printf("Enter the elements of matrix 2: \n");
    for(i = 0; i < row2; i++)
    {
        for(j = 0; j < col2; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    if(col1 != row2)
    {
        printf("Matrix multiplication is not possible!\n");
    }
    else
    {
        printf("Matrix addition:\n");
        matrix_addition(m1, m2, result, 0, 0);

        for(i = 0; i < row1; i++)
        {
            for(j = 0; j < col1; j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }

        printf("Matrix multiplication:\n");
        matrix_multiplication(m1, m2, result, 0, 0);

        for(i = 0; i < row1; i++)
        {
            for(j = 0; j < col2; j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }

    printf("Matrix transpose:\n");
    matrix_transpose(m1, transpose, 0, 0);

    for(i = 0; i < col1; i++)
    {
        for(j = 0; j < row1; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}