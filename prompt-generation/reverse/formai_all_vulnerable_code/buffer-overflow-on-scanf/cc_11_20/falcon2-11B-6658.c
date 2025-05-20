//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int board[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int player, cpu, turn = 1;
    int win = 0;
    int i, j;

    srand(time(NULL));

    printf("Welcome to Tic Tac Toe!\n");

    while (win == 0)
    {
        printf("\nPlayer %d's turn.\n", turn);
        scanf("%d %d", &i, &j);

        if (board[i][j] == 1)
        {
            printf("Invalid input. Please try again.\n");
        }
        else if (board[i][j] == 2)
        {
            printf("Invalid input. Please try again.\n");
        }
        else
        {
            board[i][j] = turn;

            if (turn == 1)
            {
                cpu = rand() % 2 + 1;
            }
            else
            {
                cpu = 3 - (rand() % 2 + 1);
            }

            turn = 2 - turn;
            if (cpu == 1)
            {
                i = rand() % 3 + 1;
                j = rand() % 3 + 1;
            }
            else
            {
                i = 3 - (rand() % 3 + 1);
                j = 3 - (rand() % 3 + 1);
            }

            board[i][j] = cpu;

            if (check_win(board, turn) == 1)
            {
                printf("Player %d wins!\n", turn);
                win = 1;
            }
            else if (check_win(board, 3 - turn) == 1)
            {
                printf("CPU wins!\n");
                win = 1;
            }

            if (check_tie(board) == 1)
            {
                printf("It's a tie!\n");
                win = 1;
            }
        }
    }

    printf("\nThanks for playing!\n");

    return 0;
}

int check_win(int board[3][3], int player)
{
    int i, j;

    if (board[0][0] == player && board[0][1] == player && board[0][2] == player)
    {
        return 1;
    }

    if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
    {
        return 1;
    }

    if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
    {
        return 1;
    }

    if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
    {
        return 1;
    }

    if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
    {
        return 1;
    }

    if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
    {
        return 1;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }

    return 0;
}

int check_tie(int board[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}