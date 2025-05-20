//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, a[MAX], b[MAX], c[MAX], d[MAX], e[MAX];

    // Generate Fibonacci sequence
    a[0] = 0;
    a[1] = 1;
    for (i = 2; i < MAX; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    // Visualize Fibonacci sequence
    printf("Fibonacci Sequence:\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    // Calculate Fibonacci ratios
    b[0] = 0;
    b[1] = 1;
    for (i = 2; i < MAX; i++)
    {
        b[i] = (a[i] - a[i - 1]) * 100 / a[i - 1];
    }

    // Visualize Fibonacci ratios
    printf("Fibonacci Ratios:**\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d %% ", b[i]);
    }

    printf("\n");

    // Find Fibonacci number at given index
    c[0] = 0;
    c[1] = 1;
    for (i = 2; i < MAX; i++)
    {
        c[i] = a[i - 1] + a[i - 2];
    }

    printf("Fibonacci Number at Index 20: %d\n", c[20]);

    // Calculate Fibonacci number at given index
    d[0] = 0;
    d[1] = 1;
    for (i = 2; i < MAX; i++)
    {
        d[i] = a[i - 1] + a[i - 2];
    }

    printf("Fibonacci Number at Index 30: %d\n", d[30]);

    // Calculate Fibonacci number at given index
    e[0] = 0;
    e[1] = 1;
    for (i = 2; i < MAX; i++)
    {
        e[i] = a[i - 1] + a[i - 2];
    }

    printf("Fibonacci Number at Index 40: %d\n", e[40]);

    return 0;
}