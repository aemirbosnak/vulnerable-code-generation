//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 6

typedef struct {
    char value;
    int revealed;
} Card;

Card deck[MAX_SIZE][MAX_SIZE];
int gridSize;

void initializeDeck() {
    int totalPairs = (gridSize * gridSize) / 2;
    char values[MAX_SIZE * MAX_SIZE];

    // Fill values for pairs
    for (int i = 0; i < totalPairs; ++i) {
        values[i * 2] = 'A' + i;
        values[i * 2 + 1] = 'A' + i;
    }

    // Shuffle the values
    for (int i = totalPairs * 2 - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        char temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Assign shuffled values to the deck
    for (int i = 0, k = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            deck[i][j].value = values[k++];
            deck[i][j].revealed = 0;
        }
    }
}

void printDeck() {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (deck[i][j].revealed) {
                printf(" [%c] ", deck[i][j].value);
            } else {
                printf(" [ ] ");
            }
        }
        printf("\n");
    }
}

int revealCards(int x1, int y1, int x2, int y2) {
    if (deck[x1][y1].value == deck[x2][y2].value) {
        deck[x1][y1].revealed = 1;
        deck[x2][y2].revealed = 1;
        return 1; // Match found
    }
    return 0; // No match
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Memory Game!\n");
    printf("Enter the grid size (even number between 2 and %d): ", MAX_SIZE);
    scanf("%d", &gridSize);

    // Validate input
    if (gridSize < 2 || gridSize > MAX_SIZE || gridSize % 2 != 0) {
        printf("Invalid grid size. Exiting game.\n");
        return 1;
    }

    initializeDeck();

    int totalPairs = (gridSize * gridSize) / 2;
    int pairsFound = 0;

    while (pairsFound < totalPairs) {
        printDeck();

        int x1, y1, x2, y2;
        printf("Choose first card (row col): ");
        scanf("%d %d", &x1, &y1);

        printf("Choose second card (row col): ");
        scanf("%d %d", &x2, &y2);

        if (x1 < 0 || x1 >= gridSize || y1 < 0 || y1 >= gridSize ||
            x2 < 0 || x2 >= gridSize || y2 < 0 || y2 >= gridSize ||
            (x1 == x2 && y1 == y2) || deck[x1][y1].revealed || deck[x2][y2].revealed) {
            printf("Invalid selection. Try again.\n");
            continue;
        }

        if (revealCards(x1, y1, x2, y2)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("No match. Try again.\n");
        }
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}