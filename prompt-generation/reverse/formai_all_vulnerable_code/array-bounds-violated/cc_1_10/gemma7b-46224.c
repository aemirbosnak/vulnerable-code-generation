//Gemma-7B DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Game board setup
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    // Player pieces placement
    board[2][2] = 1;
    board[3][3] = 2;

    // Game turn
    int turn = 1;

    // Game loop
    while (!board[4][4] && turn <= 10)
    {
        // Get player's move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Validate move
        if (board[row][col] != 0)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place piece
        board[row][col] = turn;

        // Check if player has won
        if (board[row][col] == turn && board[row][col] == board[4][4])
        {
            printf("Congratulations! You have won!\n");
            break;
        }

        // Next turn
        turn++;
    }

    // Game over
    if (board[4][4] == 0)
    {
        printf("It's a draw. No one won.\n");
    }

    return 0;
}