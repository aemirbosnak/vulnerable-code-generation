//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");

    // Create a 2D array of characters to represent the game board
    char board[4][4] = {{'1', '2', '3', '4',
                              '5', '6', '7', '8',
                              '9', '0', 'a', 'b',
                              'c', 'd', 'e', 'f'}};

    // Initialize the player's move
    int move = 0;

    // Loop until the game is over
    while (move < 9)
    {
        // Get the player's move
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        // Check if the move is valid
        if (move < 1 || move > 9)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Mark the move on the board
        board[move / 4][move % 4] = 'x';

        // Print the board
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Check if the player has won
        if (board[0][0] == 'x' || board[0][1] == 'x' || board[0][2] == 'x' ||
            board[1][0] == 'x' || board[1][1] == 'x' || board[1][2] == 'x' ||
            board[2][0] == 'x' || board[2][1] == 'x' || board[2][2] == 'x')
        {
            printf("You have won!\n");
            break;
        }

        // If the board is full, it's a draw
        else if (move == 9)
        {
            printf("It's a draw!\n");
            break;
        }

        // Increment the move counter
        move++;
    }

    // Print the final board
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return;
}