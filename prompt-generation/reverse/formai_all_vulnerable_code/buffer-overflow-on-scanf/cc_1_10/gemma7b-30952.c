//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

int main()
{
    int board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int player_x = 0;
    int player_y = 0;

    char direction = ' ';

    while (direction != 'q')
    {
        printf("Enter direction (w, a, s, d, q): ");
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
            case 'q':
                printf("Thank you for playing!");
                break;
            default:
                printf("Invalid input.");
                break;
        }

        if (board[player_x][player_y] == 1)
        {
            printf("Game over!");
            break;
        }

        board[player_x][player_y] = 1;
    }

    return 0;
}