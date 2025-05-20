//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[64] = {0};
    int player = 1;
    int move = 0;

    board[6] = 1;
    board[10] = 1;
    board[14] = 1;
    board[18] = 1;
    board[22] = 1;
    board[26] = 1;
    board[30] = 1;
    board[34] = 1;
    board[38] = 1;

    while (!board[63])
    {
        printf("Enter move (e.g. e2, d3): ");
        scanf("%d", &move);

        if (move < 1 || move > 64)
        {
            printf("Invalid move.\n");
            continue;
        }

        if (board[move] != 0)
        {
            printf("Move already made.\n");
            continue;
        }

        switch (player)
        {
            case 1:
                board[move] = 1;
                break;
            case 2:
                board[move] = 2;
                break;
        }

        player *= -1;
    }

    printf("Game over! Winner: %d\n", board[63]);

    return 0;
}