//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define NUM_TRAPS 3

typedef struct {
    int x;
    int y;
} Position;

void initialize_grid(char grid[GRID_SIZE][GRID_SIZE], Position *treasure, Position traps[NUM_TRAPS]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    treasure->x = rand() % GRID_SIZE;
    treasure->y = rand() % GRID_SIZE;
    grid[treasure->x][treasure->y] = 'T'; // Treasure marked with 'T'

    for (int i = 0; i < NUM_TRAPS; i++) {
        do {
            traps[i].x = rand() % GRID_SIZE;
            traps[i].y = rand() % GRID_SIZE;
        } while ((traps[i].x == treasure->x && traps[i].y == treasure->y) || 
                 (i > 0 && (traps[i].x == traps[i-1].x && traps[i].y == traps[i-1].y)));

        grid[traps[i].x][traps[i].y] = 'X'; // Trap marked with 'X'
    }
}

void print_grid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("Current Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void update_grid(char grid[GRID_SIZE][GRID_SIZE], Position player) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == player.x && j == player.y) {
                grid[i][j] = 'P'; // Player marked with 'P'
            } else {
                if (grid[i][j] != 'T' && grid[i][j] != 'X') {
                    grid[i][j] = '.';
                }
            }
        }
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    Position treasure, traps[NUM_TRAPS];
    Position player = {0, 0}; // Player starts at the top left corner
    char move;
    int game_over = 0;

    srand(time(NULL)); // Seed for random number generation

    initialize_grid(grid, &treasure, traps);

    while (!game_over) {
        print_grid(grid);
        printf("Make a move (w/a/s/d): ");
        scanf(" %c", &move);

        Position new_position = player;

        switch (move) {
            case 'w': new_position.x--; break; // Move up
            case 'a': new_position.y--; break; // Move left
            case 's': new_position.x++; break; // Move down
            case 'd': new_position.y++; break; // Move right
            default: printf("Invalid move! Use w/a/s/d to move.\n"); continue; // Invalid input
        }

        // Check boundaries
        if (new_position.x < 0 || new_position.x >= GRID_SIZE || new_position.y < 0 || new_position.y >= GRID_SIZE) {
            printf("You can't move outside the grid! Try again.\n");
            continue;
        }

        // Update player position
        player = new_position;
        update_grid(grid, player);

        // Check for treasure or traps
        if (player.x == treasure.x && player.y == treasure.y) {
            printf("Congratulations! You've found the treasure!\n");
            game_over = 1; // End game
        }
        
        for (int i = 0; i < NUM_TRAPS; i++) {
            if (player.x == traps[i].x && player.y == traps[i].y) {
                printf("Oh no! You hit a trap. Game over!\n");
                game_over = 1; // End game
                break;
            }
        }
    }

    return 0;
}