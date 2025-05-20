//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int main()
{
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], i, j, k;

    // Initialization of the matrices
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            a[i][j] = 0;
            b[i][j] = 0;
            c[i][j] = 0;
        }
    }

    // Input the elements of the first matrix
    printf("Enter the elements of the first matrix (a):\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input the elements of the second matrix (b)
    printf("Enter the elements of the second matrix (b):\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix multiplication (c = a * b)
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            for (k = 0; k < MAX; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Display the elements of the resulting matrix (c)
    printf("The elements of the resulting matrix (c) are:\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}