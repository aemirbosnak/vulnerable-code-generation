//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_L 20
#define MAX_H 20

void initializeMaze(int **maze, int l, int h) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < h; j++) {
            maze[i][j] = 0;
        }
    }
}

void drawMaze(int **maze, int l, int h) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < h; j++) {
            if (maze[i][j] == 1) {
                printf("%c ", '#');
            } else {
                printf("%c ", '.');
            }
        }
        printf("\n");
    }
}

int main() {
    int l, h;
    printf("Enter the dimensions of the maze (l x h): ");
    scanf("%d %d", &l, &h);

    int **maze = (int **)malloc(l * sizeof(int *) + h * sizeof(int));
    initializeMaze(maze, l, h);

    // Generate the maze
    srand(time(NULL));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < h; j++) {
            maze[i][j] = rand() % 2;
        }
    }

    drawMaze(maze, l, h);

    // Find the route
    int x, y, dx, dy;
    x = 0;
    y = 0;
    dx = 1;
    dy = 0;

    while (x < l && y < h && maze[x][y] != 1) {
        maze[x][y] = 2;
        x += dx;
        y += dy;
    }

    drawMaze(maze, l, h);

    printf("The route is complete!\n");

    free(maze);

    return 0;
}