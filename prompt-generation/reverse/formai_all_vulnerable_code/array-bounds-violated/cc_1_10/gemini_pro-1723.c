//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 10
#define HEIGHT 10

/* A cell in the maze. */
typedef struct cell {
    int x, y;
    int walls[4]; // 0: north, 1: east, 2: south, 3: west
} cell;
/* The maze itself. */
cell maze[WIDTH][HEIGHT];

/* Initialize the maze. */
void init_maze() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            maze[i][j].x = i;
            maze[i][j].y = j;
            for (int k = 0; k < 4; k++) {
                maze[i][j].walls[k] = 1;
            }
        }
    }
}

/* Print the maze. */
void print_maze() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            for (int k = 0; k < 4; k++) {
                if (maze[i][j].walls[k]) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

/* Generate a maze using a recursive backtracker. 
Begin at the top left cell and randomly choose to break one or more of the cell's walls. */
void generate_maze() {
    int i, j;
    // Start at the top left cell.
    i = 0;
    j = 0;
    // Mark the current cell as visited.
    maze[i][j].walls[0] = 0;
    // While there are still unvisited cells,
    while (i != WIDTH - 1 || j != HEIGHT - 1) {
        // Randomly choose a direction to move.
        int direction = rand() % 4;
        // If the chosen direction is valid,
        if (!maze[i][j].walls[direction]) {
            // Move in the chosen direction.
            switch (direction) {
                case 0: // North
                    j--;
                    break;
                case 1: // East
                    i++;
                    break;
                case 2: // South
                    j++;
                    break;
                case 3: // West
                    i--;
                    break;
            }
            // Mark the current  cell as visited.
            maze[i][j].walls[0] = 0;
        }
    }
}

int main() {
    // Initialize the random number generator.
    srand(time(NULL));
    // Initialize the maze.
    init_maze();
    // Generate the maze.
    generate_maze();
    // Print the maze.
    print_maze();
    return 0;
}