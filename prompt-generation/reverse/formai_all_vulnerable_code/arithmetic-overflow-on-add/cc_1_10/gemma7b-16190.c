//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 5
#define PLAYER_START 0

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    board[PLAYER_START][PLAYER_START] = 1;

    int move_x, move_y;
    char move_direction;

    printf("Welcome to the Cryptic Breakout Game!\n");
    printf("Enter your move (x, y, direction): ");

    scanf("%d %d %c", &move_x, &move_y, &move_direction);

    switch (move_direction)
    {
        case 'w':
            board[move_x][move_y - 1] = 1;
            break;
        case 'a':
            board[move_x - 1][move_y] = 1;
            break;
        case 's':
            board[move_x][move_y + 1] = 1;
            break;
        case 'd':
            board[move_x + 1][move_y] = 1;
            break;
        default:
            printf("Invalid move.\n");
            break;
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}