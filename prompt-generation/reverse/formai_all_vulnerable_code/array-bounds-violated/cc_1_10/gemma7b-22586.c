//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char map[10][10] = {{'.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ','#',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','#',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ','#',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ','#',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ','#',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ','#',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

    int x = 0, y = 0, direction = 0;

    printf("Welcome to the Wasteland, traveler. You have a map and a trusty blade. You have no ammo.\n");

    while (1)
    {
        system("clear");
        printf("Current position: (%d, %d)\n", x, y);
        printf("Map:\n");

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        printf("Enter direction (N, S, E, W): ");
        scanf("%d", &direction);

        switch (direction)
        {
            case 1:
                y--;
                break;
            case 2:
                y++;
                break;
            case 3:
                x++;
                break;
            case 4:
                x--;
                break;
        }

        if (map[x][y] == '#')
        {
            printf("You hit a wall. Try again.\n");
        }
    }

    return 0;
}