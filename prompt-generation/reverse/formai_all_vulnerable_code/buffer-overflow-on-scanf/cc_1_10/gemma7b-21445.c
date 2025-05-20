//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, a[100], b[100], c[100], d[100], e[100];

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
        c[i] = a[i] + b[i];
    }

    for (i = 0; i < n; i++)
    {
        d[i] = a[i] - b[i];
    }

    for (i = 0; i < n; i++)
    {
        e[i] = a[i] * b[i];
    }

    printf("The doubled elements are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\nThe sum of elements and doubled elements is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\nThe difference of elements and doubled elements is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }

    printf("\nThe product of elements and doubled elements is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", e[i]);
    }

    return 0;
}