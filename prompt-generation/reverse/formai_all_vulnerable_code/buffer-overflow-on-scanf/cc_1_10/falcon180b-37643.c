//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to print the maze
void print_maze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random maze
void generate_maze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }

    // Set start and end points
    maze[0][0] = '.';
    maze[ROWS - 1][COLS - 1] = 'E';
}

// Function to check if a move is valid
int is_valid_move(int x, int y, char maze[ROWS][COLS]) {
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y]!= '#') {
        return 1;
    }
    return 0;
}

// Function to move the player
void move_player(int *x, int *y, char maze[ROWS][COLS]) {
    char key;
    printf("Enter your move (w/a/s/d): ");
    scanf(" %c", &key);

    switch (key) {
        case 'w':
            *y -= 1;
            break;
        case 'a':
            *x -= 1;
            break;
        case's':
            *y += 1;
            break;
        case 'd':
            *x += 1;
            break;
        default:
            printf("Invalid move.\n");
            return;
    }

    if (!is_valid_move(*x, *y, maze)) {
        printf("Invalid move.\n");
        return;
    }

    maze[*y][*x] = '@';
}

// Function to check if the player has reached the end
int check_end(int x, int y, char maze[ROWS][COLS]) {
    if (x == COLS - 1 && y == ROWS - 1) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));

    char maze[ROWS][COLS];
    generate_maze(maze);

    int player_x = 0;
    int player_y = 0;

    while (!check_end(player_x, player_y, maze)) {
        print_maze(maze);

        move_player(&player_x, &player_y, maze);
    }

    printf("Congratulations! You have reached the end.\n");

    return 0;
}