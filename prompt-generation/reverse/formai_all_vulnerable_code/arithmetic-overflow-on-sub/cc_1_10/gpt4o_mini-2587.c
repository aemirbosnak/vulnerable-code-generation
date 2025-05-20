//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4 // For a 4x4 grid
#define TOTAL_PAIRS (SIZE * SIZE) / 2

char cards[SIZE][SIZE]; // The cards on the grid
char revealed[SIZE][SIZE]; // Revealed cards storage
int matchedPairs = 0; // Count of matched pairs

void initializeCards() {
    char symbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Symbols for cards
    int index = 0;

    // Fill cards with pairs of symbols
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cards[i][j] = symbols[index / 2]; // Assign the symbol
            // Move to the next symbol after each pair
            if ((index % 2) == 1) index++; 
            index++;
        }
    }

    // Shuffle the cards
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        int randomIndex = rand() % TOTAL_PAIRS;
        int r1 = i / SIZE, c1 = i % SIZE;
        int r2 = randomIndex / SIZE, c2 = randomIndex % SIZE;

        // Swap cards
        char temp = cards[r1][c1];
        cards[r1][c1] = cards[r2][c2];
        cards[r2][c2] = temp;
    }

    memset(revealed, ' ', sizeof(revealed)); // Reset revealed to empty state
}

void printGrid() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j] == 'X') {
                printf(" [%c] ", cards[i][j]); // Show matched card
            } else {
                printf(" [ ] "); // Hidden card
            }
        }
        printf("\n");
    }
}

int checkForMatch(int r1, int c1, int r2, int c2) {
    if (cards[r1][c1] == cards[r2][c2]) {
        revealed[r1][c1] = 'X'; // Mark as matched
        revealed[r2][c2] = 'X'; // Mark as matched
        matchedPairs++;
        return 1; // Matched
    }
    return 0; // Not matched
}

int isGameOver() {
    return matchedPairs == TOTAL_PAIRS / 2;
}

int main() {
    int r1, c1, r2, c2;
    srand(time(NULL)); // Seed random number generator
    initializeCards(); // Initialize and shuffle the cards

    printf("Welcome to the Memory Game!\n");

    while (!isGameOver()) {
        printGrid();
        printf("Choose first card (row and column): ");
        scanf("%d %d", &r1, &c1);
        r1--; c1--; // Adjust for zero-based index

        printf("Choose second card (row and column): ");
        scanf("%d %d", &r2, &c2);
        r2--; c2--; // Adjust for zero-based index

        if (r1 < 0 || r1 >= SIZE || c1 < 0 || c1 >= SIZE ||
            r2 < 0 || r2 >= SIZE || c2 < 0 || c2 >= SIZE ||
            (r1 == r2 && c1 == c2) || revealed[r1][c1] == 'X' || revealed[r2][c2] == 'X') {
            printf("Invalid choice. Try again.\n");
            sleep(1); // Wait for a moment
            continue;
        }

        revealed[r1][c1] = cards[r1][c1]; // Temporarily reveal card
        revealed[r2][c2] = cards[r2][c2]; // Temporarily reveal card
        printGrid(); // Show the chosen cards
        sleep(1); // Show the selected cards briefly

        if (!checkForMatch(r1, c1, r2, c2)) {
            printf("No match! Try again.\n");
            revealed[r1][c1] = ' '; // Hide card again
            revealed[r2][c2] = ' '; // Hide card again
        } else {
            printf("You found a match!\n");
        }
    }

    printf("Congratulations! You've matched all pairs!\n");
    return 0;
}