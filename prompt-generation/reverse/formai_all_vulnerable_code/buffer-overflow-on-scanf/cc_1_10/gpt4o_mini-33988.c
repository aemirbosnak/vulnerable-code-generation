//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 4 // Define the size of the memory grid
#define CELL_COUNT (SIZE * SIZE) // Total number of cells
#define MAX_TRIES 3 // Number of tries for each round

void initializeGrid(char grid[SIZE][SIZE], int symbols[CELL_COUNT]) {
    int index = 0;
    for (int i = 0; i < CELL_COUNT / 2; i++) {
        // Fill the symbols array with pairs of letters
        symbols[index++] = 'A' + i; // Assume unique characters A, B, C...
        symbols[index++] = 'A' + i; // Pairing the same characters
    }

    // Shuffle the symbols
    for (int i = 0; i < CELL_COUNT; i++) {
        int randIndex = rand() % CELL_COUNT;
        char temp = symbols[i];
        symbols[i] = symbols[randIndex];
        symbols[randIndex] = temp;
    }

    // Fill the grid with shuffled symbols
    index = 0;
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            grid[r][c] = symbols[index++];
        }
    }
}

void printGrid(char grid[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\nMemory Game Grid:\n");
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (revealed[r][c]) {
                printf(" %c ", grid[r][c]); // Show the symbol
            } else {
                printf(" ? ");
            }
        }
        printf("\n");
    }
}

int playGame() {
    char grid[SIZE][SIZE];
    int symbols[CELL_COUNT];
    int revealed[SIZE][SIZE] = {0}; // 0 - hidden, 1 - revealed
    int matches = 0;

    // Initialize random number generator and grid
    srand(time(NULL));
    initializeGrid(grid, symbols);

    while (matches < (CELL_COUNT / 2)) {
        printGrid(grid, revealed);
        int firstR, firstC, secondR, secondC;

        // Player selects the first cell
        printf("Select first cell (row col): ");
        scanf("%d %d", &firstR, &firstC);
        firstR--; firstC--; // Adjust to zero-based index

        // Validate input
        if (firstR < 0 || firstR >= SIZE || firstC < 0 || firstC >= SIZE || revealed[firstR][firstC]) {
            printf("Invalid selection. Try again.\n");
            continue;
        }

        revealed[firstR][firstC] = 1; // Reveal the first cell
        printGrid(grid, revealed);

        // Player selects the second cell
        printf("Select second cell (row col): ");
        scanf("%d %d", &secondR, &secondC);
        secondR--; secondC--; // Adjust to zero-based index

        // Validate input
        if (secondR < 0 || secondR >= SIZE || secondC < 0 || secondC >= SIZE || revealed[secondR][secondC]) {
            printf("Invalid selection. Try again.\n");
            revealed[firstR][firstC] = 0; // Hide the first cell again
            continue;
        }

        revealed[secondR][secondC] = 1; // Reveal the second cell
        printGrid(grid, revealed);

        // Check for a match
        if (grid[firstR][firstC] == grid[secondR][secondC]) {
            printf("Match found!\n");
            matches++;
        } else {
            printf("No match! Try again.\n");
            sleep(2); // Pause before hiding the non-matching cells
            revealed[firstR][firstC] = 0; // Hide the first cell again
            revealed[secondR][secondC] = 0; // Hide the second cell again
        }
    }

    printf("Congratulations! You've matched all pairs.\n");
    return 0; // End game
}

int main() {
    printf("Welcome to the Memory Game!\n");
    playGame();
    return 0;
}