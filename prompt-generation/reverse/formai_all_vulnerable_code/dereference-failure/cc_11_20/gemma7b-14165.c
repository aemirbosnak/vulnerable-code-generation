//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 51
#define HEIGHT 51

#define EMPTY 0
#define WALL 1
#define PATH 2

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the maze
    int **maze = (int**)malloc(HEIGHT * sizeof(int*));
    for (int y = 0; y < HEIGHT; y++) {
        maze[y] = (int*)malloc(WIDTH * sizeof(int));
        for (int x = 0; x < WIDTH; x++) {
            maze[y][x] = EMPTY;
        }
    }

    // Generate the walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 || y == 0 || x == WIDTH - 1 || y == HEIGHT - 1) {
                maze[y][x] = WALL;
            }
        }
    }

    // Generate the path
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    maze[y][x] = PATH;

    // Print the maze
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", maze[y][x]);
        }
        printf("\n");
    }

    // Free the memory
    for (int y = 0; y < HEIGHT; y++) {
        free(maze[y]);
    }
    free(maze);

    return 0;
}