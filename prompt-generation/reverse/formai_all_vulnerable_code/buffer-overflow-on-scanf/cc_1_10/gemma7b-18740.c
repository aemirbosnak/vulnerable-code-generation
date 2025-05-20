//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void find_maze_route(int **maze, int n, int m, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == 0) {
        return;
    }
    if (x == n - 1 && y == m - 1) {
        printf("Path found!\n");
        return;
    }

    maze[x][y] = 2;
    find_maze_route(maze, n, m, x - 1, y);
    find_maze_route(maze, n, m, x, y - 1);
    find_maze_route(maze, n, m, x + 1, y);
    find_maze_route(maze, n, m, x, y + 1);
    maze[x][y] = 0;
}

int main() {
    int n, m, x, y;
    int **maze;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        maze[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the maze map (1 for visited, 0 for unvisited):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    printf("Enter the starting position (x, y): ");
    scanf("%d", &x);
    scanf("%d", &y);

    find_maze_route(maze, n, m, x, y);

    return 0;
}