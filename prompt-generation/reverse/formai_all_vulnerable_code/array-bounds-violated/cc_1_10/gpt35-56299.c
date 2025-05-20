//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define SHIPS 3

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int ships_placed = 0;

    srand(time(NULL));

    for (int i = 0; i < SHIPS; i++)
    {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;

        if (board[x][y] == 0)
        {
            board[x][y] = 1;
            ships_placed++;
        }
        else
        {
            i--;
        }
    }

    printf("Welcome to Battleship!\n");

    while (ships_placed > 0)
    {
        int guess_x, guess_y;

        printf("Enter coordinates (x,y): ");
        scanf("%d,%d", &guess_x, &guess_y);

        if (guess_x >= BOARD_SIZE || guess_y >= BOARD_SIZE)
        {
            printf("Invalid input. Coordinates must be in range (0,0) to (%d,%d)\n", BOARD_SIZE-1, BOARD_SIZE-1);
            continue;
        }

        if (board[guess_x][guess_y] == 1)
        {
            printf("Hit!\n");
            board[guess_x][guess_y] = 2;
            ships_placed--;
        }
        else if (board[guess_x][guess_y] == 0)
        {
            printf("Miss!\n");
            board[guess_x][guess_y] = -1;
        }
        else
        {
            printf("You already guessed this square. Try again.\n");
        }
    }

    printf("You sunk all the enemy ships! Congratulations!\n");
    return 0;
}