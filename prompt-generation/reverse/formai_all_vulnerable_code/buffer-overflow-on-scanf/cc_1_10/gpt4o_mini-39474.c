//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define MAX_TREASURES 3
#define MAX_MOVES 10

char grid[GRID_SIZE][GRID_SIZE];
int treasures[MAX_TREASURES][2]; // x, y coordinates of treasures
int player_x = 0; // Starting position of player
int player_y = 0; // Starting position of player
int moves = 0;
int collected_treasures = 0;

void initialize_grid() {
    // Initialize empty grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // Place treasures randomly in grid
    for (int i = 0; i < MAX_TREASURES; i++) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] == 'T'); // Ensure treasure is placed in an empty cell
        grid[x][y] = 'T';
        treasures[i][0] = x;
        treasures[i][1] = y;
    }
    
    // Place player at starting point
    grid[player_x][player_y] = 'P';
}

void display_grid() {
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("Moves remaining: %d\n", MAX_MOVES - moves);
    printf("Treasures collected: %d/%d\n", collected_treasures, MAX_TREASURES);
}

void move_player(char direction) {
    // Calculate new position based on input
    int new_x = player_x;
    int new_y = player_y;
    
    switch (direction) {
        case 'w': new_x--; break; // Up
        case 's': new_x++; break; // Down
        case 'a': new_y--; break; // Left
        case 'd': new_y++; break; // Right
        default: printf("Invalid move! Use w, a, s, d to move.\n"); return;
    }

    // Check boundaries
    if (new_x < 0 || new_x >= GRID_SIZE || new_y < 0 || new_y >= GRID_SIZE) {
        printf("You hit the wall!\n");
        return;
    }

    // Check for treasures
    if (grid[new_x][new_y] == 'T') {
        collected_treasures++;
        printf("You've found a treasure!\n");
    }

    // Move player in the grid
    grid[player_x][player_y] = '.'; // Leave previous position
    player_x = new_x;
    player_y = new_y;
    grid[player_x][player_y] = 'P'; // New position

    moves++;
}

int main() {
    srand(time(NULL)); // Seed random number generator
    initialize_grid();
    
    while (moves < MAX_MOVES && collected_treasures < MAX_TREASURES) {
        display_grid();
        
        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);
        
        move_player(move);
    }

    printf("Game Over!\n");
    if (collected_treasures == MAX_TREASURES) {
        printf("Congratulations! You've collected all treasures!\n");
    } else {
        printf("You didn't find all treasures. Better luck next time!\n");
    }
    
    return 0;
}