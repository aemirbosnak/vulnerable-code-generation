//MISTRAL-7B DATASET v1.0 Category: Maze Route Finder ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 51
#define HEIGHT 51
#define MAZE_SIZE (WIDTH * HEIGHT)

typedef struct {
    int x, y;
} point;

char maze[HEIGHT][WIDTH];
point start, end;
int dist[MAZE_SIZE];
bool visited[MAZE_SIZE];

void print_maze() {
    int i, j;

    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            putchar(maze[i][j]);
        }
        putchar('\n');
    }
}

bool is_valid_move(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT &&
            maze[y][x] != '#');
}

void bfs() {
    int i, j, u, v, qsize = 0;
    point q[MAZE_SIZE / 2];

    memset(dist, -1, sizeof(dist));
    memset(visited, false, sizeof(visited));

    dist[start.x + start.y * WIDTH] = 0;
    q[qsize++] = start;

    while (qsize) {
        u = q[--qsize].x + u * WIDTH;

        for (i = -2; i <= 2; ++i) {
            for (j = -2; j <= 2; ++j) {
                v = u + i + j * WIDTH;

                if (is_valid_move(v % WIDTH, v / WIDTH) &&
                    !visited[v] && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q[qsize++] = (point){v % WIDTH, v / WIDTH};
                }
            }
        }
    }
}

int main() {
    int i, j, c;

    memset(maze, '.', sizeof(maze));

    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            if (scanf("%c", &c) != EOF) {
                maze[i][j] = c;
                if (c == 'S') {
                    start = (point){j, i};
                } else if (c == 'E') {
                    end = (point){j, i};
                }
            }
        }
        getchar();
    }

    bfs();

    if (dist[end.x + end.y * WIDTH] != -1) {
        printf("Shortest path length: %d\n", dist[end.x + end.y * WIDTH]);
    } else {
        printf("No path found\n");
    }

    print_maze();

    return 0;
}