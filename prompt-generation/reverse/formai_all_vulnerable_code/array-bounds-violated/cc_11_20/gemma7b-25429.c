//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    int player1 = 1;
    int player2 = 2;
    int turn = 1;

    char move;

    while (!board[2][2] && turn)
    {
        printf("Enter your move (e.g. e3): ");
        scanf(" %c", &move);

        switch (move)
        {
            case 'e':
                board[1][2] = player1;
                break;
            case 'f':
                board[2][2] = player1;
                break;
            case 'g':
                board[3][2] = player1;
                break;
            case 'h':
                board[4][2] = player1;
                break;
            case 'i':
                board[5][2] = player1;
                break;
            case 'j':
                board[2][3] = player1;
                break;
            case 'k':
                board[2][4] = player1;
                break;
            case 'l':
                board[2][5] = player1;
                break;
            case 'm':
                board[2][6] = player1;
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        turn = 2 - turn;
    }

    if (board[2][2] == player1)
    {
        printf("You won!");
    }
    else
    {
        printf("You lost!");
    }

    return 0;
}