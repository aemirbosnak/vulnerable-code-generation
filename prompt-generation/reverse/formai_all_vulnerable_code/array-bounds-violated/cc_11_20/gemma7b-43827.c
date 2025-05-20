//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                                {0, 1, 1, 1, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

    int ball_x = 2;
    int ball_y = 1;
    int direction = 1;

    while (1)
    {
        // Draw the board
        for (int y = 0; y < BOARD_SIZE; y++)
        {
            for (int x = 0; x < BOARD_SIZE; x++)
            {
                if (board[y][x] == 1)
                {
                    printf("%c ", '*');
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Move the ball
        switch (direction)
        {
            case 1:
                ball_x++;
                break;
            case 2:
                ball_x--;
                break;
            case 3:
                ball_y++;
                break;
            case 4:
                ball_y--;
                break;
        }

        // Check if the ball has reached a border
        if (ball_x == BOARD_SIZE - 1 || ball_x == 0)
        {
            direction = direction * -1;
        }
        if (ball_y == BOARD_SIZE - 1 || ball_y == 0)
        {
            direction = direction * -1;
        }

        // Update the board
        board[ball_y][ball_x] = 1;

        // Sleep for a bit
        sleep(0.1);
    }

    return 0;
}