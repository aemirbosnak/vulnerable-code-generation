//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4
#define NUM_PAIRS 8

// Card struct
typedef struct {
    int value;
    int matched;
} Card;

// Grid of cards
Card grid[GRID_SIZE][GRID_SIZE];

// Function to initialize the grid
void initGrid() {
    // Initialize random number generator
    srand(time(NULL));

    // Create an array of values
    int values[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        values[i] = i / 2;
    }

    // Shuffle the array
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int j = rand() % (NUM_PAIRS * 2);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Fill the grid with values
    int index = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j].value = values[index];
            grid[i][j].matched = 0;
            index++;
        }
    }
}

// Function to print the grid
void printGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j].matched) {
                printf("  ");
            } else {
                printf("%2d ", grid[i][j].value);
            }
        }
        printf("\n");
    }
}

// Function to get user input
void getInput(int *row, int *col) {
    printf("Enter the row and column of the card you want to flip (e.g. 1 2): ");
    scanf("%d %d", row, col);
}

// Function to flip a card
void flipCard(int row, int col) {
    grid[row][col].matched = 1;
}

// Function to check if the game is over
int isGameOver() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (!grid[i][j].matched) {
                return 0;
            }
        }
    }
    return 1;
}

// Main function
int main() {
    // Initialize the grid
    initGrid();

    // Print the grid
    printGrid();

    // Main game loop
    while (!isGameOver()) {
        // Get user input
        int row1, col1, row2, col2;
        getInput(&row1, &col1);
        getInput(&row2, &col2);

        // Flip the cards
        flipCard(row1, col1);
        flipCard(row2, col2);

        // Print the grid
        printGrid();

        // Check if the cards match
        if (grid[row1][col1].value == grid[row2][col2].value) {
            printf("Match!\n");
        } else {
            printf("No match.\n");
        }
    }

    // Game over
    printf("Congratulations! You win!\n");

    return 0;
}