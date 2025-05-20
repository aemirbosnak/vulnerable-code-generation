//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int board[MAX_SIZE][MAX_SIZE];
    int i, j, x, y, move = 0, player = 1;
    char symbol;

    // Initialize the board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    while (!board[x][y] && move < MAX_SIZE * MAX_SIZE)
    {
        // Get the move
        printf("Enter move (x, y): ");
        scanf("%d %d", &x, &y);

        // Validate the move
        if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the move
        board[x][y] = player;

        // Increment the move counter
        move++;

        // Switch players
        player = (player == 1) ? 2 : 1;

        // Display the board
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                printf("%c ", board[i][j] == 1 ? 'X' : board[i][j] == 2 ? 'O' : '.');
            }
            printf("\n");
        }

        // Check if the player has won
        if (board[x][y] == player && board[x][y] * MAX_SIZE == move)
        {
            printf("Congratulations! You have won!\n");
            break;
        }
    }

    // Game over
    if (move == MAX_SIZE * MAX_SIZE)
    {
        printf("It's a draw.\n");
    }

    return 0;
}