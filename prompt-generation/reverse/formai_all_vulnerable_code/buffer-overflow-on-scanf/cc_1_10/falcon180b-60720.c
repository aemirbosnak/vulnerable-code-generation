//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MIN 1
#define MAX 100
#define WALL '#'
#define PATH '.'
#define PLAYER '@'
#define GOAL '*'
#define ENEMY 'E'
#define DEAD 'X'

enum Direction { UP, DOWN, LEFT, RIGHT };

void init_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
    maze[0][0] = PATH;
    maze[ROWS - 1][COLS - 1] = GOAL;
}

void print_maze(const char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void move_player(char maze[ROWS][COLS], int *x, int *y, enum Direction dir) {
    int nx = *x;
    int ny = *y;

    switch (dir) {
        case UP:
            --nx;
            break;
        case DOWN:
            ++nx;
            break;
        case LEFT:
            --ny;
            break;
        case RIGHT:
            ++ny;
            break;
    }

    if (maze[nx][ny] == PATH) {
        *x = nx;
        *y = ny;
    }
}

void generate_enemy(char maze[ROWS][COLS]) {
    int x, y;
    do {
        x = rand() % ROWS;
        y = rand() % COLS;
    } while (maze[x][y]!= PATH);

    maze[x][y] = ENEMY;
}

int main() {
    srand(time(NULL));

    char maze[ROWS][COLS];
    init_maze(maze);
    print_maze(maze);

    int player_x = 0;
    int player_y = 0;

    while (1) {
        system("clear");
        print_maze(maze);

        char ch;
        scanf("%c", &ch);

        switch (ch) {
            case 'w':
            case 'W':
                move_player(maze, &player_x, &player_y, UP);
                break;
            case's':
            case 'S':
                move_player(maze, &player_x, &player_y, DOWN);
                break;
            case 'a':
            case 'A':
                move_player(maze, &player_x, &player_y, LEFT);
                break;
            case 'd':
            case 'D':
                move_player(maze, &player_x, &player_y, RIGHT);
                break;
            default:
                continue;
        }

        if (maze[player_x][player_y] == GOAL) {
            printf("You win!\n");
            return 0;
        } else if (maze[player_x][player_y] == ENEMY) {
            printf("You lose!\n");
            return 1;
        }
    }

    return 0;
}