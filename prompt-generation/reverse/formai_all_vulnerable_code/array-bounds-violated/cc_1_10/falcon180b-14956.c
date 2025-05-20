//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS];
int player_row, player_col, score;

void generate_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

void draw_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int move(int dir) {
    int new_row, new_col;
    switch (dir) {
        case 0: // up
            new_row = player_row - 1;
            new_col = player_col;
            break;
        case 1: // right
            new_row = player_row;
            new_col = player_col + 1;
            break;
        case 2: // down
            new_row = player_row + 1;
            new_col = player_col;
            break;
        case 3: // left
            new_row = player_row;
            new_col = player_col - 1;
            break;
        default:
            return -1;
    }
    if (maze[new_row][new_col] == '.') {
        player_row = new_row;
        player_col = new_col;
        return 0;
    }
    return -1;
}

void game_loop() {
    int dir;
    while (1) {
        draw_maze();
        printf("Score: %d\n", score);
        printf("Press a key to move:\n");
        printf("w - up\n");
        printf("s - down\n");
        printf("a - left\n");
        printf("d - right\n");
        scanf(" %c", &dir);
        if (move(dir) == -1) {
            printf("Game over!\n");
            break;
        }
        score++;
    }
}

int main() {
    srand(time(NULL));
    generate_maze();
    player_row = 0;
    player_col = 0;
    score = 0;
    game_loop();
    return 0;
}