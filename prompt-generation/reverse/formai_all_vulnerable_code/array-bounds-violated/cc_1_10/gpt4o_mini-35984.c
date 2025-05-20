//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4
#define TOTAL_PAIRS (SIZE * SIZE) / 2

void shuffle(int cards[][SIZE]) {
    int temp[SIZE * SIZE];
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        temp[i] = i % TOTAL_PAIRS + 1;  // Assigning pairs 1 to TOTAL_PAIRS
    }
    for (int i = 0; i < SIZE * SIZE; i++) {
        int r = rand() % (TOTAL_PAIRS);
        int tempCard = temp[i];
        temp[i] = temp[r];
        temp[r] = tempCard;
    }
  
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cards[i][j] = temp[i * SIZE + j];
        }
    }
}

void displayBoard(int cards[][SIZE], bool revealed[][SIZE]) {
    printf("Current board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d\t", cards[i][j]);
            } else {
                printf("X\t");
            }
        }
        printf("\n");
    }
}

bool allRevealed(bool revealed[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    srand(time(0)); // Seed random number generator

    int cards[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false}; // Track revealed cards
    
    shuffle(cards);

    int guess1x, guess1y, guess2x, guess2y;
    int attempts = 0;

    while (!allRevealed(revealed)) {
        displayBoard(cards, revealed);
        
        // Get first guess
        printf("Enter the coordinates of the first card (row and column): ");
        scanf("%d %d", &guess1x, &guess1y);

        // Reveal the first card
        revealed[guess1x][guess1y] = true;
        displayBoard(cards, revealed);
        
        // Get second guess
        printf("Enter the coordinates of the second card (row and column): ");
        scanf("%d %d", &guess2x, &guess2y);
        
        // Reveal the second card
        revealed[guess2x][guess2y] = true;
        displayBoard(cards, revealed);
        
        attempts++;

        // Check if they match
        if (cards[guess1x][guess1y] != cards[guess2x][guess2y]) {
            printf("Not a match! Try again.\n");
            revealed[guess1x][guess1y] = false; // Hide first card
            revealed[guess2x][guess2y] = false; // Hide second card
        } else {
            printf("It's a match!\n");
        }

        printf("Attempts: %d\n\n", attempts);
    }

    printf("Congratulations! You've matched all pairs in %d attempts!\n", attempts);
    return 0;
}