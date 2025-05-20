//Falcon-180B DATASET v1.0 Category: Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void init_maze(char maze[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

void print_maze(const char maze[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
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

    int player_row = 0;
    int player_col = 0;

    while (1) {
        system("clear");
        print_maze(maze);

        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);

        int new_row = player_row;
        int new_col = player_col;

        switch (move) {
            case 'w':
                if (player_row > 0 && maze[player_row - 1][player_col]!= '#') {
                    new_row--;
                }
                break;
            case 'a':
                if (player_col > 0 && maze[player_row][player_col - 1]!= '#') {
                    new_col--;
                }
                break;
            case's':
                if (player_row < MAX_ROWS - 1 && maze[player_row + 1][player_col]!= '#') {
                    new_row++;
                }
                break;
            case 'd':
                if (player_col < MAX_COLS - 1 && maze[player_row][player_col + 1]!= '#') {
                    new_col++;
                }
                break;
            default:
                break;
        }

        if (new_row!= player_row || new_col!= player_col) {
            if (maze[new_row][new_col] == '.') {
                player_row = new_row;
                player_col = new_col;
            }
        }
    }

    return 0;
}