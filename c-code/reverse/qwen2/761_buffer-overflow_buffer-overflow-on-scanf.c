#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define SIZE 10

int isValid(int x, int y, int visited[SIZE][SIZE], int grid[SIZE][SIZE]) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && !visited[x][y] && grid[x][y] != 0);
}

void dfs(int x, int y, int endX, int endY, int visited[SIZE][SIZE], int grid[SIZE][SIZE]) {
    if (!isValid(x, y, visited, grid)) return;
    if (x == endX && y == endY) {
        grid[x][y] = -1;
        return;
    }
    visited[x][y] = 1;
    grid[x][y] = -1;
    dfs(x + 1, y, endX, endY, visited, grid);
    dfs(x - 1, y, endX, endY, visited, grid);
    dfs(x, y + 1, endX, endY, visited, grid);
    dfs(x, y - 1, endX, endY, visited, grid);
    grid[x][y] = 0; // Backtrack
}

int main() {
    int grid[SIZE][SIZE];
    int startX, startY, endX, endY;
    int visited[SIZE][SIZE] = {0};

    printf("Enter the 10x10 grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter start point (row col): ");
    scanf("%d %d", &startX, &startY);

    printf("Enter end point (row col): ");
    scanf("%d %d", &endX, &endY);

    dfs(startX, startY, endX, endY, visited, grid);

    printf("\nModified Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}
