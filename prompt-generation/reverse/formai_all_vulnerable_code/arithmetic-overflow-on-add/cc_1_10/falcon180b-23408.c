//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5
#define TOTAL_CARDS (ROWS * COLS)

typedef struct {
    int row;
    int col;
    char value;
} Card;

Card deck[TOTAL_CARDS];
int matches = 0;
int attempts = 0;

void initDeck() {
    int i;
    for (i = 0; i < TOTAL_CARDS; i++) {
        deck[i].row = rand() % ROWS;
        deck[i].col = rand() % COLS;
        deck[i].value = 'A' + i;
    }
}

void printDeck() {
    int i;
    for (i = 0; i < TOTAL_CARDS; i++) {
        printf("%c ", deck[i].value);
    }
    printf("\n");
}

void flipCard(int row, int col) {
    int index = row * COLS + col;
    if (deck[index].value == 'A' + matches) {
        printf("Match found!\n");
        matches++;
    } else {
        printf("No match.\n");
        attempts++;
    }
    deck[index].value = 'X';
}

void checkWin() {
    int i;
    for (i = 0; i < TOTAL_CARDS; i++) {
        if (deck[i].value!= 'X') {
            return;
        }
    }
    printf("You win!\n");
    exit(0);
}

int main() {
    srand(time(NULL));
    initDeck();
    printDeck();

    while (matches < TOTAL_CARDS / 2) {
        int row, col;
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        flipCard(row, col);
        printDeck();
        checkWin();
    }

    printf("You lose.\n");
    return 0;
}