//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int rows;
    int cols;
    int **maze;
} Maze;

void generate_maze(Maze *maze) {
    srand(time(NULL));

    for (int i = 0; i < maze->rows; i++) {
        maze->maze[i] = malloc(maze->cols * sizeof(int));
        for (int j = 0; j < maze->cols; j++) {
            maze->maze[i][j] = 0;
        }
    }

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (rand() % 2) {
                maze->maze[i][j] = 1;
            } else {
                maze->maze[i][j] = 2;
            }
        }
    }

    int start_row = rand() % maze->rows;
    int start_col = rand() % maze->cols;
    maze->maze[start_row][start_col] = 3;

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->maze[i][j] == 1) {
                maze->maze[i][j] = 4;
                generate_maze(maze);
                maze->maze[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->maze[i][j] == 2) {
                maze->maze[i][j] = 5;
                generate_maze(maze);
                maze->maze[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->maze[i][j] == 3) {
                maze->maze[i][j] = 6;
                generate_maze(maze);
                maze->maze[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->maze[i][j] == 4) {
                maze->maze[i][j] = 7;
                generate_maze(maze);
                maze->maze[i][j] = 4;
            }
        }
    }

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->maze[i][j] == 5) {
                maze->maze[i][j] = 8;
                generate_maze(maze);
                maze->maze[i][j] = 5;
            }
        }
    }
}

int main() {
    Maze maze;
    maze.rows = ROWS;
    maze.cols = COLS;
    maze.maze = malloc(maze.rows * sizeof(int *));

    for (int i = 0; i < maze.rows; i++) {
        maze.maze[i] = malloc(maze.cols * sizeof(int));
    }

    generate_maze(&maze);

    for (int i = 0; i < maze.rows; i++) {
        for (int j = 0; j < maze.cols; j++) {
            printf("%d ", maze.maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}