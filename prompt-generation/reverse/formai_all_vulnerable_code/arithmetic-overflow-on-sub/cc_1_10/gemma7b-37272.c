//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPACE ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

#define MOVE_LEFT 'L'
#define MOVE_RIGHT 'R'
#define MOVE_UP 'U'
#define MOVE_DOWN 'D'

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                 {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                 {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}};

    char current_player = PLAYER_X;

    int move_made = 0;

    while (!move_made)
    {
        int row, column;

        printf("Enter row (1-3): ");
        scanf("%d", &row);

        printf("Enter column (1-3): ");
        scanf("%d", &column);

        if (board[row - 1][column - 1] != EMPTY_SPACE)
        {
            printf("Invalid move.\n");
            continue;
        }

        board[row - 1][column - 1] = current_player;

        move_made = 1;

        switch (current_player)
        {
            case PLAYER_X:
                current_player = PLAYER_O;
                break;
            case PLAYER_O:
                current_player = PLAYER_X;
                break;
        }
    }

    printf("Game over! The winner is: %c", board[0][0] == current_player ? current_player : 'N');

    return 0;
}