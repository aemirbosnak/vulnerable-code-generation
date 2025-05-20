//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int main()
{
    int **a = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        a[i] = (int *)malloc(MAX * sizeof(int));
    }

    int **b = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        b[i] = (int *)malloc(MAX * sizeof(int));
    }

    int **c = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        c[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < MAX; i++)
    {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < MAX; i++)
    {
        free(b[i]);
    }
    free(b);

    for (int i = 0; i < MAX; i++)
    {
        free(c[i]);
    }
    free(c);

    return 0;
}