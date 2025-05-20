//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 5
#define MAX_HEIGHT 5
#define BLOCK_SIZE 20

int main()
{
    int board[MAX_HEIGHT][MAX_WIDTH] = {{0, 0, 0, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 1, 0},
                                {0, 0, 0, 0, 0}};

    int paddle_x = 0;
    int paddle_y = MAX_HEIGHT - 1;

    int ball_x = MAX_WIDTH / 2;
    int ball_y = MAX_HEIGHT - 1;

    int direction = 1;

    while (!board[ball_y][ball_x] && ball_x >= 0 && ball_x < MAX_WIDTH && ball_y >= 0)
    {
        switch (direction)
        {
            case 1:
                ball_x++;
                break;
            case 2:
                ball_x--;
                break;
            case 3:
                ball_y--;
                break;
            case 4:
                ball_y++;
                break;
        }

        if (board[ball_y][ball_x] == 1)
        {
            board[ball_y][ball_x] = 0;
            direction = (rand() % 2) + 1;
        }

        if (board[paddle_y][paddle_x] == 1 && ball_x == paddle_x)
        {
            board[paddle_y][paddle_x] = 0;
            direction = 3;
        }

        printf("\033[2J");
        for (int h = 0; h < MAX_HEIGHT; h++)
        {
            for (int w = 0; w < MAX_WIDTH; w++)
            {
                printf("%c ", board[h][w] ? '#' : '.');
            }
            printf("\n");
        }

        printf("Paddle: (%d, %d)\n", paddle_x, paddle_y);
        printf("Ball: (%d, %d)\n", ball_x, ball_y);

        sleep(0.1);
    }

    printf("Game Over!");

    return 0;
}