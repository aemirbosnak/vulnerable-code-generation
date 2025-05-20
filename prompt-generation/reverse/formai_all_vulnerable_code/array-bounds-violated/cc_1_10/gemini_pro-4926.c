//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define the dimensions of the maze
#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

// Define the possible directions of movement
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

// Define the structure of a cell in the maze
typedef struct cell {
    bool visited;
    bool walls[4];
} cell;

// Create a new maze
cell maze[MAZE_WIDTH][MAZE_HEIGHT];

// Generate a maze using a depth-first search algorithm
void generate_maze() {
    // Start at a random cell
    int x = rand() % MAZE_WIDTH;
    int y = rand() % MAZE_HEIGHT;

    // Mark the current cell as visited
    maze[x][y].visited = true;

    // While there are still unvisited cells
    while (true) {
        // Get a list of all the unvisited neighbors of the current cell
        int neighbors[4];
        int num_neighbors = 0;
        if (!maze[x][y].walls[UP] && !maze[x][y - 1].visited) {
            neighbors[num_neighbors++] = UP;
        }
        if (!maze[x][y].walls[RIGHT] && !maze[x + 1][y].visited) {
            neighbors[num_neighbors++] = RIGHT;
        }
        if (!maze[x][y].walls[DOWN] && !maze[x][y + 1].visited) {
            neighbors[num_neighbors++] = DOWN;
        }
        if (!maze[x][y].walls[LEFT] && !maze[x - 1][y].visited) {
            neighbors[num_neighbors++] = LEFT;
        }

        // If there are no unvisited neighbors, backtrack
        if (num_neighbors == 0) {
            break;
        }

        // Choose a random neighbor
        int neighbor = neighbors[rand() % num_neighbors];

        // Remove the wall between the current cell and the neighbor
        switch (neighbor) {
            case UP:
                maze[x][y].walls[UP] = false;
                maze[x][y - 1].walls[DOWN] = false;
                break;
            case RIGHT:
                maze[x][y].walls[RIGHT] = false;
                maze[x + 1][y].walls[LEFT] = false;
                break;
            case DOWN:
                maze[x][y].walls[DOWN] = false;
                maze[x][y + 1].walls[UP] = false;
                break;
            case LEFT:
                maze[x][y].walls[LEFT] = false;
                maze[x - 1][y].walls[RIGHT] = false;
                break;
        }

        // Move to the neighbor
        switch (neighbor) {
            case UP:
                y--;
                break;
            case RIGHT:
                x++;
                break;
            case DOWN:
                y++;
                break;
            case LEFT:
                x--;
                break;
        }

        // Mark the new cell as visited
        maze[x][y].visited = true;
    }
}

// Print the maze to the console
void print_maze() {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (maze[x][y].walls[UP]) {
                printf("+---+");
            } else {
                printf("+   +");
            }
        }
        printf("+\n");

        for (int y = 0; y < MAZE_HEIGHT; y++) {
            for (int x = 0; x < MAZE_WIDTH; x++) {
                if (maze[x][y].walls[LEFT]) {
                    printf("|   ");
                } else {
                    printf("    ");
                }
            }
            printf("|\n");
        }

        for (int y = 0; y < MAZE_HEIGHT; y++) {
            for (int x = 0; x < MAZE_WIDTH; x++) {
                if (maze[x][y].walls[DOWN]) {
                    printf("+---+");
                } else {
                    printf("+   +");
                }
            }
            printf("+\n");
        }
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate the maze
    generate_maze();

    // Print the maze to the console
    print_maze();

    return 0;
}