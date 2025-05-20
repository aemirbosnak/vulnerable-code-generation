//Gemma-7B DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, score = 0, highScore = 0;
    char board[6][6] = { { ' ', ' ', ' ', ' ', ' ', ' ' },
                              { ' ', 'O', ' ', ' ', ' ', ' ' },
                              { ' ', 'O', 'O', ' ', ' ', ' ' },
                              { ' ', 'O', 'O', 'O', ' ', ' ' },
                              { ' ', 'O', 'O', 'O', 'O', ' ' },
                              { ' ', ' ', ' ', ' ', ' ', ' ' } };

    printf("Welcome to Connect Four!\n");

    // Game loop
    while (score != 1 && highScore != 1)
    {
        // Get the player's move
        printf("Enter your move (1-7): ");
        scanf("%d", &k);

        // Validate the move
        if (k < 1 || k > 7)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece on the board
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'O';
                    break;
                }
            }
        }

        // Check if the player has won
        for (l = 0; l < 6; l++)
        {
            // Check rows
            for (i = 0; i < 6; i++)
            {
                if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == 'O')
                {
                    score = 1;
                    break;
                }
            }

            // Check columns
            for (j = 0; j < 6; j++)
            {
                if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] == 'O')
                {
                    score = 1;
                    break;
                }
            }

            // Check diagonals
            if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == 'O')
            {
                score = 1;
            }

            // Check if the board is full
            if (board[5][5] == 'O')
            {
                highScore = 1;
            }
        }

        // Print the board
        printf("Board:\n");
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }

    // End game message
    printf("Game over! The winner is: ");
    if (score == 1)
    {
        printf("You!\n");
    }
    else
    {
        printf("Computer.\n");
    }

    return 0;
}