//FormAI DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>

// define matrix dimensions
#define ROWS 3
#define COLS 3

int main()
{
    // declare matrices
    int matrix_one[ROWS][COLS], matrix_two[ROWS][COLS], sum_matrix[ROWS][COLS], diff_matrix[ROWS][COLS], mul_matrix[ROWS][COLS];
    int row, col;

    // initialize matrix_one
    printf("Enter elements of matrix_one:\n");
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            printf("[%d][%d]: ", row, col);
            scanf("%d", &matrix_one[row][col]);
        }
    }

    // initialize matrix_two
    printf("Enter elements of matrix_two:\n");
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            printf("[%d][%d]: ", row, col);
            scanf("%d", &matrix_two[row][col]);
        }
    }

    // matrix addition
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            sum_matrix[row][col] = matrix_one[row][col] + matrix_two[row][col];
        }
    }

    // matrix subtraction
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            diff_matrix[row][col] = matrix_one[row][col] - matrix_two[row][col];
        }
    }

    // matrix multiplication
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            mul_matrix[row][col] = 0;
            int k;
            for(k = 0; k < ROWS; k++)
            {
                mul_matrix[row][col] += matrix_one[row][k] * matrix_two[k][col];
            }
        }
    }

    // print sum matrix
    printf("\nSum of matrices:\n");
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            printf("%d ", sum_matrix[row][col]);
        }
        printf("\n");
    }

    // print difference matrix
    printf("\nDifference of matrices:\n");
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            printf("%d ", diff_matrix[row][col]);
        }
        printf("\n");
    }

    // print multiplication matrix
    printf("\nMultiplication of matrices:\n");
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            printf("%d ", mul_matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}