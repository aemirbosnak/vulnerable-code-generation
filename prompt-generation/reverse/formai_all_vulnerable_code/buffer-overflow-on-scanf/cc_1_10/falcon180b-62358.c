//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generate_maze(char maze[ROWS][COLS]);
void print_maze(char maze[ROWS][COLS]);
int check_win(char maze[ROWS][COLS]);
void move_player(char maze[ROWS][COLS], int *row, int *col);

int main() {
    srand(time(NULL));

    char maze[ROWS][COLS];
    generate_maze(maze);

    int player_row = 0;
    int player_col = 0;

    while (!check_win(maze)) {
        system("clear");
        print_maze(maze);

        move_player(maze, &player_row, &player_col);
    }

    printf("Congratulations! You won!\n");

    return 0;
}

void generate_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }

    // Set start and end points
    maze[0][0] = '.';
    maze[ROWS - 1][COLS - 1] = 'E';
}

void print_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int check_win(char maze[ROWS][COLS]) {
    return maze[ROWS - 1][COLS - 1] == '.';
}

void move_player(char maze[ROWS][COLS], int *row, int *col) {
    printf("Enter your move (W/A/S/D): ");
    char move;
    scanf("%c", &move);

    switch (move) {
        case 'W':
            --(*row);
            break;
        case 'A':
            --(*col);
            break;
        case 'S':
            ++(*row);
            break;
        case 'D':
            ++(*col);
            break;
        default:
            printf("Invalid move.\n");
            return;
    }

    if (maze[*row][*col] == '#') {
        printf("You hit a wall.\n");
    } else if (maze[*row][*col] == 'E') {
        printf("You reached the end!\n");
    }
}