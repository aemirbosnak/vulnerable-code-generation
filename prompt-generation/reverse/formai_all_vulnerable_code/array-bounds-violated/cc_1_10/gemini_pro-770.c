//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAXSIZE 100

typedef struct {
    int x, y;
} point;

int maze[MAXSIZE][MAXSIZE];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int width, height;

void init_maze() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = 1;
        }
    }
}

point *generate_maze() {
    int x = rand() % width;
    int y = rand() % height;
    maze[y][x] = 0;
    point *p = malloc(sizeof(point));
    p->x = x;
    p->y = y;
    return p;
}

void recursive_backtrack(point *p) {
    int i;
    while (1) {
        int count = 0;
        for (i = 0; i < 4; i++) {
            int nx = p->x + dx[i];
            int ny = p->y + dy[i];
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                if (maze[ny][nx] == 1) {
                    count++;
                }
            }
        }
        if (count == 0) {
            return;
        }
        i = rand() % 4;
        while (maze[p->y + dy[i]][p->x + dx[i]] != 1) {
            i = (i + 1) % 4;
        }
        maze[p->y + dy[i]][p->x + dx[i]] = 0;
        p->x += dx[i];
        p->y += dy[i];
        recursive_backtrack(p);
    }
}

void print_maze() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s width height\n", argv[0]);
        return 1;
    }
    srand(time(NULL));
    width = atoi(argv[1]);
    height = atoi(argv[2]);
    init_maze();
    point *p = generate_maze();
    recursive_backtrack(p);
    print_maze();
    return 0;
}