//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    point_t *points;
    int size;
} path_t;

int maze[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

path_t *path;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    path = malloc(sizeof(path_t));
    path->points = malloc(sizeof(point_t) * MAX_SIZE);
    path->size = 0;

    if (find_path(0, 0, n - 1, m - 1)) {
        printf("YES\n");
        for (int i = 0; i < path->size; i++) {
            printf("%d %d\n", path->points[i].x, path->points[i].y);
        }
    } else {
        printf("NO\n");
    }

    free(path->points);
    free(path);

    return 0;
}

int find_path(int x, int y, int dest_x, int dest_y) {
    if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE || maze[x][y] == 0 || visited[x][y]) {
        return 0;
    }

    if (x == dest_x && y == dest_y) {
        return 1;
    }

    visited[x][y] = 1;
    path->points[path->size].x = x;
    path->points[path->size].y = y;
    path->size++;

    if (find_path(x + 1, y, dest_x, dest_y)) {
        return 1;
    }

    if (find_path(x - 1, y, dest_x, dest_y)) {
        return 1;
    }

    if (find_path(x, y + 1, dest_x, dest_y)) {
        return 1;
    }

    if (find_path(x, y - 1, dest_x, dest_y)) {
        return 1;
    }

    visited[x][y] = 0;
    path->size--;

    return 0;
}