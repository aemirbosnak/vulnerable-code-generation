//Gemma-7B DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, j, k, l, m, score = 0, game_over = 0;
    char board[6][6] = {{' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '}};

    // Game setup
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Enter the number of players (2-4): ");
    scanf("%d", &n);

    // Game loop
    while (!game_over)
    {
        // Get the player's move
        printf("Enter the row and column of your move (1-5): ");
        scanf("%d %d", &i, &j);

        // Check if the move is valid
        if (board[i][j] != ' ' && board[i][j] != 'O')
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        board[i][j] = 'O';

        // Check if the player has won
        for (k = 0; k < 6; k++)
        {
            for (l = 0; l < 6; l++)
            {
                if (board[k][l] == 'O' && board[k][l] == board[k][0] && board[k][l] == board[0][l])
                {
                    score++;
                    game_over = 1;
                    break;
                }
            }
        }

        // If the player has not won, check if the board is full
        if (!game_over)
        {
            for (m = 0; m < 6; m++)
            {
                for (n = 0; n < 6; n++)
                {
                    if (board[m][n] == ' ')
                    {
                        game_over = 0;
                        break;
                    }
                }
            }

            // If the board is full, it's a draw
            if (game_over)
            {
                score++;
                printf("It's a draw!\n");
            }
        }
    }

    // Game over
    printf("Thank you for playing! Your score is: %d\n", score);
}