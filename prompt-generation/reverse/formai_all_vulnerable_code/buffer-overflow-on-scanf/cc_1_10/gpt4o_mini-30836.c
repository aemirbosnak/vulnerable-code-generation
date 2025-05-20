//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define MAX_MOVES 15
#define TREASURES 5
#define TRAPS 5

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char grid[GRID_SIZE][GRID_SIZE];
    int treasures;
    int traps;
    Position player;
    int moves;
} GameState;

void initializeGame(GameState *game) {
    // Initialize game state
    game->treasures = 0;
    game->traps = 0;
    game->moves = 0;

    // Initialize grid with empty spaces
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            game->grid[i][j] = '.';
        }
    }

    // Randomly place treasures
    while (game->treasures < TREASURES) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (game->grid[x][y] == '.') {
            game->grid[x][y] = 'T'; // T for Treasure
            game->treasures++;
        }
    }

    // Randomly place traps
    while (game->traps < TRAPS) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (game->grid[x][y] == '.') {
            game->grid[x][y] = 'X'; // X for Trap
            game->traps++;
        }
    }

    // Set player's initial position
    game->player.x = 0;
    game->player.y = 0;
    game->grid[game->player.x][game->player.y] = 'P'; // P for Player
}

void printGrid(GameState *game) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", game->grid[i][j]);
        }
        printf("\n");
    }
}

void updatePlayerPosition(GameState *game, int x, int y) {
    // Remove the player from the current position
    game->grid[game->player.x][game->player.y] = '.';
    // Update player position
    game->player.x += x;
    game->player.y += y;
    // Check bounds
    if (game->player.x < 0) game->player.x = 0;
    if (game->player.x >= GRID_SIZE) game->player.x = GRID_SIZE - 1;
    if (game->player.y < 0) game->player.y = 0;
    if (game->player.y >= GRID_SIZE) game->player.y = GRID_SIZE - 1;
    // Update grid
    game->grid[game->player.x][game->player.y] = 'P';
}

void checkCurrentPosition(GameState *game) {
    if (game->grid[game->player.x][game->player.y] == 'T') {
        printf("You found a treasure!\n");
        game->grid[game->player.x][game->player.y] = '.'; // Remove treasure
    } else if (game->grid[game->player.x][game->player.y] == 'X') {
        printf("Oh no! You fell into a trap!\n");
        game->moves = MAX_MOVES; // End game on trap
    }
}

int main() {
    srand(time(NULL));
    GameState game;
    initializeGame(&game);

    while (game.moves < MAX_MOVES) {
        printGrid(&game);
        printf("Moves made: %d/%d\n", game.moves, MAX_MOVES);
        printf("Enter your move (W/A/S/D): ");
        
        char move;
        scanf(" %c", &move);
        switch (move) {
            case 'W': updatePlayerPosition(&game, -1, 0); break; // Up
            case 'A': updatePlayerPosition(&game, 0, -1); break; // Left
            case 'S': updatePlayerPosition(&game, 1, 0); break; // Down
            case 'D': updatePlayerPosition(&game, 0, 1); break; // Right
            default: printf("Invalid move! Use W/A/S/D.\n"); continue;
        }

        checkCurrentPosition(&game);
        game.moves++;

        if (game.moves == MAX_MOVES) {
            printf("You've run out of moves! Game over.\n");
            break;
        }
    }

    printf("Final Score: You found %d treasures!\n", TREASURES - game.traps);
    return 0;
}