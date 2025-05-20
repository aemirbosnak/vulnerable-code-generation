//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int turn = 0;
    char player_symbol = 'X';

    // Game Loop
    while (!board[1][1] && turn < 9)
    {
        // Get the player's move
        int row, column;
        printf("Enter row (1-3): ");
        scanf("%d", &row);

        printf("Enter column (1-3): ");
        scanf("%d", &column);

        // Check if the move is valid
        if (board[row][column] != 0)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        board[row][column] = player_symbol;

        // Switch turns
        turn++;
        player_symbol = (player_symbol == 'X') ? 'O' : 'X';
    }

    // Check if the player won or it's a draw
    if (board[1][1] == player_symbol)
    {
        printf("You won!");
    }
    else if (turn == 9)
    {
        printf("It's a draw!");
    }
    else
    {
        printf("Invalid move. Game over.");
    }

    return 0;
}