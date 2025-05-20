//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c, i, j, k, l, m, n;
    char ch, cmd, dir, move;

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    printf("Enter the number of moves: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the direction (N, S, E, W): ");
        scanf(" %c", &dir);

        printf("Enter the move (F, B, L, R): ");
        scanf(" %c", &move);

        switch (dir)
        {
            case 'N':
                l = -1;
                m = 0;
                break;
            case 'S':
                l = 1;
                m = 0;
                break;
            case 'E':
                l = 0;
                m = 1;
                break;
            case 'W':
                l = 0;
                m = -1;
                break;
        }

        switch (move)
        {
            case 'F':
                k = 1;
                break;
            case 'B':
                k = -1;
                break;
            case 'L':
                k = -1;
                break;
            case 'R':
                k = 1;
                break;
        }

        for (j = 0; j < r; j++)
        {
            for (k = 0; k < c; k++)
            {
                if (j == l && k == m)
                {
                    printf("R");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}