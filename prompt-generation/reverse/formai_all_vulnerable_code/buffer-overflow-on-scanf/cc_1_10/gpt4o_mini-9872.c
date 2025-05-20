//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define TREASURES 3
#define TRAPS 3

char grid[GRID_SIZE][GRID_SIZE];
int player_x = 0, player_y = 0;
int treasures_found = 0;

void initialize_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
    // Place treasures
    for (int i = 0; i < TREASURES; i++) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] != '.');
        grid[x][y] = 'T';
    }
    // Place traps
    for (int i = 0; i < TRAPS; i++) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] != '.');
        grid[x][y] = 'X';
    }
}

void display_grid() {
    printf("\nGrid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == player_x && j == player_y) {
                printf("P ");
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
    printf("Treasures Found: %d/%d\n", treasures_found, TREASURES);
}

int move_player(char direction) {
    int new_x = player_x, new_y = player_y;
    switch (direction) {
        case 'w': new_x--; break; // Up
        case 's': new_x++; break; // Down
        case 'a': new_y--; break; // Left
        case 'd': new_y++; break; // Right
        default: return 0; // Invalid move
    }
    
    // Check boundaries
    if (new_x < 0 || new_x >= GRID_SIZE || new_y < 0 || new_y >= GRID_SIZE) {
        printf("Move out of bounds!\n");
        return 0;
    }

    // Update player position
    player_x = new_x;
    player_y = new_y;

    // Check for treasures or traps
    if (grid[player_x][player_y] == 'T') {
        treasures_found++;
        grid[player_x][player_y] = '.'; // Clear the treasure after finding
        printf("You found a treasure!\n");
    } else if (grid[player_x][player_y] == 'X') {
        printf("You stepped on a trap! Game Over!\n");
        return -1; // Game Over
    }

    return 1; // Successfully moved
}

int main() {
    srand(time(0)); // Seed the random number generator
    initialize_grid();
    
    char move;
    while (1) {
        display_grid();
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);

        int result = move_player(move);

        if (result == -1) {
            display_grid();
            printf("Thanks for playing!\n");
            break;
        }

        if (treasures_found == TREASURES) {
            printf("Congratulations! You found all the treasures!\n");
            display_grid();
            break;
        }
    }
    
    return 0;
}