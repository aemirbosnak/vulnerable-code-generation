//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct {
    int x;
    int y;
} Point;

int isSafe(int maze[MAX_SIZE][MAX_SIZE], int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0);
}

int findPath(int maze[MAX_SIZE][MAX_SIZE], int x, int y, int n, Point path[], int step) {
    if (x == n-1 && y == n-1) {
        path[step].x = x;
        path[step].y = y;
        return 1;
    }

    if (isSafe(maze, x, y, n)) {
        path[step].x = x;
        path[step].y = y;

        if (findPath(maze, x + 1, y, n, path, step + 1))
            return 1;

        if (findPath(maze, x, y + 1, n, path, step + 1))
            return 1;

        if (findPath(maze, x - 1, y, n, path, step + 1))
            return 1;

        if (findPath(maze, x, y - 1, n, path, step + 1))
            return 1;
    }

    return 0;
}

void printPath(Point path[], int step) {
    printf("Path to exit:\n");
    for (int i = 0; i <= step; i++) {
        printf("(%d, %d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

int main() {
    int n, i, j;
    int maze[MAX_SIZE][MAX_SIZE];
    Point path[MAX_SIZE * MAX_SIZE];

    printf("Enter size of the maze (n x n, n <= %d): ", MAX_SIZE);
    scanf("%d", &n);

    if(n > MAX_SIZE) {
        printf("Size exceeds maximum limit of %d. Exiting.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the maze (0 = free path, 1 = wall):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    if (maze[0][0] == 1 || maze[n-1][n-1] == 1) {
        printf("No path available from the entrance to the exit.\n");
        return 1;
    }

    if (findPath(maze, 0, 0, n, path, 0))
        printPath(path, n + n - 2);  // Maximum steps needed to traverse in a worst-case grid
    else
        printf("No path exists to reach the exit.\n");

    return 0;
}