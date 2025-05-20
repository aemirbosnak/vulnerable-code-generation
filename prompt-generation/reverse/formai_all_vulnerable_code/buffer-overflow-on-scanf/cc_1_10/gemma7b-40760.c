//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, l, x, y;
    int a[MAX], b[MAX], c[MAX];

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    a[0] = 0;
    a[1] = 1;

    for (i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    printf("The Fibonacci sequence of %d terms is: ", n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    x = 0;
    y = 1;

    for (k = 0; k < n; k++)
    {
        l = x + y;
        c[k] = x;
        x = y;
        y = l;
    }

    printf("The Fibonacci sequence in the shape of a spiral is: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}