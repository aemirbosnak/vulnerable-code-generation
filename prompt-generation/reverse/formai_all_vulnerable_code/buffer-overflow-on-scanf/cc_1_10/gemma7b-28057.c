//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, a[100], b[100], c[100], d[100];
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    a[0] = 0;
    a[1] = 1;

    for (i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    printf("The Fibonacci sequence is:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    b[0] = 0;
    b[1] = 1;

    for (i = 2; i < n; i++)
    {
        b[i] = b[i - 1] + b[i - 2];
    }

    printf("The modified Fibonacci sequence is:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    c[0] = 0;
    c[1] = 1;

    for (i = 2; i < n; i++)
    {
        c[i] = c[i - 1] + c[i - 2];
    }

    printf("The squared Fibonacci sequence is:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i] * c[i]);
    }

    printf("\n");

    d[0] = 0;
    d[1] = 1;

    for (i = 2; i < n; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }

    printf("The cube Fibonacci sequence is:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", d[i] * d[i] * d[i]);
    }

    return 0;
}