//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMaze(int maze[20][20], int startX, int startY) {
    int x, y, dir = 0, count = 0;
    srand(time(0));
    for (y = 0; y < 20; y++) {
        for (x = 0; x < 20; x++) {
            if (x == startX && y == startY) {
                maze[y][x] = 1;
            } else {
                maze[y][x] = 0;
            }
        }
    }
    while (count < 20) {
        dir = rand() % 4;
        switch (dir) {
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
        if (maze[y][x] == 0) {
            maze[y][x] = 1;
            count++;
        }
    }
}

void printMaze(int maze[20][20]) {
    int x, y;
    for (y = 0; y < 20; y++) {
        for (x = 0; x < 20; x++) {
            if (maze[y][x] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[20][20], startX, startY;
    printf("Enter the starting position (x y): ");
    scanf("%d %d", &startX, &startY);
    generateMaze(maze, startX, startY);
    printMaze(maze);
    return 0;
}