//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

int main()
{
    int x, y, i, j, score = 0;
    char board[MAX_WIDTH][MAX_HEIGHT] = {0};

    // Initialize the board
    for (i = 0; i < MAX_WIDTH; i++)
    {
        for (j = 0; j < MAX_HEIGHT; j++)
        {
            board[i][j] = '-';
        }
    }

    // Place the invader
    board[5][0] = 'I';

    // Game loop
    while (board[5][MAX_HEIGHT - 1] != 'O')
    {
        // Move the invader
        board[5][y] = '-';
        board[5][y - 1] = 'I';

        // Check if the invader has reached the border
        if (board[5][y - 1] == 'O')
        {
            // Game over
            printf("Game over! Your score is: %d", score);
            break;
        }

        // Get the next move
        printf("Enter the next move (x, y): ");
        scanf("%d %d", &x, &y);

        // Validate the move
        if (x < 0 || x >= MAX_WIDTH || y < 0 || y >= MAX_HEIGHT)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place the invader
        board[x][y] = 'I';

        // Increment the score
        score++;
    }

    return 0;
}