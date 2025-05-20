//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;
    int i, j, k, l;

    a = (int **)malloc(5 * sizeof(int *));
    for (i = 0; i < 5; i++)
    {
        a[i] = (int *)malloc(10 * sizeof(int));
    }

    b = (int **)malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++)
    {
        b[i] = (int *)malloc(5 * sizeof(int));
    }

    c = (int **)malloc(2 * sizeof(int *));
    for (i = 0; i < 2; i++)
    {
        c[i] = (int *)malloc(10 * sizeof(int));
    }

    k = 0;
    l = 0;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            a[i][j] = k++;
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            b[i][j] = l++;
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 10; j++)
        {
            c[i][j] = l++;
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);
}