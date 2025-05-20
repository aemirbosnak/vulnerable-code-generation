//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

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

    printf("The Fibonacci sequence of %d terms is: ", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    b[0] = 0;
    b[1] = 1;
    for (i = 2; i < n; i++)
    {
        b[i] = (int)round(a[i - 1] * 1.8);
    }

    printf("The Fibonacci sequence of %d terms with 1.8 multiplier is: ", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    c[0] = 0;
    c[1] = 1;
    for (i = 2; i < n; i++)
    {
        c[i] = (int)round(a[i - 1] * 2);
    }

    printf("The Fibonacci sequence of %d terms with 2 multiplier is: ", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}