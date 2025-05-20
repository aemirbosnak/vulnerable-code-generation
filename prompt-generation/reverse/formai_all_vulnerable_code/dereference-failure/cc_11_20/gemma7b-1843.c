//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL, i, j, k;

    a = (int **)malloc(10 * sizeof(int *));
    for(i = 0; i < 10; i++)
    {
        a[i] = (int *)malloc(10 * sizeof(int));
    }

    b = (int **)malloc(20 * sizeof(int *));
    for(i = 0; i < 20; i++)
    {
        b[i] = (int *)malloc(20 * sizeof(int));
    }

    c = (int **)malloc(30 * sizeof(int *));
    for(i = 0; i < 30; i++)
    {
        c[i] = (int *)malloc(30 * sizeof(int));
    }

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            a[i][j] = i + j;
        }
    }

    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 20; j++)
        {
            b[i][j] = 2 * i + 3 * j;
        }
    }

    for(i = 0; i < 30; i++)
    {
        for(j = 0; j < 30; j++)
        {
            c[i][j] = 3 * i + 4 * j;
        }
    }

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 20; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 30; i++)
    {
        for(j = 0; j < 30; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}