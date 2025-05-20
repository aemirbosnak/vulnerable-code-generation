//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void init_maze(char maze[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

void print_maze(const char maze[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char maze[MAX_ROWS][MAX_COLS];
    init_maze(maze);
    print_maze(maze);

    int player_x = 0, player_y = 0;
    while (1) {
        char input;
        scanf("%c", &input);
        switch (input) {
            case 'w':
                if (player_y > 0 && maze[player_y - 1][player_x] == '.') {
                    player_y--;
                }
                break;
            case's':
                if (player_y < MAX_ROWS - 1 && maze[player_y + 1][player_x] == '.') {
                    player_y++;
                }
                break;
            case 'a':
                if (player_x > 0 && maze[player_y][player_x - 1] == '.') {
                    player_x--;
                }
                break;
            case 'd':
                if (player_x < MAX_COLS - 1 && maze[player_y][player_x + 1] == '.') {
                    player_x++;
                }
                break;
            default:
                continue;
        }
        print_maze(maze);
    }

    return 0;
}