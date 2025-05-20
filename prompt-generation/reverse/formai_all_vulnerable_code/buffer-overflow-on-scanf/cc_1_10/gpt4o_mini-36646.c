//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 4 // 4x4 grid
#define NUM_CARDS (SIZE * SIZE / 2) // Number of unique cards
#define MAX_ATTEMPTS 2

// Function to shuffle the cards
void shuffle(int *cards) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        int r = rand() % (SIZE * SIZE);
        // Swap cards
        int temp = cards[i];
        cards[i] = cards[r];
        cards[r] = temp;
    }
}

// Function to display the grid
void displayGrid(char grid[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\nMemory Game Grid:\n");
    printf("   0 1 2 3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", grid[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    int cards[SIZE * SIZE];
    char grid[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // To track revealed cards

    // Initialize cards
    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i] = 'A' + i; // Unique cards from 'A' to 'Num_Cards'
        cards[NUM_CARDS + i] = 'A' + i; // Repeat for pairs
    }

    // Shuffle cards
    shuffle(cards);

    // Fill grid with shuffled cards
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = cards[i * SIZE + j];
        }
    }

    int pairsFound = 0;
    while (pairsFound < NUM_CARDS) {
        displayGrid(grid, revealed);
        
        int x1, y1, x2, y2;
        printf("Select first card to reveal (row and column): ");
        scanf("%d %d", &x1, &y1);

        // Validate first selection
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || revealed[x1][y1]) {
            printf("Invalid selection. Try again!\n");
            continue;
        }
        revealed[x1][y1] = 1; // Reveal first card

        displayGrid(grid, revealed);
        
        printf("Select second card to reveal (row and column): ");
        scanf("%d %d", &x2, &y2);

        // Validate second selection
        if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || revealed[x2][y2] || (x1 == x2 && y1 == y2)) {
            printf("Invalid selection. Try again!\n");
            revealed[x1][y1] = 0; // Hide first card again
            continue;
        }
        revealed[x2][y2] = 1; // Reveal second card

        // Check for match
        if (grid[x1][y1] == grid[x2][y2]) {
            printf("It's a match! You found a pair!\n");
            pairsFound++;
        } else {
            printf("No match! Try again.\n");
            sleep(2); // Pause for a moment before hiding cards
            revealed[x1][y1] = 0; // Hide first card
            revealed[x2][y2] = 0; // Hide second card
        }
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}