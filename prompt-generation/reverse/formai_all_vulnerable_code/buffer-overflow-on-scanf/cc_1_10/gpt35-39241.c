//FormAI DATASET v1.0 Category: Pattern printing ; Style: accurate
#include <stdio.h>

int main()
{
    int size, i, j, k, space = 1;

    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    for (i = 1; i <= size; i++)
    {
        for (j = size; j > i; j--)
        {
            printf("  ");
        }

        printf("* ");

        if (i != 1)
        {
            for (k = 1; k <= space; k++)
            {
                printf("  ");
            }

            space += 2;

            printf("* ");
        }

        printf("\n");
    }

    space -= 4;

    for (i = 1; i <= size - 1; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("  ");
        }

        printf("* ");

        for (k = 1; k <= space; k++)
        {
            printf("  ");
        }

        space -= 2;

        if (i != size - 1)
        {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}