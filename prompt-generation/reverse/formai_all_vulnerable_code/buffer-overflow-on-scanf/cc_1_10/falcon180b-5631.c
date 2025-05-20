//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define START_X 0
#define START_Y 0
#define END_X COLS-1
#define END_Y ROWS-1
#define WALL '#'
#define PATH '.'
#define DRONE 'D'

char maze[ROWS][COLS];
int start_x, start_y, end_x, end_y;

void generate_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
    start_x = START_X;
    start_y = START_Y;
    end_x = END_X;
    end_y = END_Y;
    maze[start_y][start_x] = PATH;
    maze[end_y][end_x] = PATH;
}

void print_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int x, int y, int dx, int dy) {
    if (dx == 0 && dy == 0)
        return 0;
    int nx = x + dx;
    int ny = y + dy;
    if (nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS && maze[ny][nx] == PATH)
        return 1;
    return 0;
}

void move_drone(int dx, int dy) {
    int nx, ny;
    nx = start_x + dx;
    ny = start_y + dy;
    if (is_valid_move(start_x, start_y, dx, dy)) {
        maze[ny][nx] = DRONE;
        start_x = nx;
        start_y = ny;
    }
}

int main() {
    srand(time(NULL));
    generate_maze();
    int choice;
    while (1) {
        system("clear");
        print_maze();
        printf("\nEnter your move (w/a/s/d): ");
        scanf("%d", &choice);
        move_drone(0, -1);
        move_drone(0, 1);
        move_drone(-1, 0);
        move_drone(1, 0);
    }
    return 0;
}