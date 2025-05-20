//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAZE_SIZE 100
#define MAX_PATH_LENGTH 1000

// Maze representation
char maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
int maze_size;

// Path representation
int path[MAX_PATH_LENGTH];
int path_length;

// Function to display the maze
void display_maze() {
    for (int i = 0; i < maze_size; i++) {
        for (int j = 0; j < maze_size; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to find a path through the maze using a recursive backtracking algorithm
int find_path(int x, int y) {
    // Check if we have reached the end of the maze
    if (x == maze_size - 1 && y == maze_size - 1) {
        return 1;
    }

    // Check if we have hit a wall or visited this square before
    if (maze[x][y] == '#' || maze[x][y] == 'V') {
        return 0;
    }

    // Mark this square as visited
    maze[x][y] = 'V';

    // Try moving in all four directions
    int found_path = 0;
    if (find_path(x + 1, y)) {
        found_path = 1;
    } else if (find_path(x, y + 1)) {
        found_path = 1;
    } else if (find_path(x - 1, y)) {
        found_path = 1;
    } else if (find_path(x, y - 1)) {
        found_path = 1;
    }

    // If we found a path, add this square to the path
    if (found_path) {
        path[path_length++] = x * maze_size + y;
    }

    // Unmark this square as visited
    maze[x][y] = ' ';

    // Return whether or not we found a path
    return found_path;
}

// Main function
int main() {
    // Get the maze size from the user
    printf("Enter the size of the maze: ");
    scanf("%d", &maze_size);

    // Get the maze from the user
    printf("Enter the maze:\n");
    for (int i = 0; i < maze_size; i++) {
        scanf("%s", maze[i]);
    }

    // Display the maze
    printf("Maze:\n");
    display_maze();

    // Find a path through the maze
    if (find_path(0, 0)) {
        // Display the path
        printf("Path:\n");
        for (int i = 0; i < path_length; i++) {
            int x = path[i] / maze_size;
            int y = path[i] % maze_size;
            printf("(%d, %d)\n", x, y);
        }
    } else {
        // No path found
        printf("No path found.\n");
    }

    return 0;
}