//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    time_t t = time(NULL);
    srand(t);

    int n = rand() % 10 + 1;
    char board[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '-';
        }
    }

    board[rand() % n][rand() % n] = 'o';

    int score = 0;
    int game_over = 0;

    while (!game_over)
    {
        char move;

        printf("Enter your move (e.g. 'a1', 'b2', 'c3'): ");
        scanf("%c", &move);

        switch (move)
        {
            case 'a':
                board[0][0] = 'o';
                break;
            case 'b':
                board[0][1] = 'o';
                break;
            case 'c':
                board[0][2] = 'o';
                break;
            case 'd':
                board[1][0] = 'o';
                break;
            case 'e':
                board[1][1] = 'o';
                break;
            case 'f':
                board[1][2] = 'o';
                break;
            case 'g':
                board[2][0] = 'o';
                break;
            case 'h':
                board[2][1] = 'o';
                break;
            case 'i':
                board[2][2] = 'o';
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        if (board[rand() % n][rand() % n] == 'o')
        {
            score++;
            printf("You scored a point!\n");
        }

        if (score == n * n)
        {
            game_over = 1;
            printf("Congratulations! You won!\n");
        }
    }

    return;
}