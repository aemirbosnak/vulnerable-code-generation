//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS];
int player_row, player_col;

void generate_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
    maze[0][0] = '.';
    maze[ROWS - 1][COLS - 1] = '.';
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

void move_player(int dir) {
    switch (dir) {
        case 0: // up
            if (player_row > 0 && maze[player_row - 1][player_col] == '.') {
                player_row--;
            }
            break;
        case 1: // right
            if (player_col < COLS - 1 && maze[player_row][player_col + 1] == '.') {
                player_col++;
            }
            break;
        case 2: // down
            if (player_row < ROWS - 1 && maze[player_row + 1][player_col] == '.') {
                player_row++;
            }
            break;
        case 3: // left
            if (player_col > 0 && maze[player_row][player_col - 1] == '.') {
                player_col--;
            }
            break;
    }
}

int main() {
    srand(time(NULL));
    generate_maze();
    player_row = 0;
    player_col = 0;

    while (1) {
        print_maze();
        int choice;
        printf("Enter your move (0: up, 1: right, 2: down, 3: left): ");
        scanf("%d", &choice);
        move_player(choice);

        if (maze[player_row][player_col] == 'E') {
            printf("Congratulations! You won!\n");
            break;
        } else if (maze[player_row][player_col] == 'X') {
            printf("Game over. You hit a wall.\n");
            break;
        }
    }

    return 0;
}