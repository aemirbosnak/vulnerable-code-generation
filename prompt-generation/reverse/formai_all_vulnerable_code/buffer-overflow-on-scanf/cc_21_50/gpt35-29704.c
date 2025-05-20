//FormAI DATASET v1.0 Category: Matrix operations ; Style: satisfied
/*
This program demonstrates the use of 2D arrays or matrices in C programming for doing some common matrix operations like
matrix addition, matrix subtraction, matrix multiplication, and matrix transposition.

Let's get started!
*/

#include <stdio.h>

int main()
{
    int rows, cols, i, j, k, sum;

    // Taking input from the user for the size of matrices
    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Initializing the matrices with zeros
    int mat1[rows][cols], mat2[rows][cols], res[rows][cols], transpose[cols][rows];
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            mat1[i][j] = 0;
            mat2[i][j] = 0;
            res[i][j] = 0;
            transpose[j][i] = 0;
        }
    }

    // Taking input for matrix 1 elements from the user
    printf("\nEnter the elements of matrix 1:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter element (%d,%d): ", i+1, j+1);
            scanf("%d", &mat1[i][j]);
        }
    }

    // Taking input for matrix 2 elements from the user
    printf("\nEnter the elements of matrix 2:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter element (%d,%d): ", i+1, j+1);
            scanf("%d", &mat2[i][j]);
        }
    }

    // Displaying the matrices
    printf("\nMatrix 1 is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2 is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    // Matrix addition
    printf("\nMatrix Addition is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    // Matrix subtraction
    printf("\nMatrix Subtraction is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            res[i][j] = mat1[i][j] - mat2[i][j];
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    // Matrix multiplication
    printf("\nMatrix Multiplication is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            sum = 0;
            for (k = 0; k < cols; k++)
            {
                sum += mat1[i][k] * mat2[k][j];
            }
            res[i][j] = sum;
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    // Matrix transposition
    printf("\nMatrix 1 Transpose is:\n");
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            transpose[i][j] = mat1[j][i];
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2 Transpose is:\n");
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            transpose[i][j] = mat2[j][i];
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // End of program
    return 0;
}