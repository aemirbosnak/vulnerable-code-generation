//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, a[MAX], b[MAX], c[MAX];

    printf("Enter the number of terms: ");
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

    printf("Fibonacci sequence using array a: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nFibonacci sequence using array b: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\nFibonacci sequence using array c: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}