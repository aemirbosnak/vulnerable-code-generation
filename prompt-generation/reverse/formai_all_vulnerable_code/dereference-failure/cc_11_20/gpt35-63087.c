//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Maze structure
typedef struct {
    bool isWall;
    bool visited;
    bool isRoute;
} Cell;

// Function to solve maze
bool solveMaze(Cell* maze[], int row, int col, int endRow, int endCol, int maxRow, int maxCol) {

    if(row < 0 || col < 0 || row >= maxRow || col >= maxCol || !maze[row][col].isWall || maze[row][col].visited) {
        // If the current cell is out of bounds, a wall or already visited, return false
        return false;
    }

    // If we reached the end of the maze, mark the cell as part of the route and return true
    if(row == endRow && col == endCol) {
        maze[row][col].isRoute = true;
        return true;
    }

    // Mark the cell as visited
    maze[row][col].visited = true;

    // Check if we can move up, down, left or right
    if(solveMaze(maze, row-1, col, endRow, endCol, maxRow, maxCol) ||
       solveMaze(maze, row+1, col, endRow, endCol, maxRow, maxCol) ||
       solveMaze(maze, row, col-1, endRow, endCol, maxRow, maxCol) ||
       solveMaze(maze, row, col+1, endRow, endCol, maxRow, maxCol)) {
        // If any of the recursive calls return true, that means we found a route
        maze[row][col].isRoute = true;
        return true;
    }

    // If we reach here, it means we didn't find a route, so mark the cell as not part of the route
    maze[row][col].isRoute = false;
    return false;
}

int main() {

    // Create a maze with 4 rows and 5 columns
    Cell** maze = malloc(sizeof(Cell*) * 4);
    for(int i=0; i<4; i++) {
        maze[i] = malloc(sizeof(Cell) * 5);
        // Initialize all cells as walls
        for(int j=0; j<5; j++) {
            maze[i][j].isWall = true;
            maze[i][j].visited = false;
            maze[i][j].isRoute = false;
        }
    }

    // Create a simple maze
    maze[0][1].isWall = false;
    maze[1][1].isWall = false;
    maze[2][1].isWall = false;
    maze[3][1].isWall = false;
    maze[3][2].isWall = false;
    maze[3][3].isWall = false;
    maze[0][2].isWall = false;
    maze[1][2].isWall = false;
    maze[1][3].isWall = false;

    // Print the maze
    printf("Maze:\n");
    for(int i=0; i<4; i++) {
        for(int j=0; j<5; j++) {
            printf("%c ", maze[i][j].isWall ? '#' : '.');
        }
        printf("\n");
    }

    // Find a route from the top-left corner to the bottom-right corner
    if(solveMaze(maze, 0, 0, 3, 4, 4, 5)) {
        // Print the maze with the found route
        printf("Route:\n");
        for(int i=0; i<4; i++) {
            for(int j=0; j<5; j++) {
                printf("%c ", maze[i][j].isRoute ? '*' : (maze[i][j].isWall ? '#' : '.'));
            }
            printf("\n");
        }
    } else {
        printf("No route found\n");
    }

    // Free memory
    for(int i=0; i<4; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}