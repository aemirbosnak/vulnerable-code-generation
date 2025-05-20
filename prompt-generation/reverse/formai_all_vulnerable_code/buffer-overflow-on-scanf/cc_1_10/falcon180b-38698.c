//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define MAX_PATH 500

typedef struct {
    int x;
    int y;
} Point;

Point maze[MAX_SIZE][MAX_SIZE];
int startX, startY, endX, endY;
int path[MAX_PATH];
int pathIndex = 0;

void generateMaze() {
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            maze[i][j].x = rand() % MAX_SIZE;
            maze[i][j].y = rand() % MAX_SIZE;
        }
    }
}

void printMaze() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", maze[i][j].x);
        }
        printf("\n");
    }
}

void findPath() {
    int x = startX;
    int y = startY;
    path[pathIndex++] = x * MAX_SIZE + y;
    while (x!= endX || y!= endY) {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        if (dx == 0 && dy == 0) {
            continue;
        }
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < MAX_SIZE && ny >= 0 && ny < MAX_SIZE && maze[nx][ny].x!= -1) {
            x = nx;
            y = ny;
            path[pathIndex++] = x * MAX_SIZE + y;
        }
    }
}

int main() {
    printf("Enter start coordinates (x y):\n");
    scanf("%d %d", &startX, &startY);
    printf("Enter end coordinates (x y):\n");
    scanf("%d %d", &endX, &endY);
    generateMaze();
    findPath();
    printf("Path: ");
    for (int i = 0; i < pathIndex; i++) {
        int x = path[i] / MAX_SIZE;
        int y = path[i] % MAX_SIZE;
        printf("%d %d ", x, y);
    }
    printf("\n");
    return 0;
}