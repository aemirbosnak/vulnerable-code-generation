//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
#include <stdio.h>

// The maze: an array of characters representing the walls, corridors, and exit.
char maze[] = {
    '+---+---+---+---+',  // Top wall
    '|   |   |   |   |',  // Corridor
    '+---+---+---+---+',  // Bottom wall
    '|   |   | X |   |',  // Corridor with exit at the end
    '+---+---+---+---+',  // Bottom wall
};

// The size of the maze: the number of rows and columns.
int rows = 5;
int cols = 5;

// The current position of the wanderer: the row and column indices.
int row = 0;
int col = 0;

// A function to print the maze.
void printMaze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", maze[i * cols + j]);
        }
        printf("\n");
    }
}

// A function to check if the current position is the exit.
int isExit() {
    return maze[row * cols + col] == 'X';
}

// A function to check if the current position is a corridor.
int isCorridor() {
    return maze[row * cols + col] == ' ';
}

// A function to check if the current position is a wall.
int isWall() {
    return maze[row * cols + col] == '+';
}

// A function to move the wanderer one step to the right.
void moveRight() {
    col++;
}

// A function to move the wanderer one step to the left.
void moveLeft() {
    col--;
}

// A function to move the wanderer one step down.
void moveDown() {
    row++;
}

// A function to move the wanderer one step up.
void moveUp() {
    row--;
}

// A function to find a solution for the maze.
int findSolution() {
    // If the current position is the exit, then the solution is found.
    if (isExit()) {
        return 1;
    }

    // If the current position is a wall, then there is no solution.
    if (isWall()) {
        return 0;
    }

    // If the current position is a corridor, then explore the possible paths.
    if (isCorridor()) {
        // Try to move right.
        moveRight();
        if (findSolution()) {
            return 1;
        }
        moveLeft();

        // Try to move left.
        moveLeft();
        if (findSolution()) {
            return 1;
        }
        moveRight();

        // Try to move down.
        moveDown();
        if (findSolution()) {
            return 1;
        }
        moveUp();

        // Try to move up.
        moveUp();
        if (findSolution()) {
            return 1;
        }
        moveDown();
    }

    // If no solution is found, then return 0.
    return 0;
}

// The main function.
int main() {
    // Print the initial maze.
    printMaze();

    // Find a solution for the maze.
    int solutionFound = findSolution();

    // Print the final maze.
    printMaze();

    // Print the result.
    if (solutionFound) {
        printf("Solution found!\n");
    } else {
        printf("No solution found.\n");
    }

    return 0;
}