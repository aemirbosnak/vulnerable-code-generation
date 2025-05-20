//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 4
#define NUM_PAIRS (GRID_SIZE * GRID_SIZE) / 2

char grid[GRID_SIZE][GRID_SIZE];
char displayGrid[GRID_SIZE][GRID_SIZE];
bool revealed[GRID_SIZE][GRID_SIZE] = {false};
char symbols[NUM_PAIRS] = {'@', '#', '$', '%', '&', '*', '!', '?'};
int moves = 0;

void initializeGrid() {
    srand(time(NULL));
    for (int i = 0; i < NUM_PAIRS; i++) {
        grid[i / (GRID_SIZE / 2)][i % (GRID_SIZE / 2) * 2] = symbols[i];
        grid[i / (GRID_SIZE / 2)][i % (GRID_SIZE / 2) * 2 + 1] = symbols[i];
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int randX = rand() % GRID_SIZE;
            int randY = rand() % GRID_SIZE;
            char temp = grid[i][j];
            grid[i][j] = grid[randX][randY];
            grid[randX][randY] = temp;
        }
    }
}

void displayGridState() {
    printf("Current Grid State:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", grid[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
    printf("Moves: %d\n", moves);
}

bool checkForMatch(int x1, int y1, int x2, int y2) {
    return grid[x1][y1] == grid[x2][y2];
}

void revealCard(int x, int y) {
    revealed[x][y] = true;
}

bool allMatched() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void resetRevealedFlags(int x1, int y1, int x2, int y2) {
    revealed[x1][y1] = false;
    revealed[x2][y2] = false;
}

void playGame() {
    while (!allMatched()) {
        displayGridState();
        int x1, y1, x2, y2;
        printf("Select first card (row col): ");
        scanf("%d %d", &x1, &y1);
        printf("Select second card (row col): ");
        scanf("%d %d", &x2, &y2);

        if (x1 < 0 || x1 >= GRID_SIZE || y1 < 0 || y1 >= GRID_SIZE ||
            x2 < 0 || x2 >= GRID_SIZE || y2 < 0 || y2 >= GRID_SIZE ||
            (x1 == x2 && y1 == y2) || revealed[x1][y1] || revealed[x2][y2]) {
            printf("Invalid selection, try again.\n");
            continue;
        }

        revealCard(x1, y1);
        revealCard(x2, y2);
        moves++;

        displayGridState();

        if (!checkForMatch(x1, y1, x2, y2)) {
            printf("No match! Try again.\n");
            sleep(2); // wait for 2 seconds before hiding again
            resetRevealedFlags(x1, y1, x2, y2);
        } else {
            printf("It's a match!\n");
        }
    }
    printf("Congratulations! You've matched all cards in %d moves.\n", moves);
}

int main() {
    initializeGrid();
    printf("Welcome to the Memory Game!\n");
    printf("Find all matching pairs in the least number of moves.\n");
    playGame();
    return 0;
}