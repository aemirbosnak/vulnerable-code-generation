//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL, i, j, k;

    a = (int **)malloc(5 * sizeof(int *));
    for(i = 0; i < 5; i++)
    {
        a[i] = (int *)malloc(5 * sizeof(int));
    }

    b = (int **)malloc(3 * sizeof(int *));
    for(i = 0; i < 3; i++)
    {
        b[i] = (int *)malloc(3 * sizeof(int));
    }

    c = (int **)malloc(2 * sizeof(int *));
    for(i = 0; i < 2; i++)
    {
        c[i] = (int *)malloc(2 * sizeof(int));
    }

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            a[i][j] = 0;
        }
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            b[i][j] = 0;
        }
    }

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            c[i][j] = 0;
        }
    }

    k = 0;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            c[k][0] = a[i][j] + b[i][j];
            k++;
        }
    }

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
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