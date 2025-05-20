//FormAI DATASET v1.0 Category: Pattern printing ; Style: careful
#include <stdio.h>

int main()
{
    int n, i, j, k;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    for (i = 1; i <= n; i++)
    {
        for (j = n; j >= i; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--)
    {
        for (j = n; j >= i; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    for (i = 1; i <= n; i++)
    {
        for (j = n; j >= i; j--)
        {
            printf("%d ", j);
        }
        for (k = 1; k < i; k++)
        {
            printf("%d ", k + 1);
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--)
    {
        for (j = n; j >= i; j--)
        {
            printf("%d ", j);
        }
        for (k = 1; k < i; k++)
        {
            printf("%d ", k + 1);
        }
        printf("\n");
    }

    return 0;
}