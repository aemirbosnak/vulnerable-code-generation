//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int maze[MAX][MAX], sol[MAX][MAX];
int N; // Size of the maze

// Function to print the maze solution
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(sol[i][j] == 1) {
                printf(" * "); // Path taken
            } else {
                printf(" . "); // Empty space
            }
        }
        printf("\n");
    }
}

// Function to check if a cell is valid
int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Maze Solver using Depth First Search
int solveMaze(int x, int y) {
    // If we reached the bottom-right corner
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1; // Mark as part of the solution
        return 1;
    }

    // Check if current cell is valid
    if (isSafe(x, y)) {
        sol[x][y] = 1; // Mark as part of the solution

        // Move forward in x direction
        if (solveMaze(x + 1, y)) {
            return 1;
        }
        // If moving in x direction doesn't give solution then 
        // move down in y direction
        if (solveMaze(x, y + 1)) {
            return 1;
        }

        // If neither forward nor down worked then backtrack
        sol[x][y] = 0; // Remove from solution
        return 0;
    }
    return 0;
}

// Function to take input for the maze
void inputMaze() {
    printf("Enter the size of the maze (N x N, max %dx%d): ", MAX, MAX);
    scanf("%d", &N);

    printf("Enter the maze (%d x %d grid of 0s and 1s): \n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
            sol[i][j] = 0; // Initialize the solution grid
        }
    }
}

// Main function
int main() {
    inputMaze();

    if (solveMaze(0, 0)) {
        printf("Found a path through the maze:\n");
        printSolution();
    } else {
        printf("No path exists in the maze.\n");
    }

    return 0;
}