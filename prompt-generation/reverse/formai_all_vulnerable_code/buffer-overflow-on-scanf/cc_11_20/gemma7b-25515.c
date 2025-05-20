//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, m, l, a[100], b[100], c[100], d[100], e[100], f[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        b[i] = a[i] * 2;
    }

    for (i = 0; i < n; i++)
    {
        c[i] = a[i] + 10;
    }

    for (i = 0; i < n; i++)
    {
        d[i] = a[i] - 5;
    }

    for (i = 0; i < n; i++)
    {
        e[i] = a[i] * a[i];
    }

    for (i = 0; i < n; i++)
    {
        f[i] = a[i] / 2;
    }

    printf("The original array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nThe doubled array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\nThe added array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\nThe subtracted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }

    printf("\nThe squared array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", e[i]);
    }

    printf("\nThe divided array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", f[i]);
    }

    return 0;
}