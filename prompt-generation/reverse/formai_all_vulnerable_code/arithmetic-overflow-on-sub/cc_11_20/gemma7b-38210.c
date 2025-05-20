//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player1 = 1, player2 = 2, turn = 1, game_over = 0;

    system("clear");

    while (!game_over)
    {
        printf("Player %d's turn:", player1);
        printf("\nEnter move (1-9): ");
        int move = getchar() - '0';

        if (move < 1 || move > 9)
        {
            printf("Invalid move.\n");
            continue;
        }

        if (board[move] != '1' && board[move] != '2')
        {
            printf("Move already made.\n");
            continue;
        }

        board[move] = player1;

        turn++;

        system("clear");

        printf("Board:");
        for (int i = 0; i < 9; i++)
        {
            printf(" %c ", board[i]);
        }

        printf("\n");

        if (board[1] == board[2] && board[1] == board[3] ||
            board[4] == board[5] && board[4] == board[6] ||
            board[7] == board[8] && board[7] == board[9] ||
            board[1] == board[4] && board[1] == board[7] ||
            board[2] == board[5] && board[2] == board[8] ||
            board[3] == board[6] && board[3] == board[9])
        {
            game_over = 1;
            printf("Game Over! Player %d won!", player1);
        }

        else if (turn == 9)
        {
            game_over = 1;
            printf("It's a draw!");
        }
    }

    return 0;
}