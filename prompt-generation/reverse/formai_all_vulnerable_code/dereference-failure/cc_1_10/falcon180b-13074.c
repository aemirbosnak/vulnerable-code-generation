//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_CARDS 25
#define NUM_BALLS 75

typedef struct {
    int row, col;
} Card;

void generateCard(Card *card) {
    card->row = rand() % MAX_ROWS;
    card->col = rand() % MAX_COLS;
}

void printCard(Card card) {
    printf("(%d,%d)\n", card.row, card.col);
}

void generateCards(Card cards[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        generateCard(&cards[i]);
    }
}

void printCards(Card cards[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        printCard(cards[i]);
    }
}

int checkCard(Card card, int num) {
    return ((card.row == num / MAX_COLS) && (card.col == num % MAX_COLS));
}

void markCard(Card *card, int num) {
    if (checkCard(*card, num)) {
        card->row = -1;
        card->col = -1;
    }
}

int main() {
    srand(time(NULL));

    Card cards[MAX_CARDS];
    generateCards(cards);
    printCards(cards);

    int numBalls = 0;
    while (numBalls < NUM_BALLS) {
        int num = rand() % NUM_BALLS + 1;
        if (num <= NUM_BALLS) {
            printf("Bingo ball #%d: ", num);
            markCard(&cards[num - 1], num);
            numBalls++;
        }
    }

    printf("\n");
    printCards(cards);

    if (checkCard(cards[0], 1)) {
        printf("Bingo!\n");
    } else {
        printf("No bingo.\n");
    }

    return 0;
}