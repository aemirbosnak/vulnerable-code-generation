//FormAI DATASET v1.0 Category: Checkers Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY ' '
#define SIZE 8

void init_board(char board[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (i < 3)
                board[i][j] = BLACK;
            else if (i > 4)
                board[i][j] = WHITE;
            else
                board[i][j] = EMPTY;
        }
    }
}

void print_board(char board[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
}

int valid_move(char player, int start_x, int start_y, int end_x, int end_y)
{
    // check if the move is in bounds
    if (end_x < 0 || end_x >= SIZE || end_y < 0 || end_y >= SIZE)
        return 0;

    // check if there is a piece at the starting position
    if (player == BLACK && start_x >= 3)
    {
        if (start_x - end_x != 1 || abs(start_y - end_y) != 1)
            return 0;
    }
    else if (player == WHITE && start_x <= 4)
    {
        if (end_x - start_x != 1 || abs(start_y - end_y) != 1)
            return 0;
    }
    else
    {
        if (abs(start_x - end_x) != 1 || abs(start_y - end_y) != 1)
            return 0;
    }

    // check if there is a piece at the ending position
    if (player == BLACK && end_x < start_x)
        return 0;
    if (player == WHITE && end_x > start_x)
        return 0;

    return 1;
}

int main()
{
    char board[SIZE][SIZE];
    char player = BLACK;
    int start_x, start_y, end_x, end_y;
    int i, j;

    init_board(board);
    print_board(board);

    while (1)
    {
        printf("%c's turn\n", player);
        printf("Enter start position (x y): ");
        scanf("%d %d", &start_x, &start_y);
        printf("Enter end position (x y): ");
        scanf("%d %d", &end_x, &end_y);

        if (valid_move(player, start_x, start_y, end_x, end_y))
        {
            board[start_x][start_y] = EMPTY;
            board[end_x][end_y] = player;
            print_board(board);

            if (player == BLACK)
                player = WHITE;
            else
                player = BLACK;
        }
        else
        {
            printf("Invalid move!\n");
        }
    }

    return 0;
}