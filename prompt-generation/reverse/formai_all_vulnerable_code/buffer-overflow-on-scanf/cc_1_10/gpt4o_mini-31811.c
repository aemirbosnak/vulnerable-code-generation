//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define TREASURE_COUNT 3

char grid[GRID_SIZE][GRID_SIZE];
int treasures[TREASURE_COUNT][2]; // To store treasure locations

void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '-'; // Initialize grid with dashes
        }
    }
}

void placeTreasures() {
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < TREASURE_COUNT; i++) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] == 'T'); // Ensure no overlapping treasures

        grid[x][y] = 'T'; // Place the treasure in the grid
        treasures[i][0] = x; // Store x-coordinate
        treasures[i][1] = y; // Store y-coordinate
    }
}

void printGrid() {
    printf("Current Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int checkMatch(int x, int y) {
    for (int i = 0; i < TREASURE_COUNT; i++) {
        if (treasures[i][0] == x && treasures[i][1] == y) {
            return 1; // Match found
        }
    }
    return 0; // No match
}

int main() {
    int foundTreasures = 0;
    int attempts = 0;

    initializeGrid();
    placeTreasures();

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("You have to find %d treasures hidden in a %dx%d grid.\n", TREASURE_COUNT, GRID_SIZE, GRID_SIZE);
    
    while (foundTreasures < TREASURE_COUNT) {
        printGrid();
        
        int x, y;
        printf("Enter your guess (row and column): ");
        scanf("%d %d", &x, &y);

        // Validate the input
        if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
            printf("Invalid input. Please enter values between 0 and %d.\n", GRID_SIZE - 1);
            continue;
        }

        attempts++;

        if (grid[x][y] == 'T') {
            printf("You've already found a treasure at (%d, %d)!\n", x, y);
        } else if (checkMatch(x, y)) {
            grid[x][y] = 'T'; // Mark treasure as found
            foundTreasures++;
            printf("Congratulations! You found a treasure at (%d, %d)!\n", x, y);
        } else {
            grid[x][y] = 'X'; // Mark this position as tried
            printf("No treasure at (%d, %d). Try again!\n", x, y);
        }
    }

    printf("You've found all the treasures in %d attempts!\n", attempts);
    printGrid();
    printf("Thank you for playing Treasure Hunt!\n");

    return 0;
}