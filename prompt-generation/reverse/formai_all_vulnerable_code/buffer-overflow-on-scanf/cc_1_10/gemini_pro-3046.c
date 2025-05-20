//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PAIRS 8

typedef struct {
    int value;
    int matched;
} card;

void shuffle(card *deck, int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(card c) {
    if (c.matched) {
        printf("[%d]", c.value);
    } else {
        printf("[  ]");
    }
}

void print_deck(card *deck, int n) {
    for (int i = 0; i < n; i++) {
        print_card(deck[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));

    card deck[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS; i++) {
        deck[i * 2].value = i;
        deck[i * 2 + 1].value = i;
        deck[i * 2].matched = 0;
        deck[i * 2 + 1].matched = 0;
    }

    shuffle(deck, NUM_PAIRS * 2);

    int matches = 0;
    int guesses = 0;

    while (matches < NUM_PAIRS) {
        print_deck(deck, NUM_PAIRS * 2);

        int guess1, guess2;
        printf("Guess two cards: ");
        scanf("%d %d", &guess1, &guess2);

        if (guess1 < 1 || guess1 > NUM_PAIRS * 2 || guess2 < 1 || guess2 > NUM_PAIRS * 2) {
            printf("Invalid guess\n");
            continue;
        }

        card c1 = deck[guess1 - 1];
        card c2 = deck[guess2 - 1];

        if (c1.matched || c2.matched) {
            printf("Card already matched\n");
            continue;
        }

        guesses++;

        if (c1.value == c2.value) {
            printf("Match!\n");
            c1.matched = 1;
            c2.matched = 1;
            matches++;
        } else {
            printf("No match\n");
        }
    }

    printf("Congratulations! You matched all %d pairs in %d guesses.\n", NUM_PAIRS, guesses);

    return 0;
}