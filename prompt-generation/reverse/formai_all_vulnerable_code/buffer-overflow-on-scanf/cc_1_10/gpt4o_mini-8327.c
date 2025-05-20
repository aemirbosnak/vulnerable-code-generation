//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define TREASURE 'T'
#define TRAP 'X'
#define EMPTY ' '
#define PLAYER 'P'

void initialize_grid(char grid[SIZE][SIZE], int *treasure_x, int *treasure_y, int *trap_x, int *trap_y) {
    // Initialize the grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }

    // Place treasure at a random position
    *treasure_x = rand() % SIZE;
    *treasure_y = rand() % SIZE;
    grid[*treasure_x][*treasure_y] = TREASURE;

    // Place a trap at a random position that is not the same as the treasure
    do {
        *trap_x = rand() % SIZE;
        *trap_y = rand() % SIZE;
    } while (*trap_x == *treasure_x && *trap_y == *treasure_y);
    grid[*trap_x][*trap_y] = TRAP;
}

void display_grid(char grid[SIZE][SIZE], int player_x, int player_y) {
    printf("Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == player_x && j == player_y) {
                printf("%c ", PLAYER); // Player position
            } else {
                printf("%c ", grid[i][j]); // Other items
            }
        }
        printf("\n");
    }
}

int main() {
    char grid[SIZE][SIZE];
    int treasure_x, treasure_y, trap_x, trap_y;
    int player_x = 0, player_y = 0;
    char move;

    srand(time(NULL)); // Seed the random number generator
    initialize_grid(grid, &treasure_x, &treasure_y, &trap_x, &trap_y);

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Objective: Find the treasure (T) while avoiding traps (X).\n");

    while (1) {
        display_grid(grid, player_x, player_y);
        printf("Move (w: up, s: down, a: left, d: right, q: quit): ");
        scanf(" %c", &move);

        // Update player position based on input
        if (move == 'w' && player_x > 0) {
            player_x--;
        } else if (move == 's' && player_x < SIZE - 1) {
            player_x++;
        } else if (move == 'a' && player_y > 0) {
            player_y--;
        } else if (move == 'd' && player_y < SIZE - 1) {
            player_y++;
        } else if (move == 'q') {
            printf("Exiting the game. Goodbye!\n");
            break;
        } else {
            printf("Invalid move!\n");
            continue; // Skip the rest of the loop
        }

        // Check for treasure or traps
        if (player_x == treasure_x && player_y == treasure_y) {
            printf("Congratulations! You've found the treasure!\n");
            break;
        } else if (player_x == trap_x && player_y == trap_y) {
            printf("Oh no! You fell into a trap! Game Over.\n");
            break;
        }
    }

    return 0;
}