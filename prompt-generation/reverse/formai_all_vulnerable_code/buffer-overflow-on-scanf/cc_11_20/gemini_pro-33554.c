//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, p, q;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (k = i; k < n; k++)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            if (j == 1 || i == n)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        for (p = 2; p <= i; p++)
        {
            if (p == i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        for (q = i + 1; q <= n; q++)
        {
            printf(" ");
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--)
    {
        for (k = i; k <= n; k++)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            if (j == 1 || i == n)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        for (p = 2; p <= i; p++)
        {
            if (p == i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        for (q = i + 1; q <= n; q++)
        {
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}