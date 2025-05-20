//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

Point maze[100][100];
int startX, startY, endX, endY;

void generateMaze(int x, int y) {
    int directions[4] = {0, 1, 0, -1};
    int direction = rand() % 4;
    while (maze[x][y].x == 0 && maze[x][y].y == 0) {
        if (direction == 0) {
            x--;
        } else if (direction == 1) {
            y++;
        } else if (direction == 2) {
            x++;
        } else {
            y--;
        }
    }
    maze[x][y].x = x;
    maze[x][y].y = y;
}

void printMaze() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (maze[i][j].x == 0 && maze[i][j].y == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            generateMaze(i, j);
        }
    }
    startX = rand() % 100;
    startY = rand() % 100;
    while (maze[startX][startY].x!= 0 && maze[startX][startY].y!= 0) {
        startX = rand() % 100;
        startY = rand() % 100;
    }
    endX = rand() % 100;
    endY = rand() % 100;
    while (maze[endX][endY].x!= 0 && maze[endX][endY].y!= 0) {
        endX = rand() % 100;
        endY = rand() % 100;
    }
    maze[startX][startY].x = 1;
    maze[endX][endY].y = 2;
    printMaze();
    return 0;
}