//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

char maze[HEIGHT][WIDTH];
int visited[HEIGHT][WIDTH];

void generate_maze() {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        maze[0][x] = '#';
        maze[HEIGHT - 1][x] = '#';
    }
    for (y = 0; y < HEIGHT; y++) {
        maze[y][0] = '#';
        maze[y][WIDTH - 1] = '#';
    }
    for (y = 1; y < HEIGHT - 1; y++) {
        for (x = 1; x < WIDTH - 1; x++) {
            maze[y][x] = rand() % 2? '.' : '#';
        }
    }
    maze[START_Y][START_X] = 'S';
    maze[END_Y][END_X] = 'E';
}

void print_maze() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", maze[y][x]);
        }
        printf("\n");
    }
}

void pathfinding() {
    int x, y, dx, dy;
    int path[HEIGHT][WIDTH];

    x = START_X;
    y = START_Y;

    while (x!= END_X || y!= END_Y) {
        path[y][x] = 1;
        dx = rand() % 2? -1 : 1;
        dy = rand() % 2? -1 : 1;
        while (dx == 0 || dy == 0) {
            dx = rand() % 2? -1 : 1;
            dy = rand() % 2? -1 : 1;
        }
        x += dx;
        y += dy;
    }
}

int main() {
    srand(time(NULL));
    generate_maze();
    print_maze();

    pathfinding();

    return 0;
}