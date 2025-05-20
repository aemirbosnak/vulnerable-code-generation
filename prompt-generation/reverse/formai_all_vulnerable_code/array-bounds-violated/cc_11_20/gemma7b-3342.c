//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Define the game board
    int board[3][3] = {{0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0}};

    // Initialize the player's move
    int move = 0;

    // Loop until the game is over
    while (!board[1][1] && move < 9)
    {
        // Get the player's move
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        // Validate the move
        if (move < 1 || move > 9)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the player's mark on the board
        board[move / 3][move % 3] = 1;

        // Check if the player has won
        if (board[0][0] == 1 || board[0][1] == 1 || board[0][2] == 1 ||
            board[1][0] == 1 || board[1][1] == 1 || board[1][2] == 1 ||
            board[2][0] == 1 || board[2][1] == 1 || board[2][2] == 1)
        {
            printf("You have won!\n");
            break;
        }

        // If the board is full, it's a draw
        if (move == 9)
        {
            printf("It's a draw.\n");
            break;
        }

        // Next move
        move++;
    }

    // Print the game board
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}