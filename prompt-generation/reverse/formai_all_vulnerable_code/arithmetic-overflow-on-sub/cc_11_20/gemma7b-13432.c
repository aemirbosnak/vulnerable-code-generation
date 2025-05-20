//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 21
#define PADDLE_SIZE 5

int main()
{
    int board[BOARD_SIZE] = { 0 };
    int paddle[PADDLE_SIZE] = { 0 };
    int player_pos = 0;
    int ai_pos = BOARD_SIZE - 1 - PADDLE_SIZE;
    int ball_x = BOARD_SIZE / 2;
    int ball_y = PADDLE_SIZE / 2;
    int direction = 1;

    time_t start_time = time(NULL);
    clock_t time_elapsed = 0;

    while (!board[ball_x] || board[ball_y])
    {
        time_elapsed = clock() - start_time;
        if (time_elapsed > 100)
        {
            start_time = clock();
            direction *= -1;
            ball_x = (rand() % 2) ? BOARD_SIZE - 1 : 0;
            ball_y = rand() % PADDLE_SIZE;
        }

        if (board[ball_x] || board[ball_y] || ball_x == 0 || ball_x == BOARD_SIZE - 1)
        {
            direction *= -1;
        }

        if (ball_x < player_pos)
        {
            board[ball_x] = 1;
            ball_x++;
        }
        else if (ball_x > ai_pos)
        {
            board[ball_x] = 1;
            ball_x--;
        }

        if (ball_y < paddle[player_pos] || ball_y > paddle[player_pos] + PADDLE_SIZE - 1)
        {
            direction *= -1;
        }

        board[ball_x] = board[ball_y] = 1;
        ball_y++;
    }

    printf("Game Over!");
    return 0;
}