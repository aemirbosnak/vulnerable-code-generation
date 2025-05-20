//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define LEFT_BOUND 0
#define RIGHT_BOUND 80

int main()
{
    int x = 20, y = 10;
    char board[20][10] = {'#'};

    // Draw the initial board
    board[x][y] = 'O';
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Game loop
    while (1)
    {
        // Get the direction of the invader
        int direction = rand() % 2;

        // Move the invader
        switch (direction)
        {
            case 0:
                x--;
                break;
            case 1:
                x++;
                break;
        }

        // Check if the invader has reached a boundary
        if (x < LEFT_BOUND || x > RIGHT_BOUND)
        {
            break;
        }

        // Update the board
        board[x][y] = 'O';
        board[x][y - 1] = '#';

        // Draw the updated board
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}