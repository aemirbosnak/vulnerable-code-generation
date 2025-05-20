//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int map[HEIGHT][WIDTH] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
                            {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
                            {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
                            {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int main()
{
    system("clear");
    int x = 0, y = 0, direction = RIGHT;
    char c;

    while (map[y][x] != 1)
    {
        switch (direction)
        {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
        }

        map[y][x] = 2;

        if (x == 0)
            direction = UP;
        else if (x == WIDTH - 1)
            direction = DOWN;
        else if (y == 0)
            direction = RIGHT;
        else if (y == HEIGHT - 1)
            direction = LEFT;

        printf("Press any key to continue...");
        c = getchar();
    }

    printf("You win!");
    return 0;
}