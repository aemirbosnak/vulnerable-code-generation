#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int x, y;
} Point;

int maze[MAX_SIZE][MAX_SIZE];
int size;
Point start, end;

void generateMaze() {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    start.x = 0, start.y = 0;
    end.x = size - 1, end.y = size - 1;
}

int isValid(int x, int y) {
    return (x >= 0 && x < size && y >= 0 && y < size && maze[x][y] == 0);
}

int dfs(Point current, Point parent) {
    if (current.x == end.x && current.y == end.y) return 0;
    maze[current.x][current.y] = 2;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) {
        int newX = current.x + dx[i], newY = current.y + dy[i];
        if (isValid(newX, newY) && !(newX == parent.x && newY == parent.y)) {
            int result = dfs((Point){newX, newY}, current);
            if (result != -1) return result + 1;
        }
    }
    maze[current.x][current.y] = 0;
    return -1;
}

int main() {
    printf("Enter maze size: ");
    scanf("%d", &size);
    if (size > MAX_SIZE) {
        printf("Size too large.\n");
        return 1;
    }
    generateMaze();
    int pathCost = dfs(start, start);
    if (pathCost != -1) {
        printf("Shortest path cost: %d\n", pathCost);
    } else {
        printf("No path found.\n");
    }
    return 0;
}
