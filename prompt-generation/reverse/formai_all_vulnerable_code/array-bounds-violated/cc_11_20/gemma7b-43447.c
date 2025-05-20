//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Define the game board
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0}};

    // Place the initial bomb
    board[2][2] = 1;

    // Display the game board
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Get the player's move
    int move_r, move_c;
    printf("Enter the row and column of your move (separate with a space): ");
    scanf("%d %d", &move_r, &move_c);

    // Check if the move is valid
    if (move_r < 0 || move_r >= 6)
    {
        printf("Invalid move.\n");
    }
    else if (move_c < 0 || move_c >= 6)
    {
        printf("Invalid move.\n");
    }
    else if (board[move_r][move_c] != 0)
    {
        printf("Invalid move.\n");
    }

    // Place the player's mark on the board
    board[move_r][move_c] = 2;

    // Display the updated game board
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Check if the player has won
    if (board[0][0] == 2 || board[0][5] == 2 || board[5][0] == 2 || board[5][5] == 2)
    {
        printf("You have won!\n");
    }
    else
    {
        printf("You have lost.\n");
    }

    return 0;
}