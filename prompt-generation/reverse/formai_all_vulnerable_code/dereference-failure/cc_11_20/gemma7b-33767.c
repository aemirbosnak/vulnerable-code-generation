//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL, i, j, k, l;

    a = (int **)malloc(5 * sizeof(int *));
    for(i = 0; i < 5; i++)
    {
        a[i] = (int *)malloc(10 * sizeof(int));
    }

    b = (int **)malloc(3 * sizeof(int *));
    for(i = 0; i < 3; i++)
    {
        b[i] = (int *)malloc(4 * sizeof(int));
    }

    c = (int **)malloc(2 * sizeof(int *));
    for(i = 0; i < 2; i++)
    {
        c[i] = (int *)malloc(5 * sizeof(int));
    }

    i = 0;
    j = 0;
    k = 0;
    l = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 10; j++)
        {
            a[i][j] = k++;
        }
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            b[i][j] = l++;
        }
    }

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 5; j++)
        {
            c[i][j] = k++;
        }
    }

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 10; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 5; j++)
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