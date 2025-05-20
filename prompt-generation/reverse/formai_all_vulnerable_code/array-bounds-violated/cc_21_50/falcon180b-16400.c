//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

// Define the maze
char maze[HEIGHT][WIDTH] = {
    "XXXXXOOOOOOOX",
    "XOOOOOOOXOOX",
    "XOOOOOOXOOOO",
    "XOOOOXOOOXOO",
    "XOOOOXOOOOOO",
    "XOOXOOOOOOOX",
    "XOOXOOOOOOOX",
    "XXOXOOOOOOOX",
    "XOOXOOOOOOOX",
    "XOOXOOOOOOOX"
};

int main() {
    srand(time(NULL));

    int startX = rand() % HEIGHT;
    int startY = rand() % WIDTH;
    int endX = rand() % HEIGHT;
    int endY = rand() % WIDTH;

    while (1) {
        system("clear");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == startX && j == startY) {
                    printf("\033[1;32mS\033[0m");
                } else if (i == endX && j == endY) {
                    printf("\033[1;31mE\033[0m");
                } else if (maze[i][j] == 'X') {
                    printf("\033[1;31mX\033[0m");
                } else if (maze[i][j] == 'O') {
                    printf("\033[1;34mO\033[0m");
                } else {
                    printf("%c", maze[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");

        int x = startX;
        int y = startY;

        while (x!= endX || y!= endY) {
            if (maze[x][y] == 'X') {
                x++;
                continue;
            } else if (maze[x][y] == 'O') {
                y++;
                continue;
            }

            int directions[4] = {0, 1, 0, -1};
            int randomDir = rand() % 4;

            switch (randomDir) {
                case 0:
                    x--;
                    break;
                case 1:
                    y++;
                    break;
                case 2:
                    x++;
                    break;
                case 3:
                    y--;
                    break;
            }
        }

        printf("\n");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == x && j == y) {
                    printf("\033[1;32mS\033[0m");
                } else if (i == endX && j == endY) {
                    printf("\033[1;31mE\033[0m");
                } else if (maze[i][j] == 'X') {
                    printf("\033[1;31mX\033[0m");
                } else if (maze[i][j] == 'O') {
                    printf("\033[1;34mO\033[0m");
                } else {
                    printf("%c", maze[i][j]);
                }
            }
            printf("\n");
        }

        printf("\nSolution found!\n");
        break;
    }

    return 0;
}