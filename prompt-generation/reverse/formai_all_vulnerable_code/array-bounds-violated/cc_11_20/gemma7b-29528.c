//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[20][20] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    board[10][10] = 1;
    board[10][11] = 1;
    board[10][12] = 1;
    board[11][10] = 1;
    board[11][11] = 1;
    board[11][12] = 1;
    board[12][10] = 1;
    board[12][11] = 1;
    board[12][12] = 1;

    for (int r = 0; r < 20; r++)
    {
        for (int c = 0; c < 20; c++)
        {
            int neighbors = 0;
            if (board[r - 1][c] == 1) neighbors++;
            if (board[r + 1][c] == 1) neighbors++;
            if (board[r][c - 1] == 1) neighbors++;
            if (board[r][c + 1] == 1) neighbors++;

            if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
        }
    }

    for (int r = 0; r < 20; r++)
    {
        for (int c = 0; c < 20; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}