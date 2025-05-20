//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int map[10][10];
int visited[10][10];
int next_x, next_y;

void print_path(int x, int y) {
    printf("(%d,%d) ", x, y);
}

int dfs(int x, int y) {
    visited[x][y] = 1;
    if (x == next_x && y == next_y) {
        print_path(x, y);
        return 1;
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10) {
            continue;
        }
        if (!visited[nx][ny] && map[nx][ny] == 0) {
            if (dfs(nx, ny)) {
                print_path(x, y);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    printf("Welcome to the pathfinding algorithm!\n");
    printf("Please enter the positions of the starting point and the endpoint:\n");
    int start_x, start_y, end_x, end_y;
    scanf("%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
    printf("You entered (%d,%d) and (%d,%d).\n", start_x, start_y, end_x, end_y);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = rand() % 2;
            visited[i][j] = 0;
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    next_x = end_x;
    next_y = end_y;
    printf("Calculating the path...\n");
    if (dfs(start_x, start_y)) {
        printf("\nFound the path!\n");
    } else {
        printf("\nCould not find the path!\n");
    }
    return 0;
}