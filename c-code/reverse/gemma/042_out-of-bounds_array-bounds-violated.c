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
    int move_count = 0;

    // Loop until the game is over
    while (!board[2][2] && move_count < 9)
    {
        // Get the computer's move
        int move_x = rand() % 3;
        int move_y = rand() % 3;

        // Check if the move is valid
        if (board[move_x][move_y] != 0)
        {
            // If the move is not valid, try again
            continue;
        }

        // Make the move
        board[move_x][move_y] = player;
        move_count++;

        // Switch player
        player *= -1;
    }

    // Print the winner or draw
    if (board[2][2] == player)
    {
        printf("You win!");
    }
    else if (move_count == 9)
    {
        printf("Draw!");
    }
    else
    {
        printf("Computer wins!");
    }

    return 0;
}
