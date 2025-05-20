//FormAI DATASET v1.0 Category: Checkers Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

char board[8][8] = {
    {'-', 'b', '-', 'b', '-', 'b', '-', 'b'},
    {'b', '-', 'b', '-', 'b', '-', 'b', '-'},
    {'-', 'b', '-', 'b', '-', 'b', '-', 'b'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'w', '-', 'w', '-', 'w', '-', 'w', '-'},
    {'-', 'w', '-', 'w', '-', 'w', '-', 'w'},
    {'w', '-', 'w', '-', 'w', '-', 'w', '-'}
};

void display_board()
{
    int i, j;

    printf("\n    0   1   2   3   4   5   6   7\n");
    printf("  +---+---+---+---+---+---+---+---+\n");

    for (i = 0; i < 8; i++) {
        printf("%d |", i);
        for (j = 0; j < 8; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
}

int move_is_valid(int x1, int y1, int x2, int y2, char player)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int adx = abs(dx);
    int ady = abs(dy);
    int i;

    if (board[x2][y2] != '-') { // destination cell is not empty
        return 0;
    }

    if (player == 'b' && dx > 0) { // black can only move upwards
        return 0;
    }

    if (player == 'w' && dx < 0) { // white can only move downwards
        return 0;
    }

    if (adx != ady) { // check if it's a diagonal move
        return 0;
    }

    if (adx == 1) { // just a simple move
        return 1;
    }

    if (adx == 2) { // check if it's a jump move
        int ix = (x1 + x2) / 2;
        int iy = (y1 + y2) / 2;
        if (board[ix][iy] == '-' || board[ix][iy] == player) { // check if there's an opponent's piece to jump over
            return 0;
        }
        return 1;
    }

    return 0;
}

int turn_is_over(int x1, int y1, int x2, int y2, char player)
{
    int dx = x2 - x1;
    int adx = abs(dx);

    if (adx == 2) { // it was a jump move, check if there's another jump available
        int nx, ny;

        for (nx = -2; nx <= 2; nx += 4) {
            for (ny = -2; ny <= 2; ny += 4) {
                int x = x2 + nx;
                int y = y2 + ny;

                if (x >= 0 && x < 8 && y >= 0 && y < 8) { // check if the cell is on the board
                    if (board[x][y] == '-') { // check if the cell is empty
                        if (move_is_valid(x1, y1, x, y, player)) {
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 1;
}

int make_move(int x1, int y1, int x2, int y2, char player)
{
    if (!move_is_valid(x1, y1, x2, y2, player)) {
        return 0;
    }

    board[x2][y2] = player;
    board[x1][y1] = '-';

    if (turn_is_over(x1, y1, x2, y2, player)) {
        if (player == 'b') {
            player = 'w';
        } else {
            player = 'b';
        }
    }

    return 1;
}

int main()
{
    int x1, y1, x2, y2;
    char player = 'b';

    display_board();

    while (1) {
        printf("%c's turn\n", player);
        printf("Enter the coordinates of the piece you want to move: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the cell you want to move to: ");
        scanf("%d %d", &x2, &y2);

        if (make_move(x1, y1, x2, y2, player)) {
            display_board();
            if (player == 'b') {
                printf("Black wins!\n");
                break;
            } else {
                printf("White wins!\n");
                break;
            }
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}