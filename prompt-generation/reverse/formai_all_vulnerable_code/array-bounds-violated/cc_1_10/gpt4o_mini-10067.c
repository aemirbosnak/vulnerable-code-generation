//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define MAX_PAIRS 8

typedef struct {
    char card;
    int revealed;
} Card;

void initializeDeck(Card deck[SIZE][SIZE]) {
    char symbols[MAX_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            deck[i][j].card = symbols[index / 2];
            deck[i][j].revealed = 0; 
            index++;
            if (index == MAX_PAIRS * 2) index = 0; // cycle through symbols
        }
    }
}

void shuffleDeck(Card deck[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE * SIZE; i++) {
        int r = rand() % (SIZE * SIZE);
        int r2 = rand() % (SIZE * SIZE);
        Card temp = deck[i / SIZE][i % SIZE];
        deck[i / SIZE][i % SIZE] = deck[r2 / SIZE][r2 % SIZE];
        deck[r2 / SIZE][r2 % SIZE] = temp;
    }
}

void displayDeck(Card deck[SIZE][SIZE]) {
    printf("Memory Game Deck:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (deck[i][j].revealed)
                printf(" %c ", deck[i][j].card);
            else
                printf(" ? ");
        }
        printf("\n");
    }
}

int main() {
    Card deck[SIZE][SIZE];
    initializeDeck(deck);
    shuffleDeck(deck);

    int pairsFound = 0;
    int totalPairs = MAX_PAIRS;
    int x1, y1, x2, y2;

    while (pairsFound < totalPairs) {
        displayDeck(deck);
        printf("Enter coordinates for first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter coordinates for second card (row and column): ");
        scanf("%d %d", &x2, &y2);

        if (deck[x1][y1].revealed || deck[x2][y2].revealed) {
            printf("One of those cards is already revealed!\n");
            continue;
        }

        deck[x1][y1].revealed = 1;
        deck[x2][y2].revealed = 1;
        displayDeck(deck);

        if (deck[x1][y1].card == deck[x2][y2].card) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again.\n");
            deck[x1][y1].revealed = 0;
            deck[x2][y2].revealed = 0;
        }
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}