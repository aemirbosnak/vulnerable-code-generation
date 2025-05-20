//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: artistic
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 5

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                                 {0, 1, 1, 0, 0},
                                 {0, 1, 1, 1, 0},
                                 {0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 0}};

    int player_x = 0;
    int player_y = 0;

    char direction = ' ';

    while (board[player_y][player_x] != 3)
    {
        printf("Enter direction (w, a, s, d): ");
        scanf("%c", &direction);

        switch (direction)
        {
            case 'w':
                player_y--;
                break;
            case 'a':
                player_x--;
                break;
            case 's':
                player_y++;
                break;
            case 'd':
                player_x++;
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        if (board[player_y][player_x] == 2)
        {
            printf("Game over!\n");
            break;
        }

        board[player_y][player_x] = 3;
    }

    return 0;
}