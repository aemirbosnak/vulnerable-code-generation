//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

#define BULLET_WIDTH 5
#define BULLET_HEIGHT 1

#define SHIP_WIDTH 3
#define SHIP_HEIGHT 5

#define SHIP_SPEED 5
#define BULLET_SPEED 3

int main()
{
    // Initialize the game board
    int board[MAX_HEIGHT][MAX_WIDTH] = {0};

    // Place the ship in the center of the board
    board[MAX_HEIGHT / 2][MAX_WIDTH / 2] = 1;

    // Initialize the bullets
    int bullets[MAX_HEIGHT][MAX_WIDTH] = {0};

    // Initialize the clock
    time_t start_time = time(NULL);

    // Game loop
    while (!board[0][MAX_WIDTH - 1] && time(NULL) - start_time < 60)
    {
        // Move the bullets
        for (int y = 0; y < MAX_HEIGHT; y++)
        {
            for (int x = 0; x < MAX_WIDTH; x++)
            {
                if (bullets[y][x] && bullets[y][x] != -1)
                {
                    bullets[y][x] += BULLET_SPEED * time(NULL) - start_time;
                    if (bullets[y][x] > MAX_WIDTH - 1)
                    {
                        bullets[y][x] = -1;
                    }
                }
            }
        }

        // Move the ship
        int direction = rand() % 2;
        if (direction == 0)
        {
            board[MAX_HEIGHT / 2][MAX_WIDTH / 2 - SHIP_SPEED] = 1;
            board[MAX_HEIGHT / 2][MAX_WIDTH / 2] = 0;
        }
        else
        {
            board[MAX_HEIGHT / 2][MAX_WIDTH / 2 + SHIP_SPEED] = 1;
            board[MAX_HEIGHT / 2][MAX_WIDTH / 2] = 0;
        }

        // Check if the ship has been destroyed
        if (board[0][MAX_WIDTH - 1] == 1)
        {
            printf("Game over!\n");
            break;
        }

        // Draw the game board
        for (int y = 0; y < MAX_HEIGHT; y++)
        {
            for (int x = 0; x < MAX_WIDTH; x++)
            {
                printf("%c ", board[y][x] ? '*' : '.');
            }
            printf("\n");
        }

        // Sleep for a while
        sleep(1);
    }

    return 0;
}