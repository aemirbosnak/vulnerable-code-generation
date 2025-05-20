//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to check if a point is inside the grid
int isInside(int x, int y) {
    return (x >= 0 && y >= 0 && x < MAX_ROWS && y < MAX_COLS);
}

// Function to find the minimum number of steps to reach the goal
int findMinSteps(int rows, int cols, int startX, int startY, int goalX, int goalY) {
    int grid[MAX_ROWS][MAX_COLS];
    int visited[MAX_ROWS][MAX_COLS];
    int steps = 0;
    int minSteps = MAX_ROWS * MAX_COLS;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 100000;
            visited[i][j] = 0;
        }
    }

    grid[startX][startY] = 0;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < 4; k++) {
                int x = startX + dx[k];
                int y = startY + dy[k];

                if (isInside(x, y) && grid[x][y] > grid[startX][startY] + 1) {
                    visited[x][y] = 1;
                    grid[x][y] = grid[startX][startY] + 1;

                    if (x == goalX && y == goalY) {
                        minSteps = grid[x][y];
                    }
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!visited[i][j]) {
                grid[i][j] = 100000;
            }
        }
    }

    return minSteps;
}

int main() {
    int rows, cols;
    int startX, startY, goalX, goalY;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the starting and goal coordinates: ");
    scanf("%d %d %d %d", &startX, &startY, &goalX, &goalY);

    int minSteps = findMinSteps(rows, cols, startX, startY, goalX, goalY);

    if (minSteps!= MAX_ROWS * MAX_COLS) {
        printf("Minimum number of steps: %d\n", minSteps);
    } else {
        printf("No path found\n");
    }

    return 0;
}