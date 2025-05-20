//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int i, n, a[MAX], b[MAX], c[MAX];

    a[0] = 0;
    a[1] = 1;

    for (n = 2; n < MAX; n++)
    {
        a[n] = a[n - 1] + a[n - 2];
    }

    b[0] = 0;
    b[1] = 1;

    for (n = 2; n < MAX; n++)
    {
        b[n] = b[n - 1] + b[n - 2];
    }

    c[0] = 0;
    c[1] = 1;

    for (n = 2; n < MAX; n++)
    {
        c[n] = c[n - 1] + c[n - 2];
    }

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\n");

    return 0;
}