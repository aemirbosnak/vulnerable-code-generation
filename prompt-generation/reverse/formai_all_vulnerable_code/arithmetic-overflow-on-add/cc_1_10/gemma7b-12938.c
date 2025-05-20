//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: curious
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

    printf("The Fibonacci sequence of the first %d numbers is:\n", MAX);

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    b[0] = a[0];
    b[1] = a[1];

    for (i = 2; i < MAX; i++)
    {
        b[i] = a[i - 1] + a[i - 2];
    }

    printf("The Fibonacci sequence of the first %d numbers in reverse order is:\n", MAX);

    for (i = MAX - 1; i >= 0; i--)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    c[0] = a[0];
    c[1] = a[1];

    for (i = 2; i < MAX; i++)
    {
        c[i] = a[i - 1] + a[i - 2];
    }

    printf("The Fibonacci sequence of the first %d numbers with doubling each term is:\n", MAX);

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\n");

    return 0;
}