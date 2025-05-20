//Gemma-7B DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the game board
    char board[6][6] = {
        {'1', '2', '3', '4', '5', '6'},
        {'7', '8', '9', '10', '11', '12'},
        {'13', '14', '15', '16', '17', '18'},
        {'19', '20', '21', '22', '23', '24'},
        {'25', '26', '27', '28', '29', '30'},
        {'31', '32', '33', '34', '35', '36'}
    };

    // Initialize the player's move
    int move = 0;

    // Loop until the game is over
    while (move < 3)
    {
        // Get the player's move
        printf("Enter your move: ");
        scanf("%d", &move);

        // Validate the move
        if (move < 1 || move > 36)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Mark the move on the board
        board[move / 6][move % 6] = 'X';

        // Increment the player's move
        move++;
    }

    // Print the game board
    printf("The game board is:\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Check if the player won or lost
    if (board[0][0] == 'X' || board[0][1] == 'X' || board[0][2] == 'X' ||
        board[1][0] == 'X' || board[1][1] == 'X' || board[1][2] == 'X' ||
        board[2][0] == 'X' || board[2][1] == 'X' || board[2][2] == 'X')
    {
        printf("You won!\n");
    }
    else
    {
        printf("You lost.\n");
    }

    return 0;
}