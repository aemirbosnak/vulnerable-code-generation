//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
    printf("\033[ %d; %d ]", x, y);
}

int main()
{

    system("cls");

    int x = 0, y = 0;
    char map[20][20] = {{0}};

    map[x][y] = 'o';

    while (1)
    {
        system("cls");

        gotoxy(x, y);
        printf("%c", map[x][y]);

        int direction = rand() % 4;

        switch (direction)
        {
            case 0:
                y--;
                break;
            case 1:
                x++;
                break;
            case 2:
                y++;
                break;
            case 3:
                x--;
                break;
        }

        if (map[x][y] == 'b')
        {
            printf("Game Over!");
            break;
        }

        map[x][y] = 'o';
    }

    return 0;
}