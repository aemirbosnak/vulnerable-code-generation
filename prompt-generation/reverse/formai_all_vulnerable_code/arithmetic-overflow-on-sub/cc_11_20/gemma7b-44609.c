//Gemma-7B DATASET v1.0 Category: Table Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MOVE_LEFT 0
#define MOVE_RIGHT 1
#define MOVE_UP 2
#define MOVE_DOWN 3

#define BOARD_SIZE 5

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0}};

    int player_x = 2;
    int player_y = 2;

    int direction = MOVE_RIGHT;

    time_t start_time = time(NULL);

    while (time(NULL) - start_time < 60)
    {
        switch (direction)
        {
            case MOVE_LEFT:
                if (board[player_x - 1][player_y] == 0)
                {
                    board[player_x - 1][player_y] = 1;
                    player_x--;
                }
                break;
            case MOVE_RIGHT:
                if (board[player_x + 1][player_y] == 0)
                {
                    board[player_x + 1][player_y] = 1;
                    player_x++;
                }
                break;
            case MOVE_UP:
                if (board[player_x][player_y - 1] == 0)
                {
                    board[player_x][player_y - 1] = 1;
                    player_y--;
                }
                break;
            case MOVE_DOWN:
                if (board[player_x][player_y + 1] == 0)
                {
                    board[player_x][player_y + 1] = 1;
                    player_y++;
                }
                break;
        }

        direction = rand() % 4;

        system("clear");

        for (int y = 0; y < BOARD_SIZE; y++)
        {
            for (int x = 0; x < BOARD_SIZE; x++)
            {
                printf("%d ", board[x][y]);
            }

            printf("\n");
        }

        printf("Player position: (%d, %d)\n", player_x, player_y);

        sleep(1);
    }

    return 0;
}