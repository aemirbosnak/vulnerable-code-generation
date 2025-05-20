//FormAI DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include<stdio.h>
int main()
{
    int row1, col1, row2, col2, i, j, k;
    printf("Enter number of rows and columns of matrix 1: ");
    scanf("%d%d", &row1, &col1);
    printf("Enter number of rows and columns of matrix 2: ");
    scanf("%d%d", &row2, &col2);
    int a[row1][col1], b[row2][col2], c[row1][col2];

    // Input matrix 1
    printf("\nEnter the elements of matrix 1:\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input matrix 2
    printf("\nEnter the elements of matrix 2:\n");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    // Matrix Multiplication
    if(col1 == row2)
    {
        for(i=0;i<row1;i++)
        {
            for(j=0;j<col2;j++)
            {
                c[i][j] = 0;
                for(k=0;k<col1;k++)
                {
                    c[i][j] += (a[i][k] * b[k][j]);
                }
            }
        }

        // Print multiplied matrix
        printf("\nMatrix after multiplication:\n");
        for(i=0;i<row1;i++)
        {
            for(j=0;j<col2;j++)
            {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }

        // Transpose of multiplied matrix
        printf("\nTranspose of multiplied matrix:\n");
        for(i=0;i<col2;i++)
        {
            for(j=0;j<row1;j++)
            {
                printf("%d ", c[j][i]);
            }
            printf("\n");
        }

        int sum = 0;
        // Upper triangular matrix of multiplied matrix
        printf("\nUpper Triangular matrix of multiplied matrix:\n");
        for(i=0;i<row1;i++)
        {
            for(j=0;j<col2;j++)
            {
                if(i>j)
                {
                    printf("0 ");
                }
                else
                {
                    printf("%d ", c[i][j]);
                    sum += c[i][j];
                }
            }
            printf("\n");
        }

        printf("\nSum of upper triangular matrix is: %d", sum);
    }
    else
    {
        printf("\nMatrix multiplication is not possible!\n");
    }

    return 0;
}