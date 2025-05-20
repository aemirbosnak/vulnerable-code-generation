//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4
#define NUM_CARDS (ROW * COL)

typedef struct {
    int row;
    int col;
    int value;
} Card;

void init_deck(Card deck[NUM_CARDS]) {
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i].row = i / ROW;
        deck[i].col = i % ROW;
        deck[i].value = i + 1;
    }
}

void shuffle_deck(Card deck[NUM_CARDS]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int row = rand() % ROW;
        int col = rand() % ROW;
        int value = rand() % NUM_CARDS + 1;
        deck[i].row = row;
        deck[i].col = col;
        deck[i].value = value;
    }
}

void print_deck(Card deck[NUM_CARDS]) {
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("%d ", deck[i].value);
    }
    printf("\n");
}

int main() {
    Card deck[NUM_CARDS];
    init_deck(deck);
    shuffle_deck(deck);
    print_deck(deck);

    int num_matches = 0;
    int num_attempts = 0;
    int row, col;

    while (num_matches < NUM_CARDS) {
        printf("Enter row and column for card %d: ", num_attempts + 1);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < ROW && col >= 0 && col < ROW) {
            if (deck[num_attempts].row == row && deck[num_attempts].col == col) {
                num_matches++;
            }
        }
        num_attempts++;
    }

    printf("You found %d matches in %d attempts.\n", num_matches, num_attempts);

    return 0;
}