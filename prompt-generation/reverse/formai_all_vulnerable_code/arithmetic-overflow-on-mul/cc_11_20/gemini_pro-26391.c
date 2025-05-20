//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        for (k = 0; k < 2 * i + 1; k++)
        {
            if (k == 0 || k == 2 * i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        for (k = 0; k < 2 * i + 1; k++)
        {
            if (k == 0 || k == 2 * i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}