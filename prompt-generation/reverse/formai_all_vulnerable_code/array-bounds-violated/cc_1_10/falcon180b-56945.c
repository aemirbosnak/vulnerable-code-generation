//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char maze[ROWS][COLS];

    // Initialize maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }

    // Carve out a path
    int start_x = rand() % ROWS;
    int start_y = rand() % COLS;
    maze[start_x][start_y] = 'S';

    int end_x = rand() % ROWS;
    int end_y = rand() % COLS;
    maze[end_x][end_y] = 'E';

    int path_x = start_x;
    int path_y = start_y;

    // Carve out the path
    while (path_x!= end_x || path_y!= end_y) {
        int dx = (path_x < end_x)? 1 : -1;
        int dy = (path_y < end_y)? 1 : -1;

        maze[path_x][path_y] = '.';

        path_x += dx;
        path_y += dy;
    }

    print_maze(maze);

    return 0;
}