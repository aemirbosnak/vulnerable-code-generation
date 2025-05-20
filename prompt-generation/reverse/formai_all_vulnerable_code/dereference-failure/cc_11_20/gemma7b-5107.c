//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    int rows, cols, i, j, k, l;

    printf("Enter the number of rows:");
    scanf("%d", &rows);

    printf("Enter the number of columns:");
    scanf("%d", &cols);

    a = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++)
    {
        a[i] = (int*)malloc(cols * sizeof(int));
    }

    b = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++)
    {
        b[i] = (int*)malloc(cols * sizeof(int));
    }

    c = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++)
    {
        c[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the first matrix:");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    k = rows;
    l = cols;

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < l; j++)
        {
            c[i][j] = 0;
            for (int n = 0; n < rows; n++)
            {
                for (int m = 0; m < cols; m++)
                {
                    c[i][j] += a[n][m] * b[n][m];
                }
            }
        }
    }

    printf("The product of the two matrices is:");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}