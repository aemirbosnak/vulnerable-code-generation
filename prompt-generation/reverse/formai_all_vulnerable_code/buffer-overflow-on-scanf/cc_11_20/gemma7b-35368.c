//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100];

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the operations:");
    scanf(" %c", &k);

    switch (k)
    {
        case 'A':
            for (i = 0; i < n; i++)
            {
                b[i] = a[i] + 10;
            }
            break;
        case 'S':
            for (i = 0; i < n; i++)
            {
                b[i] = a[i] - 10;
            }
            break;
        case 'M':
            for (i = 0; i < n; i++)
            {
                b[i] = a[i] * 2;
            }
            break;
        case 'D':
            for (i = 0; i < n; i++)
            {
                b[i] = a[i] / 2;
            }
            break;
        default:
            printf("Invalid operation");
    }

    printf("The results are:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    return 0;
}