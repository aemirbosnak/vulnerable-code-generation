//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    int player_x = 0, player_y = 0, computer_x = rand() % 6, computer_y = rand() % 6;

    char move;

    printf("Welcome to Shannon's Game of Life!\n");

    while (1)
    {
        printf("Enter your move (h/v/d/u): ");
        scanf(" %c", &move);

        switch (move)
        {
            case 'h':
                player_x--;
                break;
            case 'v':
                player_y--;
                break;
            case 'd':
                player_x++;
                break;
            case 'u':
                player_y++;
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        if (board[player_x][player_y] == 1)
        {
            printf("You already occupied that position.\n");
            continue;
        }

        board[player_x][player_y] = 1;

        if (board[computer_x][computer_y] == 1)
        {
            printf("The computer has won!\n");
            break;
        }

        computer_x = rand() % 6;
        computer_y = rand() % 6;

        board[computer_x][computer_y] = 1;

        printf("The computer has made its move.\n");

        if (board[player_x][player_y] == 1)
        {
            printf("You have won!\n");
            break;
        }
    }

    return 0;
}