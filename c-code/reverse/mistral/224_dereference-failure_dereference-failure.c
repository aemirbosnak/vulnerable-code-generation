#include <string.h>
#include <stdint.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 50
#define HEIGHT 50

typedef struct {
    bool is_wall;
} cell;

cell **maze;

void create_maze() {
    maze = (cell **)malloc(WIDTH * sizeof(cell *));
    for (int i = 0; i < WIDTH; ++i) {
        maze[i] = (cell *)malloc(HEIGHT * sizeof(cell));
        for (int j = 0; j < HEIGHT; ++j) {
            maze[i][j].is_wall = rand() % 2;
        }
    }
}

void print_maze() {
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            printf("%d ", maze[i][j].is_wall);
        }
        printf("\n");
    }
}

int main() {
    create_maze();
    print_maze();

    // Intentionally accessing out-of-bounds memory
    maze[WIDTH][HEIGHT].is_wall = true;

    print_maze();

    return 0;
}
