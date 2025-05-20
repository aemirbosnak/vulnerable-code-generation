//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 6
#define WIDTH 8

#define BALL_SIZE 10
#define PADDLE_SIZE 20

int main()
{
    int board[HEIGHT][WIDTH] = {{0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0}};

    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT - 1;
    int paddle_x = 0;
    int paddle_y = HEIGHT - 1;

    char direction = 'r';

    while (!board[ball_y][ball_x] || board[paddle_y][paddle_x] == 1)
    {
        switch (direction)
        {
            case 'r':
                ball_x++;
                break;
            case 'l':
                ball_x--;
                break;
            case 'u':
                ball_y--;
                break;
            case 'd':
                ball_y++;
                break;
        }

        if (board[ball_y][ball_x] == 1)
        {
            direction = 'u';
            ball_y--;
        }

        if (board[paddle_y][paddle_x] == 1 && ball_x == paddle_x)
        {
            direction = 'u';
            ball_y--;
        }

        board[ball_y][ball_x] = 1;
        board[paddle_y][paddle_x] = 1;

        system("clear");
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                printf("%c ", board[y][x] ? '#' : '.');
            }
            printf("\n");
        }

        printf("Ball: (%d, %d)\n", ball_x, ball_y);
        printf("Paddle: (%d, %d)\n", paddle_x, paddle_y);
        printf("Direction: %c\n", direction);

        sleep(0.1);
    }

    return 0;
}