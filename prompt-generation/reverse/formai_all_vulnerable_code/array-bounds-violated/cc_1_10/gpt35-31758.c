//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#define MAX_SIZE 10

int maze[MAX_SIZE][MAX_SIZE], path[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE][MAX_SIZE];
int startX, startY, exitX, exitY, pathLength = 0;
int rows, cols;

// Function to print the maze
void printMaze() {
    printf("\nTHE MAZE\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to print the path
void printPath() {
    printf("\nTHE PATH\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current position is a valid move
int isValidMove(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        return 0;
    if (maze[row][col] == 0 || visited[row][col])
        return 0;
    return 1;
}

// Function to find the route
int findRoute(int row, int col) {
    if (row == exitX && col == exitY) {
        path[row][col] = 1;
        pathLength++;
        return 1;
    }
    visited[row][col] = 1;
    if (isValidMove(row-1, col)) { // move up
        if (findRoute(row-1, col)) {
            path[row][col] = 1;
            pathLength++;
            return 1;
        }
    }
    if (isValidMove(row, col+1)) { // move right
        if (findRoute(row, col+1)) {
            path[row][col] = 1;
            pathLength++;
            return 1;
        }
    }
    if (isValidMove(row+1, col)) { // move down
        if (findRoute(row+1, col)) {
            path[row][col] = 1;
            pathLength++;
            return 1;
        }
    }
    if (isValidMove(row, col-1)) { // move left
        if (findRoute(row, col-1)) {
            path[row][col] = 1;
            pathLength++;
            return 1;
        }
    }
    return 0;
}

int main() {
    printf("Enter the number of rows and columns separated by a space: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the maze (0 for walls, 1 for open spaces):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    printMaze();

    printf("Enter the start position (row and column separated by a space): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter the exit position (row and column separated by a space): ");
    scanf("%d %d", &exitX, &exitY);

    findRoute(startX, startY);

    if (pathLength > 0) {
        printf("\nPath Found!\n");
        printPath();
    }
    else {
        printf("\nNo Path Found :(\n");
    }

    return 0;
}