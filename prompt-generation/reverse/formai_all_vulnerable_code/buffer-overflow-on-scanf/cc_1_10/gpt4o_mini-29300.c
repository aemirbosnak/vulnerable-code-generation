//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 5

// Function declarations
void printMaze(char maze[MAZE_SIZE][MAZE_SIZE]);
int navigateMaze(char maze[MAZE_SIZE][MAZE_SIZE], int x, int y);
void displayInstructions();

int main() {
    char maze[MAZE_SIZE][MAZE_SIZE] = {
        {'S', '.', '.', '#', 'E'},
        {'.', '#', '.', '#', '.'},
        {'.', '#', '.', '.', '.'},
        {'.', '.', '#', '#', '.'},
        {'#', '.', '.', '#', '#'}
    };

    int x = 0, y = 0; // Starting position
    printf("Welcome to the Maze Game!\n");
    displayInstructions();

    printMaze(maze);

    // Start navigating the maze
    int success = navigateMaze(maze, x, y);

    if (success) {
        printf("Congratulations! You've escaped the maze!\n");
    } else {
        printf("Game Over! You hit a wall!\n");
    }

    return 0;
}

// Function to print the maze
void printMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\nCurrent Maze:\n");
    for (int row = 0; row < MAZE_SIZE; row++) {
        for (int col = 0; col < MAZE_SIZE; col++) {
            printf("%c ", maze[row][col]);
        }
        printf("\n");
    }
}

// Function to navigate the maze
int navigateMaze(char maze[MAZE_SIZE][MAZE_SIZE], int x, int y) {
    char move;
    while (1) {
        printf("\nEnter your move (W/A/S/D): ");
        scanf(" %c", &move);

        switch (move) {
            case 'W':
            case 'w':
                if (x > 0 && maze[x - 1][y] != '#') {
                    x--;
                } break;

            case 'A':
            case 'a':
                if (y > 0 && maze[x][y - 1] != '#') {
                    y--;
                } break;

            case 'S':
            case 's':
                if (x < MAZE_SIZE - 1 && maze[x + 1][y] != '#') {
                    x++;
                } break;

            case 'D':
            case 'd':
                if (y < MAZE_SIZE - 1 && maze[x][y + 1] != '#') {
                    y++;
                } break;

            default:
                printf("Invalid move! Use W, A, S, D to navigate.\n");
                continue;
        }

        // Check for end or wall
        if (maze[x][y] == 'E') {
            return 1; // Success
        }
        
        if (maze[x][y] == '#') {
            return 0; // Hit a wall
        }

        // Update the current position in the maze
        maze[x][y] = 'P'; // Mark the player's position
        printMaze(maze);
    }

    return 0; // Should never reach here
}

// Function to display game instructions
void displayInstructions() {
    printf("Instructions:\n");
    printf(" - Use 'W' to move up\n");
    printf(" - Use 'A' to move left\n");
    printf(" - Use 'S' to move down\n");
    printf(" - Use 'D' to move right\n");
    printf(" - Reach the 'E' to escape the maze.\n");
}