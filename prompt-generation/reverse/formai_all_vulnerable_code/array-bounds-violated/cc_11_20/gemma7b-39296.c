//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 5
#define MAX_HEIGHT 5

int main()
{
    int board[MAX_WIDTH][MAX_HEIGHT] = {{0, 1, 0, 1, 0},
                                {0, 1, 1, 1, 0},
                                {0, 0, 0, 1, 0},
                                {0, 1, 0, 1, 0},
                                {0, 0, 0, 0, 0}};

    int x = 0, y = 0, direction = 1;

    // Game loop
    while (!board[x][y] || direction == 1)
    {
        // Move the paddle
        switch (direction)
        {
            case 1:
                y++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x++;
                break;
            case 4:
                x--;
                break;
        }

        // Check if the paddle has reached the border
        if (x < 0 || x >= MAX_WIDTH - 1)
        {
            direction = 3;
        }
        else if (y < 0 || y >= MAX_HEIGHT - 1)
        {
            direction = 2;
        }

        // Check if the paddle has hit a brick
        if (board[x][y] == 1)
        {
            board[x][y] = 0;
            direction = 4;
        }

        // Print the board
        for (int i = 0; i < MAX_WIDTH; i++)
        {
            for (int j = 0; j < MAX_HEIGHT; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Sleep for a while
        sleep(0.1);
    }

    // Game over
    printf("Game over!");

    return 0;
}