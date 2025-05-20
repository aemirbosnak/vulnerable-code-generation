//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11

typedef struct { int x, y; } point;

char maze[WIDTH][HEIGHT];
int visited[WIDTH][HEIGHT];

void init_maze() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            maze[i][j] = '#';
            visited[i][j] = 0;
        }
    }
    maze[0][0] = 'S';
    maze[WIDTH - 1][HEIGHT - 1] = 'E';
}

void print_maze() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++)
            printf("%c ", maze[i][j]);
        printf("\n");
    }
}

point random_neighbour(point p) {
    int x = p.x, y = p.y;
    point neighbours[4];

    neighbours[0] = (x > 0) ? (point){x - 1, y} : (point){WIDTH - 1, y};
    neighbours[1] = (y > 0) ? (point){x, y - 1} : (point){x, HEIGHT - 1};
    neighbours[2] = (x < WIDTH - 1) ? (point){x + 1, y} : (point){0, y};
    neighbours[3] = (y < HEIGHT - 1) ? (point){x, y + 1} : (point){x, 0};

    for (int i = 0; i < 4; i++) {
        if (maze[neighbours[i].x][neighbours[i].y] == '#' && !visited[neighbours[i].x][neighbours[i].y])
            return neighbours[i];
    }

    return (point){-1, -1};
}

void recursive_backtracking(point start) {
    point current = start;
    int x, y;

    while (current.x != -1 && current.y != -1) {
        visited[current.x][current.y] = 1;
        maze[current.x][current.y] = ' ';

        x = current.x;
        y = current.y;

        current = random_neighbour(current);

        if (current.x == -1 && current.y == -1) {
            if (maze[start.x][start.y] == 'S')
                maze[start.x][start.y] = ' ';
            return;
        }

        maze[current.x][current.x] = ' ';
        current = (point){current.x, current.y};
    }
}

int main() {
    srand(time(NULL));
    point start;

    init_maze();
    start.x = 1;
    start.y = 1;

    recursive_backtracking(start);

    printf("Enter the cryptic labyrinth:\n");
    print_maze();

    return 0;
}