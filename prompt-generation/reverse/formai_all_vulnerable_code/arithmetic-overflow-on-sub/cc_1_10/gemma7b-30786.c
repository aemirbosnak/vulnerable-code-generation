//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 11

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int main()
{

    // Define the grid
    int grid[ROWS][COLS] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Define the invader
    int invader_x = 0;
    int invader_y = 0;

    // Initialize the timer
    time_t start_time = time(NULL);

    // Game loop
    while (!grid[invader_y][invader_x] && time(NULL) - start_time < 60)
    {
        // Move the invader
        switch (rand() % 4)
        {
            case UP:
                invader_y--;
                break;
            case DOWN:
                invader_y++;
                break;
            case RIGHT:
                invader_x++;
                break;
            case LEFT:
                invader_x--;
                break;
        }

        // Draw the grid
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                printf("%c ", grid[r][c] ? '#' : '.');
            }
            printf("\n");
        }

        // Update the invader's position
        grid[invader_y][invader_x] = 1;

        // Sleep for a while
        sleep(0.1);
    }

    // Game over
    printf("Game over!");

    return 0;
}