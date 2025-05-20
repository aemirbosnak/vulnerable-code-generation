//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define SPEED 1
#define DELAY 100

int grid[ROWS][COLS] = {0};
int cars[ROWS][COLS] = {0};
int directions[ROWS][COLS] = {0};
int x, y;
int dx, dy;

void init() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
            cars[i][j] = 0;
            directions[i][j] = 0;
        }
    }
    x = rand() % ROWS;
    y = rand() % COLS;
    dx = rand() % 2 - 1;
    dy = rand() % 2 - 1;
    grid[x][y] = 1;
    cars[x][y] = 1;
}

void draw() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void move() {
    int nx, ny;
    if (dx == 1) {
        nx = x + 1;
        ny = y;
    } else {
        nx = x - 1;
        ny = y;
    }
    if (ny >= 0 && ny < COLS && grid[nx][ny] == 0) {
        x = nx;
        y = ny;
        grid[x][y] = 1;
        grid[nx][ny] = 0;
    }
}

int main() {
    init();
    while (1) {
        draw();
        move();
        usleep(DELAY * SPEED);
    }
    return 0;
}