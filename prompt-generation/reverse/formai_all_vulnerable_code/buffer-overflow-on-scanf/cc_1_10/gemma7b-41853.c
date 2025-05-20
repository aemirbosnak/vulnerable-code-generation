//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100], f[100], g[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a[0] = 1;
    b[0] = 2;
    c[0] = 3;

    for (i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + 1;
        b[i] = b[i - 1] + 2;
        c[i] = c[i - 1] + 3;
    }

    d[0] = 4;
    e[0] = 5;
    f[0] = 6;

    for (i = 1; i < n; i++)
    {
        d[i] = d[i - 1] + 2;
        e[i] = e[i - 1] + 3;
        f[i] = f[i - 1] + 4;
    }

    g[0] = 7;
    for (i = 1; i < n; i++)
    {
        g[i] = g[i - 1] + 2;
    }

    printf("The elements of the array are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        printf("%d ", b[i]);
        printf("%d ", c[i]);
        printf("%d ", d[i]);
        printf("%d ", e[i]);
        printf("%d ", f[i]);
        printf("%d ", g[i]);
    }

    return 0;
}