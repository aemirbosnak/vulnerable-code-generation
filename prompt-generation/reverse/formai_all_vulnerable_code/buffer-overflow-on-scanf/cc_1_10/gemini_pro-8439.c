//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Path;

typedef struct {
    int **grid;
    int width;
    int height;
} Maze;

Maze *create_maze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        maze->grid[i] = malloc(sizeof(int) * width);
    }
    return maze;
}

void free_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

Path *create_path() {
    Path *path = malloc(sizeof(Path));
    path->points = malloc(sizeof(Point) * MAX_SIZE);
    path->size = 0;
    return path;
}

void free_path(Path *path) {
    free(path->points);
    free(path);
}

bool is_valid_point(Maze *maze, Point point) {
    return point.x >= 0 && point.x < maze->width && point.y >= 0 && point.y < maze->height && maze->grid[point.y][point.x] == 0;
}

bool is_path_valid(Maze *maze, Path *path) {
    for (int i = 0; i < path->size; i++) {
        if (!is_valid_point(maze, path->points[i])) {
            return false;
        }
    }
    return true;
}

void add_point_to_path(Path *path, Point point) {
    path->points[path->size] = point;
    path->size++;
}

bool find_path(Maze *maze, Point start, Point end, Path *path) {
    if (start.x == end.x && start.y == end.y) {
        return true;
    }
    add_point_to_path(path, start);
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            Point next = {start.x + i, start.y + j};
            if (is_valid_point(maze, next)) {
                if (find_path(maze, next, end, path)) {
                    return true;
                }
            }
        }
    }
    path->size--;
    return false;
}

int main() {
    int width, height;
    printf("Enter the width and height of the maze: ");
    scanf("%d %d", &width, &height);

    Maze *maze = create_maze(width, height);
    printf("Enter the maze data (0 for empty, 1 for wall):\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &maze->grid[i][j]);
        }
    }

    Point start, end;
    printf("Enter the starting point (x, y): ");
    scanf("%d %d", &start.x, &start.y);
    printf("Enter the ending point (x, y): ");
    scanf("%d %d", &end.x, &end.y);

    Path *path = create_path();
    bool found = find_path(maze, start, end, path);
    if (found) {
        printf("Path found:\n");
        for (int i = 0; i < path->size; i++) {
            printf("(%d, %d)\n", path->points[i].x, path->points[i].y);
        }
    } else {
        printf("No path found.\n");
    }

    free_path(path);
    free_maze(maze);
    return 0;
}