//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 10
#define WALL 1
#define PATH 0

/* The paranoid maze route finder */
int main() {
    int maze[MAZE_SIZE][MAZE_SIZE] = { {1,1,1,1,1,1,1,1,1,1},
                                       {1,0,0,0,1,0,1,0,0,1},
                                       {1,0,1,0,1,0,1,0,1,1},
                                       {1,0,1,0,1,0,1,0,1,1},
                                       {1,0,1,0,1,0,1,0,1,1},
                                       {1,0,0,0,0,0,0,0,0,1},
                                       {1,0,1,1,1,0,1,1,1,1},
                                       {1,0,0,0,0,0,1,0,0,1},
                                       {1,1,1,1,1,0,1,1,0,1},
                                       {1,1,1,1,1,1,1,1,1,1}
                                     };

    int start_row, start_col, end_row, end_col;
    
    // Paranoid input...
    printf("Enter the starting row (must be between 1 and %d): ", MAZE_SIZE);
    scanf("%d", &start_row);
    if (start_row < 1 || start_row > MAZE_SIZE) {
        printf("Invalid input... exiting program.\n");
        return 1; // Error code
    }
    printf("Enter the starting column (must be between 1 and %d): ", MAZE_SIZE);
    scanf("%d", &start_col);
    if (start_col < 1 || start_col > MAZE_SIZE) {
        printf("Invalid input... exiting program.\n");
        return 1; // Error code
    }
    printf("Enter the ending row (must be between 1 and %d): ", MAZE_SIZE);
    scanf("%d", &end_row);
    if (end_row < 1 || end_row > MAZE_SIZE) {
        printf("Invalid input... exiting program.\n");
        return 1; // Error code
    }
    printf("Enter the ending column (must be between 1 and %d): ", MAZE_SIZE);
    scanf("%d", &end_col);
    if (end_col < 1 || end_col > MAZE_SIZE) {
        printf("Invalid input... exiting program.\n");
        return 1; // Error code
    }
    
    // Protect against sneaky input
    start_row--;
    start_col--;
    end_row--;
    end_col--;
    if (maze[start_row][start_col] == WALL || maze[end_row][end_col] == WALL) {
        printf("Invalid input... starting or ending position is a wall. Exiting program.");
        return 1;
    }
    
    printf("\nFinding the best path...\n");
    
    // Dijkstra's algorithm for finding the shortest path
    int distances[MAZE_SIZE][MAZE_SIZE] = {0};
    bool visited[MAZE_SIZE][MAZE_SIZE] = {false};
    int row, col, count, min_distance;
    
    // Initialize the distances matrix
    for (row = 0; row < MAZE_SIZE; row++) {
        for (col = 0; col < MAZE_SIZE; col++) {
            if (maze[row][col] == WALL) {
                distances[row][col] = -1;
            }
            else {
                distances[row][col] = MAZE_SIZE * MAZE_SIZE;
            }
        }
    }
    distances[start_row][start_col] = 0;
    visited[start_row][start_col] = true;
    count = 1;
    while (count < MAZE_SIZE * MAZE_SIZE) {
        // Find the minimum distance
        min_distance = MAZE_SIZE * MAZE_SIZE;
        for (row = 0; row < MAZE_SIZE; row++) {
            for (col = 0; col < MAZE_SIZE; col++) {
                if (!visited[row][col] && distances[row][col] < min_distance) {
                    min_distance = distances[row][col];
                }
            }
        }
        // Mark as visited and update distances of neighbors
        for (row = 0; row < MAZE_SIZE; row++) {
            for (col = 0; col < MAZE_SIZE; col++) {
                if (!visited[row][col] && distances[row][col] == min_distance) {
                    visited[row][col] = true;
                    if (row > 0 && distances[row - 1][col] == MAZE_SIZE * MAZE_SIZE) {
                        distances[row - 1][col] = min_distance + 1;
                    }
                    if (row < MAZE_SIZE - 1 && distances[row + 1][col] == MAZE_SIZE * MAZE_SIZE) {
                        distances[row + 1][col] = min_distance + 1;
                    }
                    if (col > 0 && distances[row][col - 1] == MAZE_SIZE * MAZE_SIZE) {
                        distances[row][col - 1] = min_distance + 1;
                    }
                    if (col < MAZE_SIZE - 1 && distances[row][col + 1] == MAZE_SIZE * MAZE_SIZE) {
                        distances[row][col + 1] = min_distance + 1;
                    }
                    count++;
                }
            }
        }
    }
    
    // Paranoid check for valid end point
    if (distances[end_row][end_col] == MAZE_SIZE * MAZE_SIZE) {
        printf("No valid path found. Exiting program.");
        return 1;
    }
    
    // Build the path in reverse order
    int path[MAZE_SIZE * MAZE_SIZE][2];
    int path_count = 0;
    row = end_row;
    col = end_col;
    while (row != start_row || col != start_col) {
        path[path_count][0] = row;
        path[path_count][1] = col;
        path_count++;
        if (row > 0 && distances[row - 1][col] == distances[row][col] - 1) {
            row--;
        }
        else if (row < MAZE_SIZE - 1 && distances[row + 1][col] == distances[row][col] - 1) {
            row++;
        }
        else if (col > 0 && distances[row][col - 1] == distances[row][col] - 1) {
            col--;
        }
        else if (col < MAZE_SIZE - 1 && distances[row][col + 1] == distances[row][col] - 1) {
            col++;
        }
        else {
            printf("Invalid path. Exiting program.");
            return 1;
        }
    }
    path[path_count][0] = start_row;
    path[path_count][1] = start_col;
    path_count++;
    
    // Output the path
    int i, j;
    for (i = path_count - 1; i >= 0; i--) {
        maze[path[i][0]][path[i][1]] = PATH;
    }
    printf("\nMaze with path:\n\n");
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
           if (maze[i][j] == WALL) {
               printf("%c", 219);
           }
           else if (maze[i][j] == PATH) {
               printf("%c", 178);
           }
           else {
               printf("%c", 32);
           }
        }
        printf("\n");
    }
    
    return 0; // Success!
}