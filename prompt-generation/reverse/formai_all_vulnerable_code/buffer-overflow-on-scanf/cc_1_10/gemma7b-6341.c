//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100];

    printf("Enter the number of elements:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element:");
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
        e[i] = a[i] & 10;
    }

    for (i = 0; i < n; i++)
    {
        f[i] = a[i] | 5;
    }

    for (i = 0; i < n; i++)
    {
        g[i] = a[i] ^ 3;
    }

    for (i = 0; i < n; i++)
    {
        h[i] = a[i] + 100;
    }

    for (i = 0; i < n; i++)
    {
        printf("The element is:");
        printf(" %d", a[i]);
        printf(", the double of the element is:");
        printf(" %d", b[i]);
        printf(", the element added by 10 is:");
        printf(" %d", c[i]);
        printf(", the remainder when the element is divided by 5 is:");
        printf(" %d", d[i]);
        printf(", the element with the first digit removed is:");
        printf(" %d", e[i]);
        printf(", the element with the first digit OR-ed with 5 is:");
        printf(" %d", f[i]);
        printf(", the element XOR-ed with 3 is:");
        printf(" %d", g[i]);
        printf(", the element added by 100 is:");
        printf(" %d", h[i]);
        printf("\n");
    }

    return 0;
}