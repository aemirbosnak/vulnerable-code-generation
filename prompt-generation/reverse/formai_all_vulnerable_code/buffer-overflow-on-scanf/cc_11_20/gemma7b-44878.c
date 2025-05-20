//Gemma-7B DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, score = 0;
    char name[20];
    char board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Welcome, %s! Let's play a game of Tic-Tac-Toe!\n", name);

    // Game loop
    while (score == 0)
    {
        // Player's turn
        printf("It's your turn, %s. Enter the row and column of the square you want to mark (1-5): ", name);
        scanf("%d %d", &i, &j);

        // Check if the square is free
        if (board[i][j] == 0)
        {
            // Mark the square
            board[i][j] = 1;

            // Check if the player has won
            for (k = 0; k < 6; k++)
            {
                // Check if the player has won in a row
                for (l = 0; l < 6; l++)
                {
                    if (board[k][l] == 1 && board[k][l] == board[i][j])
                    {
                        score = 1;
                        printf("Congratulations, %s! You have won!\n", name);
                        break;
                    }
                }

                // Check if the player has won in a column
                for (m = 0; m < 6; m++)
                {
                    if (board[m][j] == 1 && board[m][j] == board[i][j])
                    {
                        score = 1;
                        printf("Congratulations, %s! You have won!\n", name);
                        break;
                    }
                }
            }

            // If the player has not won, check if the board is full
            if (score == 0 && board[0][0] != 0)
            {
                score = 1;
                printf("It's a draw! No one won.\n");
            }
        }
        else
        {
            printf("Sorry, that square is already taken.\n");
        }
    }

    return 0;
}