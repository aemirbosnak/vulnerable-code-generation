//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, x, y, z, w, h, e, f;
    char a, b, c, d, g;

    printf("Enter the number of players: ");
    scanf("%d", &n);

    printf("Enter the number of rounds: ");
    scanf("%d", &k);

    for (l = 0; l < k; l++)
    {
        printf("Round %d:\n", l + 1);

        for (i = 0; i < n; i++)
        {
            printf("Player %d's turn:\n", i + 1);

            printf("Enter the number of moves: ");
            scanf("%d", &x);

            printf("Enter the direction of move (N/S/E/W): ");
            scanf(" %c", &a);

            switch (a)
            {
                case 'N':
                    y = -1;
                    break;
                case 'S':
                    y = 1;
                    break;
                case 'E':
                    z = 1;
                    break;
                case 'W':
                    z = -1;
                    break;
            }

            for (j = 0; j < x; j++)
            {
                printf("Move %d:\n", j + 1);

                switch (a)
                {
                    case 'N':
                        printf("Move north\n");
                        break;
                    case 'S':
                        printf("Move south\n");
                        break;
                    case 'E':
                        printf("Move east\n");
                        break;
                    case 'W':
                        printf("Move west\n");
                        break;
                }

                printf("New position: (%d, %d)\n", x + z, y);
            }

            printf("End of turn.\n");
        }

        printf("End of round.\n");
    }

    return 0;
}