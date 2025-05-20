//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5

void matrix_operations(int **a, int **b, int **c)
{
    int i, j, k;
    int rows = *a, cols = *b, output_rows = *c;

    *c = malloc(rows * output_rows * sizeof(int));

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < output_rows; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int a_rows, a_cols, b_rows, b_cols, c_rows;
    int **a, **b, **c;

    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &a_rows);

    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &a_cols);

    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &b_rows);

    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &b_cols);

    c_rows = a_rows * b_rows;

    a = malloc(a_rows * a_cols * sizeof(int));
    b = malloc(b_rows * b_cols * sizeof(int));
    c = malloc(c_rows * MAX_COLS * sizeof(int));

    printf("Enter the elements of matrix A: ");
    for (int i = 0; i < a_rows; i++)
    {
        for (int j = 0; j < a_cols; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B: ");
    for (int i = 0; i < b_rows; i++)
    {
        for (int j = 0; j < b_cols; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    matrix_operations(&a, &b, &c);

    printf("The product of the two matrices is: ");
    for (int i = 0; i < c_rows; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}