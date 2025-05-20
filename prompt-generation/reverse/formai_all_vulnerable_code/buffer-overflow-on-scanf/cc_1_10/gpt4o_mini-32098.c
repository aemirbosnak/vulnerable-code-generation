//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4  // Number of cards along one dimension (4x4 board)
#define TOTAL_CARDS (SIZE * SIZE)
#define PAIRED_CARDS (TOTAL_CARDS / 2)

void shuffleCards(char cards[]) {
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void initializeCards(char cards[]) {
    for (int i = 0; i < PAIRED_CARDS; i++) {
        cards[2 * i] = 'A' + i; // First occurrence of the pair
        cards[2 * i + 1] = 'A' + i; // Second occurrence of the pair
    }
    shuffleCards(cards);
}

void displayBoard(char cards[], bool revealed[]) {
    printf("Memory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int idx = i * SIZE + j;
            if (revealed[idx]) {
                printf("[%c] ", cards[idx]);
            } else {
                printf("[#] ");
            }
        }
        printf("\n");
    }
}

bool checkMatch(char cards[], int firstIdx, int secondIdx) {
    return cards[firstIdx] == cards[secondIdx];
}

int main() {
    char cards[TOTAL_CARDS];
    bool revealed[TOTAL_CARDS] = {false};
    int attempts = 0;
    int pairsFound = 0;

    srand(time(NULL)); // Seed the random number generator
    initializeCards(cards);

    while (pairsFound < PAIRED_CARDS) {
        displayBoard(cards, revealed);
        int firstIdx, secondIdx;

        // Get first card from user
        printf("Enter the first card index (0-15): ");
        scanf("%d", &firstIdx);
        if (firstIdx < 0 || firstIdx >= TOTAL_CARDS || revealed[firstIdx]) {
            printf("Invalid input, try again.\n");
            continue;
        }

        // Get second card from user
        printf("Enter the second card index (0-15): ");
        scanf("%d", &secondIdx);
        if (secondIdx < 0 || secondIdx >= TOTAL_CARDS || revealed[secondIdx] || firstIdx == secondIdx) {
            printf("Invalid input, try again.\n");
            continue;
        }

        revealed[firstIdx] = true;
        revealed[secondIdx] = true;
        displayBoard(cards, revealed);

        if (checkMatch(cards, firstIdx, secondIdx)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again.\n");
            revealed[firstIdx] = false;
            revealed[secondIdx] = false;
        }

        attempts++;
    }

    printf("Congratulations! You've found all pairs in %d attempts.\n", attempts);
    return 0;
}