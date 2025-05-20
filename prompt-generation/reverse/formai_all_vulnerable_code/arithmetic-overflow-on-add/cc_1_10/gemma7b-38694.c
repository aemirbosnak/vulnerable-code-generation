//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, a[MAX], b[MAX], c[MAX];

    a[0] = 0;
    a[1] = 1;

    for (i = 2; i < MAX; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    b[0] = a[0];
    b[1] = a[1];

    for (i = 2; i < n; i++)
    {
        b[i] = a[i - 1] + a[i - 2];
    }

    printf("The Fibonacci sequence of %d terms is:\n", n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    c[0] = a[0];
    c[1] = a[1];

    for (i = 2; i < n; i++)
    {
        c[i] = a[i - 1] + a[i - 2];
    }

    printf("The Fibonacci sequence of %d terms using dynamic programming is:\n", n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}