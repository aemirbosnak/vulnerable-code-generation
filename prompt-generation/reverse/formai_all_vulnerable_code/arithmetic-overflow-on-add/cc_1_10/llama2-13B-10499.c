//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Structure to represent the maze
typedef struct {
    char walls[MAX_ROWS][MAX_COLS];
    int start_x, start_y;
    int exit_x, exit_y;
} maze_t;

// Function to generate a random maze
void generate_maze(maze_t *maze) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            // 25% chance of wall
            if (rand() % 4 == 0) {
                maze->walls[i][j] = '#';
            } else {
                maze->walls[i][j] = ' ';
            }
        }
    }
    // Set starting position
    maze->start_x = rand() % MAX_COLS;
    maze->start_y = rand() % MAX_ROWS;
    // Set exit position
    maze->exit_x = rand() % MAX_COLS;
    maze->exit_y = rand() % MAX_ROWS;
}

// Function to print the maze
void print_maze(maze_t *maze) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%c", maze->walls[i][j]);
        }
        printf("\n");
    }
    printf("Start: (%d, %d)\n", maze->start_x, maze->start_y);
    printf("Exit: (%d, %d)\n", maze->exit_x, maze->exit_y);
}

// Function to move the player
void move_player(maze_t *maze, int dir) {
    int new_x, new_y;
    switch (dir) {
        case 'U':
            new_y -= 1;
            break;
        case 'D':
            new_y += 1;
            break;
        case 'L':
            new_x -= 1;
            break;
        case 'R':
            new_x += 1;
            break;
    }
    // Check for boundary checks
    if (new_x < 0 || new_x >= MAX_COLS || new_y < 0 || new_y >= MAX_ROWS) {
        printf("You have reached a wall.\n");
        return;
    }
    // Update player position
    maze->start_x = new_x;
    maze->start_y = new_y;
}

int main() {
    maze_t maze;
    generate_maze(&maze);
    print_maze(&maze);
    int dir = 'U';
    while (1) {
        move_player(&maze, dir);
        printf("You are at (%d, %d).\n", maze.start_x, maze.start_y);
        printf("Enter a direction (U, D, L, R): ");
        scanf("%c", &dir);
        if (dir == 'q') {
            break;
        }
    }
    return 0;
}