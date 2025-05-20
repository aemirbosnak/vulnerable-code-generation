//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100];

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
        e[i] = a[i] / 3;
    }

    printf("The elements of the array a are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nThe elements of the array b are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\nThe elements of the array c are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\nThe elements of the array d are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }

    printf("\nThe elements of the array e are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", e[i]);
    }

    return 0;
}