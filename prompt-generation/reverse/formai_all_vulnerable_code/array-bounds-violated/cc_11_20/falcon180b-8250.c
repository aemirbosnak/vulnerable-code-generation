//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10

// Define the maze
char maze[HEIGHT][WIDTH] = {
    "1111111111",
    "1000000000",
    "1000000000",
    "1000000000",
    "1000000000",
    "1000000000",
    "1000000000",
    "1000000000",
    "1000000000",
    "1111111111"
};

// Define the starting and ending points
int startX = 0, startY = 0;
int endX = 9, endY = 9;

// Define the pathfinding algorithm
void pathfinding(int x, int y) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int count = 0;
    int path[HEIGHT][WIDTH];

    // Initialize the path array
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            path[i][j] = -1;
        }
    }

    // Mark the starting point
    path[x][y] = 0;

    // Perform the algorithm
    while (count < HEIGHT * WIDTH) {
        // Find the unvisited neighbor with the lowest cost
        int lowestCost = HEIGHT * WIDTH;
        int u = -1, v = -1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH && path[nx][ny] == -1) {
                int cost = 0;
                if (maze[nx][ny] == '1') {
                    cost = 10;
                } else if (maze[nx][ny] == '0') {
                    cost = 1;
                }
                if (cost < lowestCost) {
                    lowestCost = cost;
                    u = nx;
                    v = ny;
                }
            }
        }

        // Update the path and mark the current point as visited
        path[u][v] = count++;
        x = u;
        y = v;
    }

    // Print the path
    printf("Path: ");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (path[i][j]!= -1) {
                printf("(%d,%d) ", i, j);
            }
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Initialize the maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == '0') {
                maze[i][j] = rand() % 2 + '0';
            }
        }
    }

    // Print the maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    // Perform the pathfinding algorithm
    pathfinding(startX, startY);

    return 0;
}