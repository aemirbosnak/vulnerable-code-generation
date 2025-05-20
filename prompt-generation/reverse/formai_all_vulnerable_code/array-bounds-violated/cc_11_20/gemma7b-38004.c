//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char shape = 'a';
    int x, y, direction = 1, speed = 1;
    char map[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    system("clear");

    while (shape != 'q')
    {
        switch (direction)
        {
            case 1:
                x++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y++;
                break;
            case 4:
                y--;
                break;
        }

        if (map[x][y] == 1)
        {
            shape = 'q';
        }
        else
        {
            map[x][y] = 1;
            switch (shape)
            {
                case 'a':
                    printf("   /\n  ;   :\n   \__)\n");
                    break;
                case 'b':
                    printf("           /\n          ;   :\n           \__)\n");
                    break;
                case 'c':
                    printf("             /\n            ;   :\n             \__)\n");
                    break;
                case 'd':
                    printf("               /\n              ;   :\n               \__)\n");
                    break;
                case 'e':
                    printf("                 /\n                ;   :\n                 \__)\n");
                    break;
            }
            system("sleep 0.1");
        }
    }

    return 0;
}