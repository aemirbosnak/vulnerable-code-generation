//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>

int main()
{
    int rows, i, j, k, space = 1;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++)
    {
        for (j = i; j < rows; j++)
        {
            printf("  ");
        }

        for (j = 1; j <= i; j++)
        {
            printf("* ");
        }

        if (i == 1)
        {
            printf("\n");
        }
        else
        {
            for (j = 1; j <= space; j++)
            {
                printf("  ");
            }

            for (j = 1; j <= i; j++)
            {
                printf("* ");
            }

            space++;
            printf("\n");
        }
    }

    space = rows - 1;

    for (i = 1; i <= rows - 1; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("  ");
        }

        for (j = space; j >= 1; j--)
        {
            printf("* ");
        }

        space--;

        printf("\n");
    }

    return 0;
}