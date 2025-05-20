//MISTRAL-7B DATASET v1.0 Category: Maze Route Finder ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define WIDTH 31
#define HEIGHT 21

typedef struct { int x, y; } point;

char maze[HEIGHT][WIDTH];
bool visited[HEIGHT][WIDTH];
point stack[HEIGHT * WIDTH];
int top = 0;
point start = { 0, 0 }, end = { 0, 0 };

void print_maze() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++)
            putchar(maze[i][j] == '#' ? '#' : ' ');
        putchar('\n');
    }
}

void dfs(point p) {
    visited[p.y][p.x] = true;
    stack[top++] = p;

    if (p.x == end.x && p.y == end.y) {
        while (top) {
            point q = stack[--top];
            printf(" (%d,%d)\n", q.x, q.y);
        }
        exit(EXIT_SUCCESS);
    }

    int dx[4] = { 0, 1, 1, 0 };
    int dy[4] = { 1, 1, 0, -1 };

    int i;
    for (i = 0; i < 4; i++) {
        int nx = p.x + dx[i], ny = p.y + dy[i];

        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT &&
            !visited[ny][nx] && maze[ny][nx] != '#')
            dfs((point){ nx, ny });
    }
}

int main() {
    int i, j;

    memset(maze, '#', sizeof(maze));

    // Input maze
    scanf("%s", maze[0]);
    for (i = 1; i < HEIGHT; i++) {
        fgets(maze[i], WIDTH, stdin);
        maze[i][WIDTH - 1] = '\0';
    }

    // Find start and end cells
    for (i = 0; i < HEIGHT; i++)
        for (j = 0; j < WIDTH; j++)
            if (maze[i][j] == 'S') {
                start.x = j;
                start.y = i;
                maze[i][j] = ' ';
            }
            else if (maze[i][j] == 'E') {
                end.x = j;
                end.y = i;
            }

    if (!start.x || !end.x) {
        fprintf(stderr, "Invalid maze\n");
        exit(EXIT_FAILURE);
    }

    // Run DFS algorithm
    dfs(start);

    // Print maze and solution
    print_maze();

    return EXIT_SUCCESS;
}