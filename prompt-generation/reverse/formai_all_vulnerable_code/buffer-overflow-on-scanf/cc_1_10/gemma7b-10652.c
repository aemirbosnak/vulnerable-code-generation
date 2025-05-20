//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: funny
#include <stdio.h>

int main()
{
    int board[64] = {0};
    board[2] = 1;
    board[5] = 1;
    board[12] = 1;
    board[15] = 1;
    board[24] = 1;
    board[27] = 1;
    board[30] = 1;
    board[39] = 1;
    board[42] = 1;
    board[45] = 1;
    board[54] = 1;

    int move = 0;
    char turn = 'a';

    while (board[53] == 0)
    {
        printf("Turn: %c\n", turn);

        int x = 0;
        int y = 0;

        printf("Enter move (x, y): ");
        scanf("%d, %d", &x, &y);

        if (x < 0 || x > 5 || y < 0 || y > 8)
        {
            printf("Invalid move.\n");
            continue;
        }

        if (board[x] == 0)
        {
            printf("There is no piece there.\n");
            continue;
        }

        if (board[x] * turn - board[y] * turn != 1)
        {
            printf("Invalid move.\n");
            continue;
        }

        board[x] = 0;
        board[y] = 1 * turn;

        move++;
        if (move % 2 == 0)
            turn = 'b';
        else
            turn = 'a';
    }

    printf("Game over! The winner is: %c\n", turn);

    return 0;
}