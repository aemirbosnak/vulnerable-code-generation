//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, a[MAX], b[MAX], c[MAX], d[MAX];

    a[0] = 0;
    a[1] = 1;

    for (i = 2; i < MAX; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    printf("The Fibonacci sequence is:\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    b[0] = 0;
    b[1] = 1;

    for (i = 2; i < MAX; i++)
    {
        b[i] = b[i - 1] + b[i - 2];
    }

    printf("The Fibonacci sequence (using recursion) is:\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    c[0] = 0;
    c[1] = 1;

    for (i = 2; i < MAX; i++)
    {
        c[i] = c[i - 1] + c[i - 2];
    }

    printf("The Fibonacci sequence (using dynamic programming) is:\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\n");

    d[0] = 0;
    d[1] = 1;

    for (i = 2; i < MAX; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }

    printf("The Fibonacci sequence (using iterative approach) is:\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", d[i]);
    }

    printf("\n");

    return 0;
}