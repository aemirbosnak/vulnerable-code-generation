//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIVES 5

int main()
{
    int lives = MAX_LIVES;
    char board[2][3] = {{' ', ' ', ' '}, {'*', ' ', ' '}};
    int x = 0, y = 0, direction = 1;

    // Game Loop
    while (lives > 0)
    {
        // Display Board
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Move Paddle
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

        // Check Boundaries
        if (x < 0 || x >= 3)
        {
            direction = 3;
        }
        if (y < 0)
        {
            direction = 2;
        }

        // Check Collision
        if (board[y][x] == '*')
        {
            lives--;
            board[y][x] = ' ';
        }

        // Update Board
        board[y][x] = 'P';

        // Sleep
        sleep(0.5);
    }

    // Game Over
    printf("Game Over!");

    return 0;
}