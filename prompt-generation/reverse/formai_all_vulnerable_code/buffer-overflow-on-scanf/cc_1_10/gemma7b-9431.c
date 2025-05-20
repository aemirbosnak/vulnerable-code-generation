//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
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
        e[i] = a[i] * 3 + 5;
    }

    for (i = 0; i < n; i++)
    {
        printf("The doubled element is: %d\n", b[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("The element plus 10 is: %d\n", c[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("The element minus 5 is: %d\n", d[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("The element multiplied by 3 and added by 5 is: %d\n", e[i]);
    }

    return 0;
}