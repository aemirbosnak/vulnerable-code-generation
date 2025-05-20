//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, a[MAX], b[MAX], c[MAX], d[MAX], e[MAX], f[MAX];

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    a[0] = 0;
    a[1] = 1;

    for (i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    b[0] = 0;
    b[1] = 1;

    for (i = 2; i < n; i++)
    {
        b[i] = b[i - 1] + b[i - 2];
    }

    c[0] = 0;
    c[1] = 1;

    for (i = 2; i < n; i++)
    {
        c[i] = c[i - 1] + c[i - 2];
    }

    d[0] = 0;
    d[1] = 1;

    for (i = 2; i < n; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }

    e[0] = 0;
    e[1] = 1;

    for (i = 2; i < n; i++)
    {
        e[i] = e[i - 1] + e[i - 2];
    }

    f[0] = 0;
    f[1] = 1;

    for (i = 2; i < n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", e[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", f[i]);
    }

    printf("\n");

    return 0;
}