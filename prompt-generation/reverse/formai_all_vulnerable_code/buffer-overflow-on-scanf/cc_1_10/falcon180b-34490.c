//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void generate_maze(char maze[MAX_ROWS][MAX_COLS]) {
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
    generate_maze(maze);

    int player_row = 0;
    int player_col = 0;

    while (1) {
        system("clear");
        print_maze(maze);

        if (player_row == MAX_ROWS - 1 && player_col == MAX_COLS - 1) {
            printf("You won!\n");
            break;
        }

        char key;
        scanf("%c", &key);

        switch (key) {
            case 'w':
                if (player_row > 0 && maze[player_row - 1][player_col] == '.') {
                    player_row--;
                }
                break;
            case's':
                if (player_row < MAX_ROWS - 1 && maze[player_row + 1][player_col] == '.') {
                    player_row++;
                }
                break;
            case 'a':
                if (player_col > 0 && maze[player_row][player_col - 1] == '.') {
                    player_col--;
                }
                break;
            case 'd':
                if (player_col < MAX_COLS - 1 && maze[player_row][player_col + 1] == '.') {
                    player_col++;
                }
                break;
            default:
                printf("Invalid key.\n");
        }

        if (maze[player_row][player_col]!= '.') {
            printf("Game over.\n");
            break;
        }
    }

    return 0;
}