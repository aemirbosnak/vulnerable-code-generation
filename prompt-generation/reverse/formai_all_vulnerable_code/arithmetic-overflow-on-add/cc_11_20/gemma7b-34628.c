//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x, y, z, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x1, x2, y1, y2;

    x = y = z = 0;
    n = 10;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                printf("X ");
            }
            else
            {
                printf("O ");
            }
        }

        printf("\n");
    }

    printf("Enter start and end points:");
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);

    printf("Path:");

    for (i = x1 - 1; i <= x2; i++)
    {
        for (j = y1 - 1; j <= y2; j++)
        {
            if (i == x2 && j == y2)
            {
                printf("X ");
            }
            else if (i == x1 - 1 && j == y1 - 1)
            {
                printf("S ");
            }
            else
            {
                printf("O ");
            }
        }

        printf("\n");
    }

    return 0;
}