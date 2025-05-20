//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int row;
    int col;
} position_t;

void print_maze(int maze[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c", maze[i][j] ? ' ' : '#');
        }
        printf("\n");
    }
}

void generate_maze(int maze[MAX_ROWS][MAX_COLS], position_t pos) {
    if (pos.row >= MAX_ROWS || pos.col >= MAX_COLS) {
        return;
    }

    maze[pos.row][pos.col] = 1;

    position_t neighbors[4];
    neighbors[0] = (position_t) {pos.row - 1, pos.col};
    neighbors[1] = (position_t) {pos.row, pos.col - 1};
    neighbors[2] = (position_t) {pos.row + 1, pos.col};
    neighbors[3] = (position_t) {pos.row, pos.col + 1};

    for (int i = 0; i < 4; i++) {
        if (!maze[neighbors[i].row][neighbors[i].col]) {
            generate_maze(maze, neighbors[i]);
        }
    }
}

int main() {
    int maze[MAX_ROWS][MAX_COLS] = {{0}};

    srand(time(NULL));

    position_t pos = (position_t) {0, 0};
    generate_maze(maze, pos);

    print_maze(maze);

    return 0;
}