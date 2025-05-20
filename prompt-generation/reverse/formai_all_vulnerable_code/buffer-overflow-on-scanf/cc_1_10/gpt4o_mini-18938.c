//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define TREASURE_COUNT 5

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void placeTreasures(char grid[GRID_SIZE][GRID_SIZE]);
void printGrid(char grid[GRID_SIZE][GRID_SIZE]);
int isLocationValid(int row, int col, char grid[GRID_SIZE][GRID_SIZE]);
void playGame(char grid[GRID_SIZE][GRID_SIZE], int *scores, int playerCount);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int playerCount;

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Enter the number of players (1-4): ");
    scanf("%d", &playerCount);

    if (playerCount < 1 || playerCount > 4) {
        printf("Invalid number of players. Please try again!\n");
        return 1;
    }

    int scores[playerCount];
    for (int i = 0; i < playerCount; i++) {
        scores[i] = 0;
    }

    initializeGrid(grid);
    placeTreasures(grid);
  
    playGame(grid, scores, playerCount);
    
    // Display final scores
    printf("\nFinal Scores:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("Player %d: %d treasures found!\n", i + 1, scores[i]);
    }

    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void placeTreasures(char grid[GRID_SIZE][GRID_SIZE]) {
    srand(time(NULL));
    int placed = 0;
    while (placed < TREASURE_COUNT) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        if (grid[row][col] == '.') {
            grid[row][col] = 'T'; // Place treasure
            placed++;
        }
    }
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int isLocationValid(int row, int col, char grid[GRID_SIZE][GRID_SIZE]) {
    return (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE);
}

void playGame(char grid[GRID_SIZE][GRID_SIZE], int *scores, int playerCount) {
    int currentPlayer = 0;
    int turns = 0;
    int totalTurns = 10; // Total number of turns

    while (turns < totalTurns) {
        printf("\nTurn %d - Player %d's turn:\n", turns + 1, currentPlayer + 1);
        printGrid(grid);

        int row, col;
        printf("Enter the row (0-4) and column (0-4) to search for treasure: ");
        scanf("%d %d", &row, &col);

        if (!isLocationValid(row, col, grid)) {
            printf("Invalid location! Try again.\n");
            continue;
        }

        if (grid[row][col] == 'T') {
            printf("Congratulations, Player %d! You found a treasure!\n", currentPlayer + 1);
            scores[currentPlayer]++;
            grid[row][col] = 'F'; // Mark found treasure
        } else if (grid[row][col] == 'F') {
            printf("You've already found that treasure! Try again.\n");
        } else {
            printf("Oops! No treasure here.\n");
            grid[row][col] = 'X'; // Mark searched location
        }
        
        currentPlayer = (currentPlayer + 1) % playerCount; // Move to the next player
        turns++;
    }
}