//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5
#define MAX_NUM 10

int main()
{
    int board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

    int player_1_pieces = 5;
    int player_2_pieces = 5;

    char current_player = 'A';

    int game_status = 0;

    while (game_status == 0)
    {
        int move_x, move_y;

        printf("Enter move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        if (move_x < 0 || move_x >= MAX_SIZE || move_y < 0 || move_y >= MAX_SIZE)
        {
            printf("Invalid move.\n");
            continue;
        }

        if (board[move_x][move_y] != 0)
        {
            printf("Square already occupied.\n");
            continue;
        }

        board[move_x][move_y] = current_player;

        if (current_player == 'A')
        {
            player_1_pieces--;
            current_player = 'B';
        }
        else
        {
            player_2_pieces--;
            current_player = 'A';
        }

        if (player_1_pieces == 0 || player_2_pieces == 0)
        {
            game_status = 1;
        }
    }

    if (game_status == 1)
    {
        printf("Game over! Winner: %c\n", current_player);
    }
    else
    {
        printf("Draw.\n");
    }

    return 0;
}