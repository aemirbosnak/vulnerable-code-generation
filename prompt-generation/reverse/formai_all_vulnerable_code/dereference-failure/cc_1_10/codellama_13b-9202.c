//Code Llama-13B DATASET v1.0 Category: Maze Route Finder ; Style: modular
/*
 * maze.c
 *
 * A modular C program that finds a route through a maze
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WALL '*'
#define PATH '.'
#define START 'S'
#define END 'E'

// Struct to represent a maze
struct Maze {
    int rows;
    int cols;
    char** grid;
};

// Struct to represent a position in the maze
struct Position {
    int row;
    int col;
};

// Function to create a new maze
struct Maze* createMaze(int rows, int cols) {
    struct Maze* maze = malloc(sizeof(struct Maze));
    maze->rows = rows;
    maze->cols = cols;
    maze->grid = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        maze->grid[i] = malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++) {
            maze->grid[i][j] = PATH;
        }
    }
    return maze;
}

// Function to set a position in the maze to a wall
void setWall(struct Maze* maze, int row, int col) {
    maze->grid[row][col] = WALL;
}

// Function to find the starting position in the maze
struct Position findStart(struct Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->grid[i][j] == START) {
                struct Position start;
                start.row = i;
                start.col = j;
                return start;
            }
        }
    }
    return (struct Position){0, 0};
}

// Function to find the ending position in the maze
struct Position findEnd(struct Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->grid[i][j] == END) {
                struct Position end;
                end.row = i;
                end.col = j;
                return end;
            }
        }
    }
    return (struct Position){0, 0};
}

// Function to check if a position is a wall
int isWall(struct Maze* maze, int row, int col) {
    return maze->grid[row][col] == WALL;
}

// Function to check if a position is the start position
int isStart(struct Maze* maze, int row, int col) {
    return maze->grid[row][col] == START;
}

// Function to check if a position is the end position
int isEnd(struct Maze* maze, int row, int col) {
    return maze->grid[row][col] == END;
}

// Function to check if a position is a valid position
int isValid(struct Maze* maze, int row, int col) {
    return row >= 0 && row < maze->rows && col >= 0 && col < maze->cols;
}

// Function to find a path from the start to the end
void findPath(struct Maze* maze, struct Position start, struct Position end) {
    if (isEnd(maze, start.row, start.col)) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int row = start.row + i;
        int col = start.col + i;
        if (isValid(maze, row, col) && !isWall(maze, row, col) && !isEnd(maze, row, col)) {
            maze->grid[row][col] = PATH;
            findPath(maze, (struct Position){row, col}, end);
        }
    }
}

int main() {
    struct Maze* maze = createMaze(5, 5);
    setWall(maze, 2, 2);
    setWall(maze, 2, 3);
    setWall(maze, 3, 2);
    setWall(maze, 3, 3);
    struct Position start = findStart(maze);
    struct Position end = findEnd(maze);
    findPath(maze, start, end);
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%c ", maze->grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}