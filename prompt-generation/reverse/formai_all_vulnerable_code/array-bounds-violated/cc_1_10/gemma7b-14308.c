//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DELAY 0

int main()
{
    char board[10][10] = {{0}};
    int x, y, i, j, score = 0, game_over = 0;
    time_t t;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            board[i][j] = 0;
        }
    }

    board[5][5] = 1;

    printf("Welcome to the Paranoiac Breakout Game!\n");
    printf("------------------------\n");

    t = time(NULL);
    while (!game_over)
    {
        printf("Enter the coordinates of the ball (x, y): ");
        scanf("%d %d", &x, &y);

        if (board[x][y] == 1)
        {
            printf("The ball is already there!\n");
            continue;
        }

        board[x][y] = 1;

        if (x == 9 || x == 0)
        {
            game_over = 1;
            printf("Game Over! Your score: %d", score);
        }

        if (y == 9)
        {
            score++;
            printf("You have cleared a row! Your score: %d", score);
        }

        sleep(DELAY);
    }

    return 0;
}