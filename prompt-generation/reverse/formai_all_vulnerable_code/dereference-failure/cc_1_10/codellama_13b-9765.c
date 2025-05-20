//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: sophisticated
/*
 * A sophisticated Procedurally Generated Maze example program in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maze structure
struct Maze {
    int rows;
    int cols;
    int** grid;
};

// Create a new maze
struct Maze* createMaze(int rows, int cols) {
    struct Maze* maze = malloc(sizeof(struct Maze));
    maze->rows = rows;
    maze->cols = cols;
    maze->grid = malloc(rows * cols * sizeof(int));
    return maze;
}

// Destroy a maze
void destroyMaze(struct Maze* maze) {
    free(maze->grid);
    free(maze);
}

// Generate a random integer between 0 and 1
int randomInt(int max) {
    return rand() % max;
}

// Generate a random direction (N, S, E, W)
char randomDirection() {
    char dirs[4] = {'N', 'S', 'E', 'W'};
    return dirs[randomInt(4)];
}

// Generate a random starting point for the player
void generateStartingPoint(struct Maze* maze) {
    int row = randomInt(maze->rows);
    int col = randomInt(maze->cols);
    maze->grid[row][col] = 1;
}

// Generate the maze
void generateMaze(struct Maze* maze) {
    // Generate the starting point
    generateStartingPoint(maze);

    // Iterate over the grid
    for (int row = 0; row < maze->rows; row++) {
        for (int col = 0; col < maze->cols; col++) {
            // If the cell is not the starting point
            if (maze->grid[row][col] == 0) {
                // Generate a random direction
                char direction = randomDirection();

                // Check if the cell has a wall
                if (direction == 'N' && row > 0 && maze->grid[row - 1][col] == 0) {
                    // Create a wall
                    maze->grid[row][col] = 1;
                } else if (direction == 'S' && row < maze->rows - 1 && maze->grid[row + 1][col] == 0) {
                    // Create a wall
                    maze->grid[row][col] = 1;
                } else if (direction == 'E' && col < maze->cols - 1 && maze->grid[row][col + 1] == 0) {
                    // Create a wall
                    maze->grid[row][col] = 1;
                } else if (direction == 'W' && col > 0 && maze->grid[row][col - 1] == 0) {
                    // Create a wall
                    maze->grid[row][col] = 1;
                }
            }
        }
    }
}

// Print the maze
void printMaze(struct Maze* maze) {
    for (int row = 0; row < maze->rows; row++) {
        for (int col = 0; col < maze->cols; col++) {
            if (maze->grid[row][col] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a new maze
    struct Maze* maze = createMaze(20, 20);

    // Generate the maze
    generateMaze(maze);

    // Print the maze
    printMaze(maze);

    // Destroy the maze
    destroyMaze(maze);

    return 0;
}