//Gemma-7B DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, score1 = 0, score2 = 0;
    char board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    printf("Enter the number of players: ");
    scanf("%d", &n);

    if (n == 2)
    {
        printf("Enter the number of moves: ");
        scanf("%d", &m);

        for (i = 0; i < m; i++)
        {
            printf("Enter the row and column of the move: ");
            scanf("%d %d", &j, &i);

            if (board[j][i] == 0)
            {
                board[j][i] = 1;

                // Check if the move is valid
                if (checkMove(board, j, i, n) == 1)
                {
                    // Increment the score of the player who made the move
                    score1++;
                }
                else
                {
                    // Print an error message
                    printf("Invalid move.\n");
                }
            }
            else
            {
                // Print an error message
                printf("Move already made.\n");
            }
        }

        // Print the final board
        printf("The final board:\n");
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Print the winner
        if (score1 > score2)
        {
            printf("Player 1 won!\n");
        }
        else if (score2 > score1)
        {
            printf("Player 2 won!\n");
        }
        else
        {
            printf("It's a draw.\n");
        }
    }
    else
    {
        printf("Invalid number of players.\n");
    }

    return 0;
}

int checkMove(char board[6][6], int j, int i, int n)
{
    int k, l, moveValid = 0;

    // Check if the move is within the board
    if (j < 0 || j >= 6 || i < 0 || i >= 6)
    {
        return 0;
    }

    // Check if the move has already been made
    if (board[j][i] != 0)
    {
        return 0;
    }

    // Check if the move is valid for the player
    for (k = 0; k < n; k++)
    {
        for (l = 0; l < n; l++)
        {
            if (board[k][l] == board[j][i] && k != j && l != i)
            {
                moveValid = 1;
            }
        }
    }

    return moveValid;
}