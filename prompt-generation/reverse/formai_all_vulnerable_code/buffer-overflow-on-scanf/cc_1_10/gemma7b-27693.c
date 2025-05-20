//Gemma-7B DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

void play_game(int **board, int player)
{
    int row, col;
    printf("Enter row and column (1-%d): ", MAX_NUM);
    scanf("%d %d", &row, &col);

    if (board[row][col] == 0)
    {
        board[row][col] = player;
        printf("Move accepted.\n");
    }
    else
    {
        printf("Move not accepted. Space already occupied.\n");
    }
}

int main()
{
    int board[MAX_NUM][MAX_NUM] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int player = 1;

    while (!board[5][5])
    {
        play_game(board, player);
        player *= -1;
    }

    printf("Game over! The winner is: ");
    if (board[5][5] == 1)
    {
        printf("Player 1\n");
    }
    else
    {
        printf("Player 2\n");
    }

    return 0;
}