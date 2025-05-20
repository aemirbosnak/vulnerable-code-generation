//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2 == 0? '.' : '#';
        }
    }
}

void haunted_house(char maze[ROWS][COLS]) {
    int player_row = 0;
    int player_col = 0;
    char player_dir = '>';

    while (1) {
        system("clear");
        printf("Haunted House Simulator\n");
        print_maze(maze);
        printf("\n");
        printf("You are at: %c (%d,%d)\n", player_dir, player_row, player_col);

        char input[3];
        scanf("%s", input);

        switch (input[0]) {
            case 'w':
            case 'W':
                if (player_row > 0 && maze[player_row - 1][player_col] == '.') {
                    player_row--;
                    player_dir = 'v';
                }
                break;
            case's':
            case 'S':
                if (player_row < ROWS - 1 && maze[player_row + 1][player_col] == '.') {
                    player_row++;
                    player_dir = '^';
                }
                break;
            case 'a':
            case 'A':
                if (player_col > 0 && maze[player_row][player_col - 1] == '.') {
                    player_col--;
                    player_dir = '<';
                }
                break;
            case 'd':
            case 'D':
                if (player_col < COLS - 1 && maze[player_row][player_col + 1] == '.') {
                    player_col++;
                    player_dir = '>';
                }
                break;
            default:
                break;
        }
    }
}

int main() {
    srand(time(NULL));

    char maze[ROWS][COLS];
    generate_maze(maze);

    haunted_house(maze);

    return 0;
}