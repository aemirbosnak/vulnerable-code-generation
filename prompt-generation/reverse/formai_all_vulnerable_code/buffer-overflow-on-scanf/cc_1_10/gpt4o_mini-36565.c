//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int size;       // Number of points in the path
    int capacity;   // Current capacity of the path array
} Path;

void initPath(Path *path, int capacity) {
    path->points = (Point *)malloc(capacity * sizeof(Point));
    path->size = 0;
    path->capacity = capacity;
}

void addPoint(Path *path, int x, int y) {
    if (path->size >= path->capacity) {
        path->capacity *= 2;
        path->points = (Point *)realloc(path->points, path->capacity * sizeof(Point));
    }
    path->points[path->size].x = x;
    path->points[path->size].y = y;
    path->size++;
}

void freePath(Path *path) {
    free(path->points);
    path->points = NULL;
    path->size = 0; 
    path->capacity = 0; 
}

bool isSafe(int **maze, int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

bool findPath(int **maze, int x, int y, int n, Path *path) {
    if (x == n - 1 && y == n - 1) {
        addPoint(path, x, y);
        return true;
    }
    if (isSafe(maze, x, y, n)) {
        addPoint(path, x, y);
        maze[x][y] = -1; // Mark as visited
        
        if (findPath(maze, x + 1, y, n, path)) return true; // Move Down
        if (findPath(maze, x, y + 1, n, path)) return true; // Move Right
        if (findPath(maze, x - 1, y, n, path)) return true; // Move Up
        if (findPath(maze, x, y - 1, n, path)) return true; // Move Left

        // Backtrack
        maze[x][y] = 1;
        path->size--; // Remove the point from path
    }
    return false;
}

void printSolution(Path *path) {
    printf("Path from start to end:\n");
    for (int i = 0; i < path->size; i++) {
        printf("(%d, %d) ", path->points[i].x, path->points[i].y);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the maze (n x n): ");
    scanf("%d", &n);
    
    int **maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        maze[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the maze (1 for path, 0 for wall):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    Path path;
    initPath(&path, 10);

    if (findPath(maze, 0, 0, n, &path)) {
        printSolution(&path);
    } else {
        printf("No path found!\n");
    }

    // Free allocated memory
    freePath(&path);
    for (int i = 0; i < n; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}