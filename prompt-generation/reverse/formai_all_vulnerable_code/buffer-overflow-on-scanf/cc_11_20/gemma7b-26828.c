//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIVES 3

int main()
{
    int lives = MAX_LIVES;
    char board[3][3] = {'*', ' ', ' ',
                              '*', ' ', ' ',
                              ' ', ' ', '*'};

    // Game loop
    while (lives > 0)
    {
        // Print the board
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Get the user's move
        int move_r, move_c;
        printf("Enter row: ");
        scanf("%d", &move_r);
        printf("Enter column: ");
        scanf("%d", &move_c);

        // Validate the move
        if (move_r < 0 || move_r >= 3)
        {
            printf("Invalid move.\n");
            continue;
        }
        if (move_c < 0 || move_c >= 3)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is a win or a loss
        if (board[move_r][move_c] == '*')
        {
            printf("You win!\n");
            break;
        }
        else
        {
            board[move_r][move_c] = '*';
            lives--;
            printf("You lose a life.\n");
        }
    }

    // Print the final board
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }

    // Game over message
    printf("Game over.\n");

    return 0;
}