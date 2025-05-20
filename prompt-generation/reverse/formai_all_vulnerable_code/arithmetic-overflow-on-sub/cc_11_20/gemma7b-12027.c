//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2
#define PADDLE_SIZE 4

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                                {0, 0, 0, BALL_SIZE, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

    int paddle_x = 0;
    int paddle_y = BOARD_SIZE - 1;

    int ball_x = BOARD_SIZE / 2;
    int ball_y = BOARD_SIZE - 1;

    int direction = 1;

    time_t t = time(NULL);

    while (!board[ball_y][ball_x] && time(NULL) - t < 60)
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

        if (board[ball_y][ball_x] == BALL_SIZE)
        {
            board[ball_y][ball_x] = 0;
            direction *= -1;
        }

        if (board[ball_y][ball_x] == PADDLE_SIZE)
        {
            board[ball_y][ball_x] = 0;
            direction *= -1;
            paddle_x = ball_x;
        }

        if (ball_x < 0 || ball_x >= BOARD_SIZE)
        {
            direction = 2;
        }

        if (ball_y < 0)
        {
            direction = 4;
        }

        system("clear");
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        printf("Paddle: (%d, %d)\n", paddle_x, paddle_y);
        printf("Ball: (%d, %d)\n", ball_x, ball_y);

        sleep(0.1);
    }

    return 0;
}