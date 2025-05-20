//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMaze(int maze[10][10], int x, int y) {
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int randomDirection;

    srand(time(0));
    randomDirection = rand() % 4;

    while (maze[x][y] == 0) {
        if (randomDirection == 0) {
            y++;
        } else if (randomDirection == 1) {
            y--;
        } else if (randomDirection == 2) {
            x++;
        } else {
            x--;
        }

        if (x >= 0 && x < 10 && y >= 0 && y < 10 && maze[x][y] == 0) {
            maze[x][y] = 1;
        } else {
            randomDirection = rand() % 4;
        }
    }
}

void printMaze(int maze[10][10]) {
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (maze[i][j] == 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[10][10];
    int x, y;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j] = 0;
        }
    }

    x = rand() % 10;
    y = rand() % 10;

    generateMaze(maze, x, y);

    printMaze(maze);

    return 0;
}