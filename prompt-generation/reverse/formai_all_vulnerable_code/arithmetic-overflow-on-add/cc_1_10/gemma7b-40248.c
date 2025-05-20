//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, c, a[MAX], b[MAX], f[MAX];
    a[0] = 0;
    a[1] = 1;
    for (i = 2; i < MAX; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    printf("Calculating Fibonacci using recursion: ");
    for (i = 0; i < n; i++)
    {
        f[i] = fib(i);
    }

    printf("Fibonacci sequence (recursive): ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", f[i]);
    }

    return 0;
}

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}