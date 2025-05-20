//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 20

int main()
{
    int x1 = WIDTH / 2, y1 = HEIGHT - 1, x2 = WIDTH / 2, y2 = 0;
    char direction1 = 'R', direction2 = 'L';
    int score1 = 0, score2 = 0;
    char board[HEIGHT][WIDTH] = {{0}};

    board[y1][x1] = 'O';
    board[y2][x2] = 'O';

    srand(time(NULL));

    while (score1 < 5 && score2 < 5)
    {
        int r = rand() % 3;

        switch (r)
        {
            case 0:
                direction1 = 'R';
                break;
            case 1:
                direction1 = 'L';
                break;
            case 2:
                direction1 = 'U';
                break;
            default:
                direction1 = 'D';
                break;
        }

        switch (direction1)
        {
            case 'R':
                x1++;
                break;
            case 'L':
                x1--;
                break;
            case 'U':
                y1--;
                break;
            case 'D':
                y1++;
                break;
            default:
                break;
        }

        board[y1][x1] = 'O';

        if (x1 >= WIDTH - 1)
        {
            direction1 = 'L';
            score1++;
        }
        else if (x1 <= 0)
        {
            direction1 = 'R';
            score1++;
        }

        if (board[y2][x2] == 'O')
        {
            direction2 = 'U';
        }

        switch (direction2)
        {
            case 'R':
                x2++;
                break;
            case 'L':
                x2--;
                break;
            case 'U':
                y2--;
                break;
            case 'D':
                y2++;
                break;
            default:
                break;
        }

        board[y2][x2] = 'O';

        if (x2 >= WIDTH - 1)
        {
            direction2 = 'L';
            score2++;
        }
        else if (x2 <= 0)
        {
            direction2 = 'R';
            score2++;
        }

        system("clear");

        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        printf("Score: %d - %d\n", score1, score2);
    }

    return 0;
}