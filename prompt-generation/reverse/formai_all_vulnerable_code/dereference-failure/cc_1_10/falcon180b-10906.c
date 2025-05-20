//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

typedef struct {
    int x, y;
} point;

void generateMaze(int maze[HEIGHT][WIDTH]);
void printMaze(int maze[HEIGHT][WIDTH]);

int main() {
    srand(time(0));

    int maze[HEIGHT][WIDTH];
    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(int maze[HEIGHT][WIDTH]) {
    int i, j;
    point start, end;

    // Initialize maze with walls
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }

    // Set start and end points
    start.x = rand() % HEIGHT;
    start.y = rand() % WIDTH;
    end.x = rand() % HEIGHT;
    end.y = rand() % WIDTH;

    // Carve path from start to end
    maze[start.x][start.y] = 0;
    maze[end.x][end.y] = 0;

    int dx = (end.x - start.x) / 2;
    int dy = (end.y - start.y) / 2;

    while (dx!= 0 || dy!= 0) {
        if (dx > 0) {
            maze[start.x][start.y + dy] = 0;
            start.y += 1;
        } else if (dx < 0) {
            maze[start.x + dy][start.y] = 0;
            start.y -= 1;
        }

        if (dy > 0) {
            maze[start.x + dx][start.y] = 0;
            start.x += 1;
        } else if (dy < 0) {
            maze[start.x][start.y + dx] = 0;
            start.x -= 1;
        }

        dx += (dx > 0)? -1 : 1;
        dy += (dy > 0)? -1 : 1;
    }
}

void printMaze(int maze[HEIGHT][WIDTH]) {
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