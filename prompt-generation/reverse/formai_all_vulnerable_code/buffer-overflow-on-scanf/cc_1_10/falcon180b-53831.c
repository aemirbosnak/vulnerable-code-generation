//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void draw_maze(char maze[ROWS][COLS]);
void generate_maze(char maze[ROWS][COLS]);
int valid_move(int x, int y, char maze[ROWS][COLS]);
void move_player(char maze[ROWS][COLS], int *x, int *y);

int main() {
    srand(time(NULL));
    char maze[ROWS][COLS];
    generate_maze(maze);
    int player_x = 0, player_y = 0;
    draw_maze(maze);

    while (1) {
        system("clear");
        draw_maze(maze);
        printf("Player at (%d,%d)\n", player_x, player_y);
        int key;
        scanf("%d", &key);
        if (key == 'w' && valid_move(player_x, player_y - 1, maze)) {
            move_player(maze, &player_x, &player_y);
        } else if (key =='s' && valid_move(player_x, player_y + 1, maze)) {
            move_player(maze, &player_x, &player_y);
        } else if (key == 'a' && valid_move(player_x - 1, player_y, maze)) {
            move_player(maze, &player_x, &player_y);
        } else if (key == 'd' && valid_move(player_x + 1, player_y, maze)) {
            move_player(maze, &player_x, &player_y);
        }
    }

    return 0;
}

void draw_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

int valid_move(int x, int y, char maze[ROWS][COLS]) {
    return x >= 0 && x < COLS && y >= 0 && y < ROWS && maze[y][x]!= '#';
}

void move_player(char maze[ROWS][COLS], int *x, int *y) {
    (*x)++;
    (*y)++;
    if (!valid_move(*x, *y, maze)) {
        (*x)--;
        (*y)--;
    }
    maze[*y][*x] = '.';
}