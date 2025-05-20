//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 4
#define HEIGHT 4
#define PAIRS (WIDTH * HEIGHT) / 2

typedef struct {
    char value;
    int revealed;
} Card;

void initializeCards(Card cards[HEIGHT][WIDTH]);
void shuffleCards(Card cards[HEIGHT][WIDTH]);
void printBoard(Card cards[HEIGHT][WIDTH], int revealCards[HEIGHT][WIDTH]);
int revealCard(Card cards[HEIGHT][WIDTH], int x, int y, int *score);
int checkMatch(Card cards[HEIGHT][WIDTH], int x1, int y1, int x2, int y2);
int allMatched(Card cards[HEIGHT][WIDTH]);
void playGame(Card cards[HEIGHT][WIDTH]);

int main() {
    Card cards[HEIGHT][WIDTH];
    initializeCards(cards);
    shuffleCards(cards);
    playGame(cards);
    return 0;
}

void initializeCards(Card cards[HEIGHT][WIDTH]) {
    char values[PAIRS];
    for (int i = 0; i < PAIRS; ++i) {
        values[i] = 'A' + i; // Fill the values from 'A' to the pairs count
    }
    // Each value appears twice
    for (int i = 0; i < PAIRS; ++i) {
        cards[i / (WIDTH/2)][(i % (WIDTH/2)) * 2] = (Card){values[i], 0};
        cards[i / (WIDTH/2)][(i % (WIDTH/2)) * 2 + 1] = (Card){values[i], 0};
    }
}

void shuffleCards(Card cards[HEIGHT][WIDTH]) {
    srand(time(0));
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int i1 = rand() % HEIGHT;
            int j1 = rand() % WIDTH;
            Card temp = cards[i][j];
            cards[i][j] = cards[i1][j1];
            cards[i1][j1] = temp;
        }
    }
}

void printBoard(Card cards[HEIGHT][WIDTH], int revealCards[HEIGHT][WIDTH]) {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (revealCards[i][j]) {
                printf(" %c ", cards[i][j].value);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int revealCard(Card cards[HEIGHT][WIDTH], int x, int y, int *score) {
    if (cards[x][y].revealed) {
        printf("Card already revealed!\n");
        return 0;
    }
    cards[x][y].revealed = 1;
    (*score)++;
    return 1;
}

int checkMatch(Card cards[HEIGHT][WIDTH], int x1, int y1, int x2, int y2) {
    return cards[x1][y1].value == cards[x2][y2].value ? 1 : 0;
}

int allMatched(Card cards[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (!cards[i][j].revealed) return 0;
        }
    }
    return 1;
}

void playGame(Card cards[HEIGHT][WIDTH]) {
    int revealCards[HEIGHT][WIDTH] = {0};
    int score = 0;
    while (!allMatched(cards)) {
        printBoard(cards, revealCards);
        int x1, y1, x2, y2;

        printf("Enter first card position (row col): ");
        scanf("%d %d", &x1, &y1);
        revealCard(cards, x1, y1, &score);
        
        printBoard(cards, revealCards);
        
        printf("Enter second card position (row col): ");
        scanf("%d %d", &x2, &y2);
        revealCard(cards, x2, y2, &score);
        
        if (checkMatch(cards, x1, y1, x2, y2)) {
            revealCards[x1][y1] = 1;
            revealCards[x2][y2] = 1;
            printf("Match found!\n");
        } else {
            printf("Not a match! Try again.\n");
            cards[x1][y1].revealed = 0;
            cards[x2][y2].revealed = 0;
        }

        sleep(1); // Pause for dramatic effect
    }

    printBoard(cards, revealCards);
    printf("Congratulations! You've matched all cards!\n");
}