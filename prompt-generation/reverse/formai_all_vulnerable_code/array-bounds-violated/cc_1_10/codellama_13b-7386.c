//Code Llama-13B DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
/*
 * Maze Route Finder in C
 *
 * Prompts the user for a maze and a start point, then finds a path through the maze to the exit.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MAZE_SIZE 100
#define MAX_PATH_LENGTH 100

// Struct to represent a maze
struct Maze {
    int size;
    char maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
    int start_x, start_y;
    int end_x, end_y;
};

// Struct to represent a path
struct Path {
    int length;
    int x[MAX_PATH_LENGTH];
    int y[MAX_PATH_LENGTH];
};

// Function to read a maze from the user
struct Maze read_maze() {
    struct Maze maze;
    char input[MAX_MAZE_SIZE];

    printf("Enter the maze (size, start, end): ");
    scanf("%d %d %d %d", &maze.size, &maze.start_x, &maze.start_y, &maze.end_x, &maze.end_y);

    for (int i = 0; i < maze.size; i++) {
        scanf("%s", input);
        for (int j = 0; j < maze.size; j++) {
            maze.maze[i][j] = input[j];
        }
    }

    return maze;
}

// Function to find a path through the maze
struct Path find_path(struct Maze maze) {
    struct Path path;
    path.length = 0;

    int x = maze.start_x;
    int y = maze.start_y;

    while (x != maze.end_x || y != maze.end_y) {
        if (x < maze.size - 1 && maze.maze[x + 1][y] != '#') {
            x++;
        } else if (x > 0 && maze.maze[x - 1][y] != '#') {
            x--;
        } else if (y < maze.size - 1 && maze.maze[x][y + 1] != '#') {
            y++;
        } else if (y > 0 && maze.maze[x][y - 1] != '#') {
            y--;
        } else {
            break;
        }
        path.x[path.length] = x;
        path.y[path.length] = y;
        path.length++;
    }

    return path;
}

// Function to print the path
void print_path(struct Path path) {
    printf("Path: ");
    for (int i = 0; i < path.length; i++) {
        printf("(%d, %d) ", path.x[i], path.y[i]);
    }
    printf("\n");
}

int main() {
    struct Maze maze = read_maze();
    struct Path path = find_path(maze);
    print_path(path);
    return 0;
}