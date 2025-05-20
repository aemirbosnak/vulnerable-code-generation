//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100], f[100], g[100];

    printf("Enter the number of bits: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the binary number: ");
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        b[i] = a[i] % 2;
        c[i] = a[i] / 2;
    }

    for (i = 0; i < n - 1; i++)
    {
        d[i] = c[i] % 2;
        e[i] = c[i] / 2;
    }

    for (i = 0; i < n - 2; i++)
    {
        f[i] = e[i] % 2;
        g[i] = e[i] / 2;
    }

    for (i = 0; i < n - 1; i++)
    {
        printf("%d", d[i]);
    }

    printf("\n");

    for (i = 0; i < n - 2; i++)
    {
        printf("%d", f[i]);
    }

    printf("\n");

    for (i = 0; i < n - 2; i++)
    {
        printf("%d", g[i]);
    }

    return 0;
}