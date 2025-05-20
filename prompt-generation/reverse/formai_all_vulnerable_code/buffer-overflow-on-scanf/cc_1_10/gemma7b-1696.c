//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void playGame()
{
    int board[MAX_SIZE][MAX_SIZE] = {{0}};
    int player1 = 1, player2 = 2;
    int row, column, move, found = 0;

    // Initialize the board
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Place the first move
    board[4][4] = player1;

    // Game loop
    while (!found)
    {
        // Get the move
        printf("Enter move (row, column): ");
        scanf("%d %d", &row, &column);

        // Validate the move
        if (row < 0 || row >= MAX_SIZE || column < 0 || column >= MAX_SIZE)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Check if the move is valid
        if (board[row][column] != 0)
        {
            printf("Move already taken. Please try again.\n");
            continue;
        }

        // Make the move
        board[row][column] = player1;

        // Check if the player has won
        if (board[row][column] == player1)
        {
            found = 1;
            printf("Congratulations, Player %d, you won!\n", player1);
        }
    }

    // End of the game
    printf("Thank you for playing. Goodbye!\n");
}

int main()
{
    playGame();

    return 0;
}