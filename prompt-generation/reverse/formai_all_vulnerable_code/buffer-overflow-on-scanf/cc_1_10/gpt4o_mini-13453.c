//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Size of the board (4x4)
#define TOTAL_CARDS (SIZE * SIZE)

char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char cards[TOTAL_CARDS];
int revealed[TOTAL_CARDS] = {0}; // Keep track of revealed cards

void initializeDeck() {
    // Prepare the deck by pairing symbols
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        cards[i * 2] = symbols[i];
        cards[i * 2 + 1] = symbols[i];
    }
    
    // Shuffle the cards
    for (int i = 0; i < TOTAL_CARDS; i++) {
        int randIndex = rand() % TOTAL_CARDS;
        char temp = cards[i];
        cards[i] = cards[randIndex];
        cards[randIndex] = temp;
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int index = i * SIZE + j;
            if (revealed[index]) {
                printf(" %c ", cards[index]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int isMatch(int firstIndex, int secondIndex) {
    return cards[firstIndex] == cards[secondIndex];
}

int allMatched() {
    for (int i = 0; i < TOTAL_CARDS; i++) {
        if (!revealed[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    initializeDeck();

    int attempts = 0;
    while (!allMatched()) {
        printBoard();
        int firstChoice, secondChoice;

        // Get first card choice
        printf("Select the first card (0-%d): ", TOTAL_CARDS - 1);
        scanf("%d", &firstChoice);

        // Validate first choice
        if (firstChoice < 0 || firstChoice >= TOTAL_CARDS || revealed[firstChoice]) {
            printf("Invalid choice. Try again.\n");
            continue;
        }
        revealed[firstChoice] = 1;

        printBoard(); // show the board after first selection

        // Get second card choice
        printf("Select the second card (0-%d): ", TOTAL_CARDS - 1);
        scanf("%d", &secondChoice);

        // Validate second choice
        if (secondChoice < 0 || secondChoice >= TOTAL_CARDS || revealed[secondChoice]) {
            printf("Invalid choice. Try again.\n");
            revealed[firstChoice] = 0; // Hide the first choice
            continue;
        }
        revealed[secondChoice] = 1;

        // Check if they match
        if (isMatch(firstChoice, secondChoice)) {
            printf("It's a match!\n");
        } else {
            printf("Not a match. Try again.\n");
            attempts++;
            revealed[firstChoice] = 0; // Hide the first choice
            revealed[secondChoice] = 0; // Hide the second choice
        }

        printf("Attempts: %d\n", attempts);
    }

    printf("Congratulations! You've matched all cards in %d attempts.\n", attempts);
    return 0;
}