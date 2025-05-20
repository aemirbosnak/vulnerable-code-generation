//Falcon-180B DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

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
}

// Function to check if the path is valid
int is_valid_path(int x, int y, char maze[ROWS][COLS]) {
    if (x >= 0 && x < COLS && y >= 0 && y < ROWS && maze[y][x] == '.') {
        return 1;
    }
    return 0;
}

// Function to move the player
void move_player(int *x, int *y, char maze[ROWS][COLS], int dir) {
    switch (dir) {
        case 0: // Up
            (*y)--;
            break;
        case 1: // Right
            (*x)++;
            break;
        case 2: // Down
            (*y)++;
            break;
        case 3: // Left
            (*x)--;
            break;
    }
}

// Function to check if the player has reached the end of the maze
int has_won(int x, int y, char maze[ROWS][COLS]) {
    return x == COLS - 1 && y == ROWS - 1;
}

int main() {
    srand(time(NULL));

    char maze[ROWS][COLS];
    generate_maze(maze);

    int player_x = 0, player_y = 0;

    while (!has_won(player_x, player_y, maze)) {
        system("clear");
        print_maze(maze);
        printf("Player position: (%d, %d)\n", player_x, player_y);

        int key;
        scanf("%d", &key);

        move_player(&player_x, &player_y, maze, key);
    }

    printf("Congratulations! You have won the game!\n");

    return 0;
}