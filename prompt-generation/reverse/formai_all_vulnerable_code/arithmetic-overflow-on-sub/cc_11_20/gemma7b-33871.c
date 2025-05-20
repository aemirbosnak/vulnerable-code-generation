//Gemma-7B DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, m, score = 0, board[6][6] = {{0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}};

    printf("Welcome to the Crazy Snake Game!\n");
    printf("Enter the number of players: ");
    scanf("%d", &n);

    // Allocate memory for game pieces
    int **pieces = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        pieces[i] = (int *)malloc(6 * sizeof(int));
    }

    // Initialize game pieces
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 6; j++)
        {
            pieces[i][j] = 0;
        }
    }

    // Set up the board
    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Game loop
    while (score < n - 1)
    {
        // Get the player's move
        printf("Enter your move (e.g. N, S, E, W): ");
        char move;
        scanf("%c", &move);

        // Validate the move
        if (move != 'N' && move != 'S' && move != 'E' && move != 'W')
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        switch (move)
        {
            case 'N':
                pieces[0][0]++;
                break;
            case 'S':
                pieces[0][5]--;
                break;
            case 'E':
                pieces[5][0]++;
                break;
            case 'W':
                pieces[5][5]--;
                break;
        }

        // Check if the player has won
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < 6; j++)
            {
                if (pieces[i][j] == n)
                {
                    score++;
                    printf("Congratulations! You have won!\n");
                    break;
                }
            }
        }

        // Print the board
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Free memory
    for (i = 0; i < n; i++)
    {
        free(pieces[i]);
    }
    free(pieces);

    return 0;
}