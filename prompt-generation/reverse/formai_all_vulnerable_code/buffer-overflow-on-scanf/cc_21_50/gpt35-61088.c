//FormAI DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>

int main()
{
    int rows, cols;

    // Take the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int mat1[rows][cols], mat2[rows][cols], sum[rows][cols], transpose[cols][rows], product[rows][cols];

    printf("\nEnter elements of first matrix:\n");
    // Take input for the first matrix
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("Enter element[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\nEnter elements of second matrix:\n");
    // Take input for the second matrix
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("Enter element[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("\nFirst Matrix:\n");
    // Display the first matrix
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nSecond Matrix:\n");
    // Display the second matrix
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }

    // Matrix Addition
    printf("\nMatrix Addition:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            sum[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    // Matrix Transpose
    printf("\nMatrix Transpose:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            transpose[j][i] = mat1[i][j];
        }
    }

    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    // Matrix Multiplication
    printf("\nMatrix Multiplication:\n");

    // Take input for the second matrix
    printf("\nEnter new elements of second matrix:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("Enter element[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            product[i][j] = 0;
            for(int k = 0; k < cols; k++)
                product[i][j] += mat1[i][k] * mat2[k][j];
        }
    }

    // Display the product matrix
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }
    return 0;
}