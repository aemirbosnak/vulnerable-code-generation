//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

int maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int visited[MAZE_HEIGHT][MAZE_WIDTH];

typedef struct {
    int x;
    int y;
} point;

point stack[MAZE_WIDTH * MAZE_HEIGHT];
int top = 0;

void push(point p) {
    stack[top++] = p;
}

point pop() {
    return stack[--top];
}

int is_valid(int x, int y) {
    return x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT && maze[y][x] == 0 && visited[y][x] == 0;
}

int find_path(int start_x, int start_y, int end_x, int end_y) {
    point start = {start_x, start_y};
    point end = {end_x, end_y};

    push(start);

    while (top > 0) {
        point current = pop();

        if (current.x == end.x && current.y == end.y) {
            return 1;
        }

        visited[current.y][current.x] = 1;

        if (is_valid(current.x + 1, current.y)) {
            point next = {current.x + 1, current.y};
            push(next);
        }

        if (is_valid(current.x - 1, current.y)) {
            point next = {current.x - 1, current.y};
            push(next);
        }

        if (is_valid(current.x, current.y + 1)) {
            point next = {current.x, current.y + 1};
            push(next);
        }

        if (is_valid(current.x, current.y - 1)) {
            point next = {current.x, current.y - 1};
            push(next);
        }
    }

    return 0;
}

int main() {
    int start_x, start_y, end_x, end_y;

    printf("Enter the starting coordinates (x, y): ");
    scanf("%d %d", &start_x, &start_y);

    printf("Enter the ending coordinates (x, y): ");
    scanf("%d %d", &end_x, &end_y);

    if (find_path(start_x, start_y, end_x, end_y)) {
        printf("Path found!\n");
    } else {
        printf("Path not found.\n");
    }

    return 0;
}