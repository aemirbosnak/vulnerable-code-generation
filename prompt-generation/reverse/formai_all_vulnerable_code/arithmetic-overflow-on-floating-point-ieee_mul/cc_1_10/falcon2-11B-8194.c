//Falcon2-11B DATASET v1.0 Category: Geometric algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to find the shortest path between two points on a 2D grid
int shortestPath(int x1, int y1, int x2, int y2) {
    // Create a 2D grid of size (x2 - x1 + 1) x (y2 - y1 + 1)
    int grid[x2 - x1 + 1][y2 - y1 + 1];

    // Fill the grid with the initial distance to each cell
    for (int i = 0; i < x2 - x1 + 1; i++) {
        for (int j = 0; j < y2 - y1 + 1; j++) {
            grid[i][j] = distance(x1, y1, i, j);
        }
    }

    // Create a set of visited cells
    int visited[x2 - x1 + 1][y2 - y1 + 1];
    for (int i = 0; i < x2 - x1 + 1; i++) {
        for (int j = 0; j < y2 - y1 + 1; j++) {
            visited[i][j] = 0;
        }
    }

    // Find the shortest path using Dijkstra's algorithm
    int start = 0;
    int goal = x2 - x1 + 1;
    int previous[x2 - x1 + 1][y2 - y1 + 1];
    for (int i = 0; i < x2 - x1 + 1; i++) {
        for (int j = 0; j < y2 - y1 + 1; j++) {
            if (grid[i][j] == 0 && visited[i][j] == 0) {
                grid[i][j] = distance(x1, y1, i, j);
                previous[i][j] = -1;
                int k = 0;
                for (int m = 0; m < x2 - x1 + 1; m++) {
                    for (int n = 0; n < y2 - y1 + 1; n++) {
                        if (grid[i][j] + grid[m][n] < grid[m][n]) {
                            grid[m][n] = grid[i][j] + grid[m][n];
                            previous[m][n] = (i * (x2 - x1 + 1) + j) * (m * (y2 - y1 + 1) + n);
                        }
                    }
                }
            }
        }
    }

    // Backtrack from the goal to the start to find the shortest path
    int path[x2 - x1 + 1][y2 - y1 + 1];
    int index = x2 - x1 + 1;
    int cell = x2 - x1 + 1;
    while (index!= start) {
        path[index][y2 - y1 + 1] = cell;
        cell = previous[index][y2 - y1 + 1];
        index -= 1;
    }

    // Print the shortest path
    printf("Shortest path: (%d, %d) -> ", x1, y1);
    for (int i = 0; i < x2 - x1 + 1; i++) {
        printf("%d, ", path[i][0]);
    }
    printf("%d\n", path[0][0]);

    return 0;
}

int main() {
    int x1 = 0;
    int y1 = 0;
    int x2 = 4;
    int y2 = 4;
    shortestPath(x1, y1, x2, y2);
    return 0;
}