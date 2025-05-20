//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5, b = 10, c = 20, d = 30;
    int **p, **q, **r;

    p = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        p[i] = (int *)malloc(b * sizeof(int));
    }

    q = (int **)malloc(c * sizeof(int *));
    for (int i = 0; i < c; i++)
    {
        q[i] = (int *)malloc(d * sizeof(int));
    }

    r = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        r[i] = (int *)malloc(b * sizeof(int));
    }

    // Matrix Operations
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            int sum = 0;
            for (int k = 0; k < c; k++)
            {
                sum += p[i][k] * q[k][j];
            }
            r[i][j] = sum;
        }
    }

    // Print the Result
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }

    // Free Memory
    for (int i = 0; i < a; i++)
    {
        free(p[i]);
    }
    free(p);

    for (int i = 0; i < c; i++)
    {
        free(q[i]);
    }
    free(q);

    for (int i = 0; i < a; i++)
    {
        free(r[i]);
    }
    free(r);

    return 0;
}