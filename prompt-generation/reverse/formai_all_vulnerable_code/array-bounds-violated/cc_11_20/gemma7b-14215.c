//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_BOUND 0
#define RIGHT_BOUND 5

#define ROW_SIZE 5
#define COL_SIZE 10

#define SHIP_SIZE 3
#define BULLET_SIZE 1

int main()
{
    // Game setup
    int score = 0;
    int lives = 3;
    char board[ROW_SIZE][COL_SIZE] = {{0}};
    int ship[SHIP_SIZE] = {0, 0, 0};
    int bullets[BULLET_SIZE] = {0, 0, 0};
    int direction = 1;
    time_t timer = time(NULL);

    // Game loop
    while (lives > 0 && score < 100)
    {
        // Draw the board
        for (int r = 0; r < ROW_SIZE; r++)
        {
            for (int c = 0; c < COL_SIZE; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Move the ship
        ship[0] += direction * 2;
        if (ship[0] < LEFT_BOUND || ship[0] > RIGHT_BOUND)
        {
            direction *= -1;
        }

        // Shoot bullets
        if (time(NULL) - timer >= 0.5)
        {
            bullets[0] = ship[0] + 1;
            bullets[1] = ship[0] + 1;
            bullets[2] = ship[0] + 1;
            timer = time(NULL);
        }

        // Check for collisions
        for (int b = 0; b < BULLET_SIZE; b++)
        {
            if (bullets[b] >= 0 && bullets[b] < COL_SIZE && board[bullets[b]][ship[0]] == '#')
            {
                board[bullets[b]][ship[0]] = 'X';
                bullets[b] = -1;
                ship[0] = -1;
                lives--;
            }
        }

        // Update the board
        board[ship[0]][ship[1]] = 'S';

        // Increment score
        if (ship[0] >= RIGHT_BOUND)
        {
            score++;
        }
    }

    // Game over
    printf("Game over! Your score: %d", score);

    return 0;
}