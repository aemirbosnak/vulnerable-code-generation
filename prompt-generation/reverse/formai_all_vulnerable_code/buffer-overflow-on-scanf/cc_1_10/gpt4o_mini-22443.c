//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 4

void initializeGrid(int grid[GRID_SIZE][GRID_SIZE]);
void shuffleGrid(int grid[GRID_SIZE][GRID_SIZE]);
void printGrid(int grid[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE]);
bool checkMatch(int grid[GRID_SIZE][GRID_SIZE], int row1, int col1, int row2, int col2);
bool allMatched(bool revealed[GRID_SIZE][GRID_SIZE]);

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    bool revealed[GRID_SIZE][GRID_SIZE] = {false};
    int row1, col1, row2, col2;
    int attempts = 0;

    srand(time(0)); // Seed random number generator
    initializeGrid(grid);
    shuffleGrid(grid);

    while (!allMatched(revealed)) {
        printGrid(grid, revealed);

        // Get first choice
        printf("Choose first card (row col): ");
        scanf("%d %d", &row1, &col1);
        
        // Validate input
        if (row1 < 0 || row1 >= GRID_SIZE || col1 < 0 || col1 >= GRID_SIZE || revealed[row1][col1]) {
            printf("Invalid choice! Try again.\n");
            continue;
        }
        
        revealed[row1][col1] = true;
        printGrid(grid, revealed);

        // Get second choice
        printf("Choose second card (row col): ");
        scanf("%d %d", &row2, &col2);
        
        // Validate input
        if (row2 < 0 || row2 >= GRID_SIZE || col2 < 0 || col2 >= GRID_SIZE || (row2 == row1 && col2 == col1) || revealed[row2][col2]) {
            printf("Invalid choice! Try again.\n");
            revealed[row1][col1] = false; // Un-reveal first card
            continue;
        }

        attempts++;
        revealed[row2][col2] = true;
        printGrid(grid, revealed);

        if (checkMatch(grid, row1, col1, row2, col2)) {
            printf("It's a match!\n");
        } else {
            printf("Not a match. Press Enter to continue...");
            revealed[row1][col1] = false;
            revealed[row2][col2] = false;
            getchar(); // Wait for user input
            getchar(); // Handle the newline character
        }
    }

    printf("Congratulations! You've matched all cards in %d attempts.\n", attempts);
    return 0;
}

void initializeGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    int numPairs = (GRID_SIZE * GRID_SIZE) / 2;
    int value = 1;

    for (int i = 0; i < numPairs; i++) {
        grid[i / GRID_SIZE][i % GRID_SIZE] = value;
        grid[(i / GRID_SIZE + 1) % GRID_SIZE][(i + 1) % GRID_SIZE] = value++;
    }
}

void shuffleGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int r = rand() % GRID_SIZE;
            int c = rand() % GRID_SIZE;
            int temp = grid[i][j];
            grid[i][j] = grid[r][c];
            grid[r][c] = temp;
        }
    }
}

void printGrid(int grid[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", grid[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

bool checkMatch(int grid[GRID_SIZE][GRID_SIZE], int row1, int col1, int row2, int col2) {
    return grid[row1][col1] == grid[row2][col2];
}

bool allMatched(bool revealed[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}