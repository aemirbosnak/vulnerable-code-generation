//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

point start, end;
int maze[100][100];
int visited[100][100];

int main() {
    // Read input
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
            visited[i][j] = 0;
        }
    }
    scanf("%d %d", &start.x, &start.y);
    scanf("%d %d", &end.x, &end.y);

    // Find path
    visited[start.x][start.y] = 1;
    point queue[n * m];
    int front = 0, rear = 0;
    queue[rear++] = start;
    while (front != rear) {
        point current = queue[front++];
        if (current.x == end.x && current.y == end.y) {
            break;
        }
        if (current.x - 1 >= 0 && maze[current.x - 1][current.y] == 0 && visited[current.x - 1][current.y] == 0) {
            visited[current.x - 1][current.y] = 1;
            queue[rear++] = (point) { .x = current.x - 1, .y = current.y };
        }
        if (current.x + 1 < n && maze[current.x + 1][current.y] == 0 && visited[current.x + 1][current.y] == 0) {
            visited[current.x + 1][current.y] = 1;
            queue[rear++] = (point) { .x = current.x + 1, .y = current.y };
        }
        if (current.y - 1 >= 0 && maze[current.x][current.y - 1] == 0 && visited[current.x][current.y - 1] == 0) {
            visited[current.x][current.y - 1] = 1;
            queue[rear++] = (point) { .x = current.x, .y = current.y - 1 };
        }
        if (current.y + 1 < m && maze[current.x][current.y + 1] == 0 && visited[current.x][current.y + 1] == 0) {
            visited[current.x][current.y + 1] = 1;
            queue[rear++] = (point) { .x = current.x, .y = current.y + 1 };
        }
    }

    // Print path
    if (front != rear) {
        point path[n * m];
        int length = 0;
        path[length++] = end;
        while (path[length - 1].x != start.x || path[length - 1].y != start.y) {
            if (path[length - 1].x - 1 >= 0 && visited[path[length - 1].x - 1][path[length - 1].y] == 1) {
                path[length++] = (point) { .x = path[length - 1].x - 1, .y = path[length - 1].y };
            } else if (path[length - 1].x + 1 < n && visited[path[length - 1].x + 1][path[length - 1].y] == 1) {
                path[length++] = (point) { .x = path[length - 1].x + 1, .y = path[length - 1].y };
            } else if (path[length - 1].y - 1 >= 0 && visited[path[length - 1].x][path[length - 1].y - 1] == 1) {
                path[length++] = (point) { .x = path[length - 1].x, .y = path[length - 1].y - 1 };
            } else if (path[length - 1].y + 1 < m && visited[path[length - 1].x][path[length - 1].y + 1] == 1) {
                path[length++] = (point) { .x = path[length - 1].x, .y = path[length - 1].y + 1 };
            }
        }
        for (int i = length - 1; i >= 0; i--) {
            printf("%d %d\n", path[i].x + 1, path[i].y + 1);
        }
    } else {
        printf("No path found\n");
    }

    return 0;
}