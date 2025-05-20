//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_maze(int maze[][5], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == 1)
                printf("X ");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void generate_maze(int maze[][5], int m, int n) {
    int i, j, k, r;
    int start = 0;
    int goal = m - 1;

    srand(time(NULL));

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            maze[i][j] = 0;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                maze[i][j] = 1;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                if (i == 0 && j == 0)
                    start = 1;
                else if (i == m - 1 && j == 0)
                    goal = 1;
                else if (i == m - 1 && j == n - 1)
                    goal = 1;
                else if (i == 0 && j == n - 1)
                    start = 1;
                else
                    continue;
            }
            for (k = 1; k <= n; k++) {
                r = rand() % 4;
                if (r == 0)
                    maze[i + 1][j + k] = 1;
                else if (r == 1)
                    maze[i - 1][j + k] = 1;
                else if (r == 2)
                    maze[i + k][j - 1] = 1;
                else if (r == 3)
                    maze[i - k][j - 1] = 1;
            }
        }
    }

    printf("Maze:\n");
    print_maze(maze, m, n);
    printf("\n");

    if (start == 1 && goal == 1)
        printf("Start and goal found!\n");
    else
        printf("Start and goal not found!\n");
}

int main() {
    int maze[5][5];
    int m, n;
    int i, j;

    m = 5;
    n = 5;
    srand(time(NULL));

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            maze[i][j] = 0;

    generate_maze(maze, m, n);

    return 0;
}