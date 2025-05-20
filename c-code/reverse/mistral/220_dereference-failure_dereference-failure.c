#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

void generateMaze(int maze[HEIGHT][WIDTH]);
void recursiveBacktrack(int x, int y, int maze[HEIGHT][WIDTH]);

int main() {
    srand(time(NULL));
    int maze[HEIGHT][WIDTH];

    generateMaze(maze);

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void generateMaze(int maze[HEIGHT][WIDTH]) {
    maze[0][0] = 1;
    recursiveBacktrack(1, 1, maze);
}

void recursiveBacktrack(int x, int y, int maze[HEIGHT][WIDTH]) {
    int directions[4][2] = {{x - 2, y}, {x + 2, y}, {x, y - 2}, {x, y + 2}};

    for (int i = 0; i < 4; ++i) {
        int newX = directions[i][0];
        int newY = directions[i][1];

        if (newX >= 0 && newX < HEIGHT && newY >= 0 && newY < WIDTH && maze[newX][newY] == 0) {
            maze[newX][newY] = 1;
            recursiveBacktrack(newX, newY, maze);
            maze[newX][newY] = 0;
        }
    }
}
