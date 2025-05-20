//FormAI DATASET v1.0 Category: Scientific ; Style: satisfied
/*
 *
 * C program to find the sum of two matrices
 *
 */

#include <stdio.h>

void main()
{
    int rows, cols, i, j;
    int matrix1[10][10], matrix2[10][10], sum[10][10];

    printf("Please enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("\nNow, enter the elements of matrix 1:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter the elements of matrix 2:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nSum of Matrices:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}