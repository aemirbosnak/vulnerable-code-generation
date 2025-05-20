//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

int maze[HEIGHT][WIDTH];
int solution[HEIGHT][WIDTH];

void initMaze() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    maze[START_Y][START_X] = 0;
    maze[END_Y][END_X] = 0;
}

void printMaze() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void solveMaze() {
    int x = START_X, y = START_Y;
    int dx = 0, dy = -1;
    while (x!= END_X || y!= END_Y) {
        if (maze[y][x] == 0) {
            solution[y][x] = 1;
            if (maze[y][x + 1] == 0) {
                dx = 1;
            } else if (maze[y - 1][x] == 0) {
                dy = 1;
            } else if (maze[y][x - 1] == 0) {
                dx = -1;
            }
        }
        x += dx;
        y += dy;
    }
}

void printSolution() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (solution[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    initMaze();
    printMaze();
    solveMaze();
    printSolution();
    return 0;
}