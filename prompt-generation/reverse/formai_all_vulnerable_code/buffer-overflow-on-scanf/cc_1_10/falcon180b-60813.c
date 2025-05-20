//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int maze[ROWS][COLS];

void init_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

void print_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int player_x = 0, player_y = 0;
    init_maze();
    print_maze();

    while (!check_win()) {
        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &move);

        int new_x = player_x, new_y = player_y;

        switch (move) {
            case 'w':
                if (player_y > 0 && maze[player_y - 1][player_x] == 1) {
                    new_y--;
                }
                break;
            case 'a':
                if (player_x > 0 && maze[player_y][player_x - 1] == 1) {
                    new_x--;
                }
                break;
            case's':
                if (player_y < ROWS - 1 && maze[player_y + 1][player_x] == 1) {
                    new_y++;
                }
                break;
            case 'd':
                if (player_x < COLS - 1 && maze[player_y][player_x + 1] == 1) {
                    new_x++;
                }
                break;
            default:
                printf("Invalid move.\n");
                continue;
        }

        if (new_x!= player_x || new_y!= player_y) {
            maze[player_y][player_x] = 0;
            maze[new_y][new_x] = 1;
            player_x = new_x;
            player_y = new_y;
        }
    }

    printf("Congratulations! You won!\n");
    return 0;
}