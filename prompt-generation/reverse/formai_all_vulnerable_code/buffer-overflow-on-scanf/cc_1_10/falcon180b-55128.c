//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS];

void init_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
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
    if (x + dx < 0 || x + dx >= COLS || y + dy < 0 || y + dy >= ROWS) {
        return 0;
    }
    if (maze[y + dy][x + dx] == '#') {
        return 0;
    }
    return 1;
}

void move_player(int *x, int *y, int dx, int dy) {
    if (is_valid_move(*x, *y, dx, dy)) {
        *x += dx;
        *y += dy;
        maze[*y][*x] = '.';
    }
}

int main() {
    srand(time(NULL));
    init_maze();
    int player_x = 0, player_y = 0;
    while (1) {
        system("clear");
        print_maze();
        if (player_x == COLS - 1 && player_y == ROWS - 1) {
            printf("You won!\n");
            break;
        }
        char key;
        scanf("%c", &key);
        switch (key) {
            case 'w':
                move_player(&player_x, &player_y, 0, -1);
                break;
            case 'a':
                move_player(&player_x, &player_y, -1, 0);
                break;
            case's':
                move_player(&player_x, &player_y, 0, 1);
                break;
            case 'd':
                move_player(&player_x, &player_y, 1, 0);
                break;
            default:
                break;
        }
    }
    return 0;
}