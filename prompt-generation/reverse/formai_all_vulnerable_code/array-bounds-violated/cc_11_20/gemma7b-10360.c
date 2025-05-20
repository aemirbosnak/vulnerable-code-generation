//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int main()
{
    // Game variables
    int score = 0;
    int lives = 3;
    int direction = RIGHT;
    int x = 0;
    int y = 0;

    // Initialize the grid
    int grid[ROWS][COLS] = {0};

    // Place the invader
    grid[y][x] = 1;

    // Game loop
    while (lives > 0)
    {
        // Draw the grid
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                printf("%c ", grid[r][c] ? '#' : '.');
            }
            printf("\n");
        }

        // Move the invader
        switch (direction)
        {
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            case RIGHT:
                x++;
                break;
            case LEFT:
                x--;
                break;
        }

        // Check if the invader has reached the border
        if (x < 0 || x >= COLS - 1)
        {
            direction = UP;
        }
        if (y < 0)
        {
            direction = RIGHT;
        }

        // Check if the invader has collided with the border
        if (grid[y][x] == 1)
        {
            lives--;
        }

        // Increment the score
        score++;

        // Sleep for a while
        sleep(0.5);
    }

    // Game over
    printf("Game over! Your score is: %d", score);

    return 0;
}