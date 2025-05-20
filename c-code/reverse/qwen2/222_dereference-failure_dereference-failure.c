#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void generateMaze(int **maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

void printMaze(int **maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **maze = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    generateMaze(maze, WIDTH, HEIGHT);
    printMaze(maze, WIDTH, HEIGHT);

    // Free the allocated memory
    for (int i = 0; i < HEIGHT; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}
