#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int move = 0;

    // Loop until the game is over
    while (!board[2][2] && move < 9)
    {
        // Get the user's move
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        // Check if the move is valid
        if (move < 1 || move > 9)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        board[move / 3][move % 3] = player;

        // Increment the move counter
        move++;

        // Check if the player has won
        if (board[2][2] == player)
        {
            printf("You win!\n");
        }
        else
        {
            // Switch to the next player
            player = (player == 1) ? 2 : 1;
        }
    }

    // If the game is a draw
    if (move == 9 && board[2][2] == 0)
    {
        printf("It's a draw.\n");
    }

    return 0;
}
