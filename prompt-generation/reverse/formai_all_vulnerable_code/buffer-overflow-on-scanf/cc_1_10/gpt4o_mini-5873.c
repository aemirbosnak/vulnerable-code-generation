//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // Define size of the grid (4x4 in this case)
#define TOTAL_CARDS (SIZE * SIZE) // Total cards in the grid

char grid[SIZE][SIZE]; // The grid for the game
char revealed[SIZE][SIZE]; // Track revealed cards
bool matched[SIZE][SIZE]; // Track matched cards

// Function to shuffle the cards
void initializeGrid() {
    char values[TOTAL_CARDS / 2];
    for (int i = 0; i < TOTAL_CARDS / 2; i++) {
        values[i] = 'A' + i; // Assign letters A, B, C, etc.
    }

    // Duplicate the values
    for (int i = 0; i < TOTAL_CARDS / 2; i++) {
        grid[i / 2][i % 2] = values[i]; // Place in the grid
        grid[(i + (TOTAL_CARDS / 2)) / 2][(i + (TOTAL_CARDS / 2)) % 2] = values[i];
    }

    // Shuffle the grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r1 = rand() % SIZE;
            int r2 = rand() % SIZE;
            char temp = grid[i][j];
            grid[i][j] = grid[r1][r2];
            grid[r1][r2] = temp;
        }
    }
}

// Function to display the grid
void displayGrid() {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j] || matched[i][j]) {
                printf("%c ", grid[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// Function to reset the revealed cards
void resetRevealed() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            revealed[i][j] = false;
        }
    }
}

// Function to check if two selected cards match
bool checkMatch(int x1, int y1, int x2, int y2) {
    return grid[x1][y1] == grid[x2][y2];
}

// Main game function
void playGame() {
    int turns = 0;
    int totalMatches = 0;

    while (totalMatches < TOTAL_CARDS / 2) {
        displayGrid();
        int x1, y1, x2, y2;

        // Get first card coordinates
        printf("Select first card (row col): ");
        scanf("%d %d", &x1, &y1);
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || revealed[x1][y1] || matched[x1][y1]) {
            printf("Invalid selection. Try again.\n");
            continue;
        }
        revealed[x1][y1] = true;

        // Get second card coordinates
        displayGrid();
        printf("Select second card (row col): ");
        scanf("%d %d", &x2, &y2);
        if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || revealed[x2][y2] || matched[x2][y2] || (x1 == x2 && y1 == y2)) {
            printf("Invalid selection. Try again.\n");
            revealed[x1][y1] = false; // Reset first revealed card
            continue;
        }

        revealed[x2][y2] = true;

        // Check for match
        if (checkMatch(x1, y1, x2, y2)) {
            printf("Match found: %c\n", grid[x1][y1]);
            matched[x1][y1] = true;
            matched[x2][y2] = true;
            totalMatches++;
        } else {
            printf("No Match. Try again.\n");
            resetRevealed();
        }
        turns++;
    }

    printf("Congratulations! You've found all matches in %d turns.\n", turns);
}

// Main function
int main() {
    srand(time(NULL)); // Initialize random number generator
    initializeGrid(); // Setup grid
    resetRevealed(); // Reset revealed cards
    playGame(); // Start the game

    return 0;
}