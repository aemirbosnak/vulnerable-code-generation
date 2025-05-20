//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    int y = 0;
    char map[10][10] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    system("clear");
    printf("You are in a 10x10 grid. Use the arrow keys to move. (Press 'q' to quit)\n");

    while (x < 10 && y < 10 && map[x][y] != 'X')
    {
        int move = getchar();

        switch (move)
        {
            case 65:
                y--;
                break;
            case 66:
                y++;
                break;
            case 67:
                x++;
                break;
            case 68:
                x--;
                break;
            case 113:
                exit(0);
                break;
        }

        system("clear");
        printf("You are in a 10x10 grid. Use the arrow keys to move. (Press 'q' to quit)\n");
        map[x][y] = 'O';
        printf("Your position: (%d, %d)\n", x, y);
        printf("Map:\n");
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }
    }

    system("clear");
    printf("You have reached the center of the grid! Game Over!\n");

    return 0;
}