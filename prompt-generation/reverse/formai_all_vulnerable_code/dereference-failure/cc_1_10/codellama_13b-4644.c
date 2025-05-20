//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
// Procedurally generated maze example program in a retro style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL_SYMBOL '#'
#define PATH_SYMBOL ' '

// Struct to represent a maze
typedef struct {
    int width;
    int height;
    char** maze;
} Maze;

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to create a new maze
Maze* create_maze(int width, int height) {
    Maze* maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->maze = malloc(sizeof(char*) * maze->width);
    for (int i = 0; i < maze->width; i++) {
        maze->maze[i] = malloc(sizeof(char) * maze->height);
        for (int j = 0; j < maze->height; j++) {
            maze->maze[i][j] = WALL_SYMBOL;
        }
    }
    return maze;
}

// Function to print a maze
void print_maze(Maze* maze) {
    for (int i = 0; i < maze->width; i++) {
        for (int j = 0; j < maze->height; j++) {
            printf("%c", maze->maze[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random path in a maze
void generate_path(Maze* maze, int start_x, int start_y) {
    int x = start_x;
    int y = start_y;
    int dx = 0;
    int dy = 0;
    while (x >= 0 && x < maze->width && y >= 0 && y < maze->height) {
        if (rand_range(0, 1) == 0) {
            dx = rand_range(-1, 1);
            dy = 0;
        } else {
            dx = 0;
            dy = rand_range(-1, 1);
        }
        x += dx;
        y += dy;
        if (x >= 0 && x < maze->width && y >= 0 && y < maze->height) {
            maze->maze[x][y] = PATH_SYMBOL;
        }
    }
}

int main() {
    srand(time(NULL));
    Maze* maze = create_maze(MAZE_SIZE, MAZE_SIZE);
    generate_path(maze, 0, 0);
    print_maze(maze);
    return 0;
}