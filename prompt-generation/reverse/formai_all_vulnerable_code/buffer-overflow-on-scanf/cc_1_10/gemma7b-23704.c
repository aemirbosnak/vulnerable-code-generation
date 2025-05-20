//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, p, q, r, s, t, u, v, w, x, y, z, a[100], b[100], c[100], d[100], e[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
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
        d[i] = a[i] % 5;
    }

    for (i = 0; i < n; i++)
    {
        e[i] = a[i] * a[i] - 10;
    }

    printf("The doubled elements are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\nThe elements increased by 10 are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\nThe elements modulo 5 are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }

    printf("\nThe elements squared minus 10 are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", e[i]);
    }

    return 0;
}