//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l;
    char grid[5][5];
    char c, c2;

    printf("Welcome to the Decentralized Grid Game!\n\n");

    printf("Please input the size of the grid (1-10): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter a character for position (%d,%d): ", i, j);
            scanf(" %c", &grid[i][j]);
        }
    }

    for (k = 0; k < n; k++)
    {
        for (l = 0; l < n; l++)
        {
            printf("%c", grid[k][l]);
        }
        printf("\n");
    }

    printf("\n\n");

    printf("Now enter a character for the first move (A-Z): ");
    scanf(" %c", &c);

    printf("The game has begun!\n\n");

    while (1)
    {
        printf("Player 1: ");
        scanf(" %c", &c);

        printf("Player 2: ");
        scanf(" %c", &c2);

        if (c == c2)
        {
            printf("The game is a tie!\n\n");
            break;
        }
        else if (c == 'A' || c == 'B')
        {
            if (c == 'A')
            {
                printf("Player 2 wins!\n\n");
                break;
            }
            else if (c == 'B')
            {
                printf("Player 1 wins!\n\n");
                break;
            }
        }
        else
        {
            printf("Invalid move! Try again.\n\n");
        }
    }

    return 0;
}