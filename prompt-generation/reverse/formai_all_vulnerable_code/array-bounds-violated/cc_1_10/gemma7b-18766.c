//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main() {

    int maze[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 1, 0, 0, 1},
                              {0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
                              {0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                              {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                              {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
                              {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                              {1, 0, 0, 0, 0, 0, 0, 0, 1, 0}};

    int x = 0, y = 0, direction = 0, goalx = 5, goaly = 5;

    while (x != goalx || y != goaly) {
        switch (direction) {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
        }

        if (maze[x][y] == 0) {
            maze[x][y] = 2;
            printf("(");
            printf("%d, %d)", x, y);
            printf(") --> ");
        } else {
            direction = (direction + 1) % 4;
        }
    }

    printf("(");
    printf("%d, %d)", goalx, goaly);
    printf(") Goal!");

    return 0;
}