//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char maze[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }

    int player_row = 0;
    int player_col = 0;

    while (1) {
        system("clear");
        print_maze(maze);

        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &move);

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
                if (player_row < ROWS - 1 && maze[player_row + 1][player_col]!= '#') {
                    new_row++;
                }
                break;
            case 'd':
                if (player_col < COLS - 1 && maze[player_row][player_col + 1]!= '#') {
                    new_col++;
                }
                break;
            default:
                printf("Invalid move.\n");
                continue;
        }

        if (new_row!= player_row || new_col!= player_col) {
            if (maze[new_row][new_col] == '#') {
                printf("You hit a wall!\n");
            } else {
                player_row = new_row;
                player_col = new_col;
            }
        }
    }

    return 0;
}