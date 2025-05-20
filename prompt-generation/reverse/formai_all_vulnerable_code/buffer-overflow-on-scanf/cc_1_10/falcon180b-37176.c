//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS];
int player_row, player_col;

void init_maze() {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    player_row = rand() % MAX_ROWS;
    player_col = rand() % MAX_COLS;
    while (maze[player_row][player_col] == 1) {
        player_row = rand() % MAX_ROWS;
        player_col = rand() % MAX_COLS;
    }
    maze[player_row][player_col] = 2;
}

void draw_maze() {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else if (maze[i][j] == 2) {
                printf("@");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void move_player(int dir) {
    int new_row, new_col;
    switch (dir) {
        case 0: // up
            new_row = player_row - 1;
            break;
        case 1: // right
            new_col = player_col + 1;
            break;
        case 2: // down
            new_row = player_row + 1;
            break;
        case 3: // left
            new_col = player_col - 1;
            break;
    }
    if (maze[new_row][new_col] == 0) {
        player_row = new_row;
        player_col = new_col;
    }
}

int main() {
    srand(time(NULL));
    init_maze();
    draw_maze();

    int dir;
    while (1) {
        printf("Enter direction (0-3): ");
        scanf("%d", &dir);
        move_player(dir);
        draw_maze();
        if (maze[player_row][player_col] == 3) {
            printf("Congratulations! You won!\n");
            break;
        }
    }

    return 0;
}