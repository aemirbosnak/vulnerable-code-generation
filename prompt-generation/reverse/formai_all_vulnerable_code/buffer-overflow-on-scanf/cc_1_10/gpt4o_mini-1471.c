//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5       // Size of the game grid
#define TREASURES 3  // Number of treasures in the game
#define TRAPS 2      // Number of traps in the game

// Structure representing the game state
typedef struct {
    char grid[SIZE][SIZE];
    int treasuresFound;
    int trapsHit;
} GameState;

void initializeGame(GameState *state);
void printGrid(GameState *state);
void placeElements(GameState *state, char element, int count);
int isGameOver(GameState *state);
void playTurn(GameState *state, int x, int y);
void displayOutcome(GameState *state);

int main() {
    GameState gameState;
    int x, y;

    initializeGame(&gameState);

    printf("Welcome to the Treasure Hunt Game!\n");
    while (!isGameOver(&gameState)) {
        printGrid(&gameState);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &x, &y);

        playTurn(&gameState, x, y);
    }

    displayOutcome(&gameState);
    return 0;
}

void initializeGame(GameState *state) {
    state->treasuresFound = 0;
    state->trapsHit = 0;

    // Initialize grid with empty spaces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            state->grid[i][j] = '.';
        }
    }

    placeElements(state, 'T', TREASURES); // Place treasures
    placeElements(state, 'X', TRAPS);      // Place traps
}

void placeElements(GameState *state, char element, int count) {
    int placed = 0;
    srand(time(NULL));

    while (placed < count) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        // Place element only in empty spaces
        if (state->grid[x][y] == '.') {
            state->grid[x][y] = element;
            placed++;
        }
    }
}

void printGrid(GameState *state) {
    printf("\nCurrent grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", state->grid[i][j]);
        }
        printf("\n");
    }
}

int isGameOver(GameState *state) {
    return state->treasuresFound >= TREASURES || state->trapsHit >= TRAPS;
}

void playTurn(GameState *state, int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        printf("Invalid move! Try again.\n");
        return;
    }

    if (state->grid[x][y] == 'T') {
        printf("Congratulations! You found a treasure!\n");
        state->treasuresFound++;
        state->grid[x][y] = 'F'; // Mark treasure as found
    } else if (state->grid[x][y] == 'X') {
        printf("Oh no! You hit a trap!\n");
        state->trapsHit++;
        state->grid[x][y] = 'H'; // Mark trap as hit
    } else {
        printf("You found nothing. Keep searching!\n");
    }
}

void displayOutcome(GameState *state) {
    printf("\nGame Over!\n");
    printf("Treasures found: %d\n", state->treasuresFound);
    printf("Traps hit: %d\n", state->trapsHit);
    
    if (state->treasuresFound == TREASURES) {
        printf("You are a true treasure hunter! Well done!\n");
    } else {
        printf("Better luck next time, adventurer!\n");
    }
}