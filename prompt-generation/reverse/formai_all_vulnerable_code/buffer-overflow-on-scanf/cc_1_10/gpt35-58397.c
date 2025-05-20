//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Game board dimensions
#define ROWS 22
#define COLS 19

// Maze layout
char maze[ROWS][COLS] = {
    "+-----------------+",
    "|-----|-------|---|",
    "|-|-|-| |-|-| | |-|",
    "| |-|-| |-|-| | |-|",
    "|-|---| | | | | |-|",
    "| | |-| | | |-| | |",
    "| | |-| | | |-| | |",
    "|-|---| | | | | |-|",
    "|-|-|-| | |-| |-|-|",
    "|-|-|-| | |-| |-|-|",
    "| | | | | |   | | |",
    "|-|-|-| | |-| |-|-|",
    "|-|-|-| | |-| |-|-|",
    "|-|---| | | | | |-|",
    "| | |-| | | |-| | |",
    "| | |-| | | |-| | |",
    "|-|---| | | | | |-|",
    "|-|-|-| |-|-| | |-|",
    "|-|-|-| |-|-| | |-|",
    "+-----------------+"
};

// Pac-man starts here
int pacman_row = 11;
int pacman_col = 9;

// Ghosts
int ghost1_row = 9;
int ghost1_col = 9;
int ghost2_row = 9;
int ghost2_col = 10;
int ghost3_row = 9;
int ghost3_col = 11;
int ghost4_row = 9;
int ghost4_col = 12;

// Scoring
int score = 0;

// Game modes
enum GameMode { PLAYING, GAME_OVER };
enum GameMode game_mode = PLAYING;

// Consume a pellet and increase the score
void eat_pellet(int row, int col) {
    maze[row][col] = ' ';
    score += 10;
}

// Move pac-man
void move_pacman(int row, int col) {
    if (maze[row][col] == '.') {
        eat_pellet(row, col);
    }
    pacman_row = row;
    pacman_col = col;
}

// Move a ghost
void move_ghost(int* row_ptr, int* col_ptr) {
    int row = *row_ptr;
    int col = *col_ptr;
    int options[4] = { 0 };
    int direction_count = 0;
    if (maze[row - 1][col] != '-') {
        options[direction_count] = 1; // Up
        direction_count++;
    }
    if (maze[row][col - 1] != '|') {
        options[direction_count] = 2; // Left
        direction_count++;
    }
    if (maze[row + 1][col] != '-') {
        options[direction_count] = 3; // Down
        direction_count++;
    }
    if (maze[row][col + 1] != '|') {
        options[direction_count] = 4; // Right
        direction_count++;
    }
    int direction = options[rand() % direction_count];
    switch (direction) {
        case 1:
            row--;
            break;
        case 2:
            col--;
            break;
        case 3:
            row++;
            break;
        case 4:
            col++;
            break;
    }
    *row_ptr = row;
    *col_ptr = col;
}

// Check for collisions between pac-man and a ghost
bool check_collision(int pacman_row, int pacman_col, int ghost_row, int ghost_col) {
    return (pacman_row == ghost_row && pacman_col == ghost_col);
}

// Display the game board
void display_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == pacman_row && j == pacman_col) {
                printf("%c", 'C'); // Pac-man
            } else if (i == ghost1_row && j == ghost1_col) {
                printf("%c", 'G'); // Ghost 1
            } else if (i == ghost2_row && j == ghost2_col) {
                printf("%c", 'G'); // Ghost 2
            } else if (i == ghost3_row && j == ghost3_col) {
                printf("%c", 'G'); // Ghost 3
            } else if (i == ghost4_row && j == ghost4_col) {
                printf("%c", 'G'); // Ghost 4
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    while (game_mode == PLAYING) {
        // Move pac-man
        char input;
        printf("Enter direction (up/down/left/right): ");
        scanf(" %c", &input);
        int target_row = pacman_row;
        int target_col = pacman_col;
        switch (input) {
            case 'up':
                target_row--;
                break;
            case 'down':
                target_row++;
                break;
            case 'left':
                target_col--;
                break;
            case 'right':
                target_col++;
                break;
        }
        if (maze[target_row][target_col] != '|' && maze[target_row][target_col] != '-') {
            move_pacman(target_row, target_col);
        }

        // Move ghosts
        move_ghost(&ghost1_row, &ghost1_col);
        move_ghost(&ghost2_row, &ghost2_col);
        move_ghost(&ghost3_row, &ghost3_col);
        move_ghost(&ghost4_row, &ghost4_col);

        // Check for collisions
        if (check_collision(pacman_row, pacman_col, ghost1_row, ghost1_col) ||
            check_collision(pacman_row, pacman_col, ghost2_row, ghost2_col) ||
            check_collision(pacman_row, pacman_col, ghost3_row, ghost3_col) ||
            check_collision(pacman_row, pacman_col, ghost4_row, ghost4_col)) {
            game_mode = GAME_OVER;
        }

        // Check for victory
        bool has_pellets = false;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (maze[i][j] == '.') {
                    has_pellets = true;
                    break;
                }
            }
            if (has_pellets) {
                break;
            }
        }
        if (!has_pellets) {
            printf("Congratulations! You have won the game!\n");
            game_mode = GAME_OVER;
        }

        // Display the game board
        printf("\n");
        display_board();
    }

    // Game over
    printf("\nGame over. Final score: %d\n", score);
    return 0;
}