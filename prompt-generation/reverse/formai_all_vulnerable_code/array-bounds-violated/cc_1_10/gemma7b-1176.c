//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_BOUND 0
#define RIGHT_BOUND 5

int main()
{
    int x, y, score, direction, speed;
    char board[6][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Initialize variables
    x = 2;
    y = 3;
    score = 0;
    direction = 1;
    speed = 1;

    // Game loop
    while (!board[y][x] && score < 10)
    {
        // Move invader
        x += direction * speed;

        // Check boundaries
        if (x < LEFT_BOUND)
        {
            direction = 1;
        }
        else if (x > RIGHT_BOUND)
        {
            direction = -1;
        }

        // Update board
        board[y][x] = 1;

        // Draw board
        for (y = 0; y < 6; y++)
        {
            for (x = 0; x < 10; x++)
            {
                printf("%c ", board[y][x] ? '#' : '.');
            }
            printf("\n");
        }

        // Score increment
        if (board[y-1][x] == 1)
        {
            score++;
        }

        // Sleep
        sleep(0.2);
    }

    // Game over
    printf("Game over! Your score is: %d", score);

    return 0;
}