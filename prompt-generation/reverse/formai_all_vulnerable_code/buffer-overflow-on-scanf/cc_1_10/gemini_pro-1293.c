//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int maze[SIZE][SIZE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int visited[SIZE][SIZE];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

typedef struct {
    int x;
    int y;
} point;

point queue[SIZE * SIZE];
int front = 0;
int rear = 0;

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

point dequeue() {
    point p = queue[front];
    front++;
    return p;
}

int is_valid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && maze[x][y] == 0 && !visited[x][y];
}

int find_path(int sx, int sy, int ex, int ey) {
    enqueue(sx, sy);
    visited[sx][sy] = 1;

    while (front != rear) {
        point p = dequeue();

        if (p.x == ex && p.y == ey) {
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (is_valid(nx, ny)) {
                enqueue(nx, ny);
                visited[nx][ny] = 1;
            }
        }
    }

    return 0;
}

int main() {
    int sx, sy, ex, ey;
    printf("Enter the starting point (x, y): ");
    scanf("%d %d", &sx, &sy);
    printf("Enter the ending point (x, y): ");
    scanf("%d %d", &ex, &ey);

    if (find_path(sx, sy, ex, ey)) {
        printf("Path found!\n");
    } else {
        printf("No path found!\n");
    }

    return 0;
}