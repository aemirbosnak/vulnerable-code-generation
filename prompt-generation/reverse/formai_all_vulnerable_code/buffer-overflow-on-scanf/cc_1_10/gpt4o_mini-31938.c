//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4
#define TOTAL_CARDS (SIZE * SIZE / 2)

typedef struct {
    char value;
    int revealed; // 0 for hidden, 1 for revealed
} Card;

void initializeDeck(Card deck[SIZE][SIZE]) {
    char symbols[TOTAL_CARDS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < TOTAL_CARDS; i++) {
        deck[i / (SIZE / 2)][(i % (SIZE / 2)) * 2] = (Card){symbols[i], 0};
        deck[i / (SIZE / 2)][(i % (SIZE / 2)) * 2 + 1] = (Card){symbols[i], 0};
    }

    // Shuffle the deck
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r1 = rand() % SIZE;
            int r2 = rand() % SIZE;

            Card temp = deck[i][j];
            deck[i][j] = deck[r1][r2];
            deck[r1][r2] = temp;
        }
    }
}

void displayDeck(Card deck[SIZE][SIZE]) {
    printf("\nMemory Game - Match the Pairs!\n");
    printf("  0 1 2 3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (deck[i][j].revealed) {
                printf("%c ", deck[i][j].value);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int revealCard(Card deck[SIZE][SIZE], int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || deck[x][y].revealed) {
        return 0;
    }
    deck[x][y].revealed = 1;
    return 1;
}

int checkMatch(Card deck[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return (deck[x1][y1].value == deck[x2][y2].value);
}

void gameLoop() {
    Card deck[SIZE][SIZE];
    int foundPairs = 0;
    int totalPairs = TOTAL_CARDS;
    srand(time(NULL));
    initializeDeck(deck);

    while (foundPairs < totalPairs) {
        displayDeck(deck);
        int x1, y1, x2, y2;

        printf("Pick first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        if (!revealCard(deck, x1, y1)) {
            printf("Invalid choice or card already revealed. Try again.\n");
            continue;
        }
        
        displayDeck(deck);
        printf("Pick second card (row and column): ");
        scanf("%d %d", &x2, &y2);
        if (!revealCard(deck, x2, y2)) {
            printf("Invalid choice or card already revealed. Try again.\n");
            continue;
        }

        displayDeck(deck);
        if (checkMatch(deck, x1, y1, x2, y2)) {
            printf("It's a match!\n");
            foundPairs++;
        } else {
            printf("Not a match, try again!\n");
            // Hide cards again after a brief pause
            sleep(1);
            deck[x1][y1].revealed = 0;
            deck[x2][y2].revealed = 0;
        }
    }
    printf("Congratulations! You've found all pairs!\n");
}

int main() {
    printf("Welcome to the Memory Card Game!\n");
    gameLoop();
    return 0;
}