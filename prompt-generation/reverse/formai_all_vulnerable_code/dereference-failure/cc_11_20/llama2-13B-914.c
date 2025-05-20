//LLAMA2-13B DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Surprise! You're in a maze!

int main() {
    // You're here! 😱
    printf("You're in a maze! 😱\n");

    // Generate a random maze
    int rows = 10;
    int cols = 10;
    int** maze = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        maze[i] = (int*) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            maze[i][j] = (rand() % 2) ? 1 : 0; // Randomly generate walls
        }
    }

    // Start at the top-left corner
    int x = 0;
    int y = 0;

    // Loop until you find the exit
    while (1) {
        // Print the current position
        printf("You're at (%d, %d).\n", x, y);

        // Check if you've found the exit
        if (maze[y][x] == 0) {
            break; // You found the exit!
        }

        // Move down or right
        if (maze[y][x] == 1) {
            y++; // Go down
        } else {
            x++; // Go right
        }

        // Check if you've gone off the board
        if (y >= rows || x >= cols || y < 0 || x < 0) {
            break; // You went off the board!
        }
    }

    // Print the final position
    printf("You found the exit at (%d, %d).\n", x, y);

    // Free the maze memory
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}