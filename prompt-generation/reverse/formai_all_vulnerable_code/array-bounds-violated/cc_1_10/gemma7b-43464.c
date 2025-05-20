//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[64] = {0};
    board[1] = 1;
    board[2] = 1;
    board[3] = 1;
    board[4] = 1;
    board[5] = 1;
    board[6] = 2;
    board[7] = 2;
    board[8] = 2;
    board[9] = 2;
    board[10] = 2;
    board[11] = 2;
    board[12] = 3;
    board[13] = 3;
    board[14] = 3;
    board[15] = 3;
    board[16] = 3;
    board[17] = 3;
    board[18] = 4;
    board[19] = 4;
    board[20] = 4;
    board[21] = 4;
    board[22] = 4;
    board[23] = 4;
    board[24] = 4;

    int turn = 0;
    char color = 'w';

    while (!board[64])
    {
        int move = 0;

        switch (color)
        {
            case 'w':
                move = rand() % 4;
                break;
            case 'b':
                move = rand() % 4;
                break;
        }

        switch (move)
        {
            case 0:
                board[board[1] + 1] = color;
                board[1] = 0;
                break;
            case 1:
                board[board[1] - 1] = color;
                board[1] = 0;
                break;
            case 2:
                board[board[1] + 2] = color;
                board[1] = 0;
                break;
            case 3:
                board[board[1] - 2] = color;
                board[1] = 0;
                break;
        }

        turn++;

        if (turn % 2 == 0)
        {
            color = 'b';
        }
        else
        {
            color = 'w';
        }
    }

    return 0;
}