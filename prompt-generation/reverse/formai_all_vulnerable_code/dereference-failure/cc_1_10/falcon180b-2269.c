//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 20
#define WALL '#'
#define FLOOR '.'
#define PLAYER '@'

void generate_maze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
    maze[0][0] = FLOOR;
    int count = 1;
    int x = 0, y = 0;
    while (count < ROWS * COLS - 1) {
        int dir = rand() % 4;
        switch (dir) {
            case 0:
                if (y > 0 && maze[x][y - 1] == WALL) {
                    maze[x][y - 1] = FLOOR;
                    y--;
                }
                break;
            case 1:
                if (x < COLS - 1 && maze[x + 1][y] == WALL) {
                    maze[x + 1][y] = FLOOR;
                    x++;
                }
                break;
            case 2:
                if (y < ROWS - 1 && maze[x][y + 1] == WALL) {
                    maze[x][y + 1] = FLOOR;
                    y++;
                }
                break;
            case 3:
                if (x > 0 && maze[x - 1][y] == WALL) {
                    maze[x - 1][y] = FLOOR;
                    x--;
                }
                break;
        }
        count++;
    }
}

void print_maze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char maze[ROWS][COLS];
    generate_maze(maze);
    print_maze(maze);
    return 0;
}