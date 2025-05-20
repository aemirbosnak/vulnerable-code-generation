//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define MAX_TRAPS 3
#define MAX_ATTEMPTS 10

char grid[GRID_SIZE][GRID_SIZE];
int treasure_row, treasure_col;
int traps[MAX_TRAPS][2];

void initialize_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
    treasure_row = rand() % GRID_SIZE;
    treasure_col = rand() % GRID_SIZE;

    for (int i = 0; i < MAX_TRAPS; i++) {
        int trap_row, trap_col;
        do {
            trap_row = rand() % GRID_SIZE;
            trap_col = rand() % GRID_SIZE;
        } while ((trap_row == treasure_row && trap_col == treasure_col) || 
                 (trap_row == traps[i][0] && trap_col == traps[i][1]));
        traps[i][0] = trap_row;
        traps[i][1] = trap_col;
    }
}

void display_grid() {
    printf("Current Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int make_move(int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        printf("Invalid Move! Out of Bounds.\n");
        return 0;
    }
    if (grid[row][col] != '.') {
        printf("You've already checked this position!\n");
        return 0;
    }

    grid[row][col] = 'X'; // Mark as attempted

    if (row == treasure_row && col == treasure_col) {
        return 1; // Treasure found
    }

    // Check for traps
    for (int i = 0; i < MAX_TRAPS; i++) {
        if (row == traps[i][0] && col == traps[i][1]) {
            printf("Oh no! You fell into a trap!\n");
            grid[row][col] = 'T'; // Mark trap
            return -1; // Trap encountered
        }
    }
    return 0; // Empty space
}

int main() {
    srand(time(NULL));
    int attempts = 0;
    int found_treasure = 0;

    initialize_grid();

    printf("Welcome to Treasure Hunt!\n");
    printf("You have %d attempts to find the treasure. Good luck!\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS && found_treasure == 0) {
        display_grid();
        int row, col;
        
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        found_treasure = make_move(row, col);
        
        attempts++;

        if (found_treasure == 1) {
            printf("Congratulations! You've found the treasure!\n");
            break;
        } else if (found_treasure == -1) {
            printf("You have %d attempts left.\n", MAX_ATTEMPTS - attempts);
        } else {
            printf("No treasure, try again!\n");
        }
    }

    if (found_treasure == 0) {
        printf("You've used all your attempts! Game Over.\n");
        printf("The treasure was located at (%d, %d).\n", treasure_row, treasure_col);
    }

    return 0;
}