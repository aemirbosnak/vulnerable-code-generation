//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int maze[20][20]; //initialize maze
int startX, startY; //initialize start point
int endX, endY; //initialize end point

void createMaze(int x, int y) {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int count = 0;
    int nx, ny;

    srand(time(0));
    startX = x;
    startY = y;
    endX = x + 19;
    endY = y + 19;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            maze[i][j] = 1;
        }
    }

    maze[startX][startY] = 0;
    maze[endX][endY] = 0;

    while (count < 50) {
        int r = rand() % 4;
        nx = x + dir[r][0];
        ny = y + dir[r][1];

        if (nx >= 0 && nx < 20 && ny >= 0 && ny < 20 && maze[nx][ny] == 1) {
            maze[nx][ny] = 0;
            x = nx;
            y = ny;
            count++;
        }
    }
}

void printMaze() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (maze[i][j] == 1) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int x, y;

    printf("Enter the starting point (x y): ");
    scanf("%d %d", &x, &y);

    createMaze(x, y);
    printMaze();

    return 0;
}