//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PAIRS 8

typedef struct {
    int value;
    int is_matched;
} card;

void shuffle_cards(card deck[]) {
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int r = rand() % (NUM_PAIRS * 2);
        card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void print_board(card deck[]) {
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        if (deck[i].is_matched) {
            printf("  ");
        } else {
            printf("%d ", deck[i].value);
        }
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));

    card deck[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS; i++) {
        deck[i].value = i + 1;
        deck[i + NUM_PAIRS].value = i + 1;
        deck[i].is_matched = 0;
        deck[i + NUM_PAIRS].is_matched = 0;
    }

    shuffle_cards(deck);

    int num_guesses = 0;
    int num_matched = 0;

    while (num_matched < NUM_PAIRS) {
        print_board(deck);

        int guess1, guess2;
        printf("Enter two guesses (1-%d): ", NUM_PAIRS * 2);
        scanf("%d %d", &guess1, &guess2);

        if (deck[guess1 - 1].value == deck[guess2 - 1].value) {
            deck[guess1 - 1].is_matched = 1;
            deck[guess2 - 1].is_matched = 1;
            num_matched++;
            num_guesses++;
        } else {
            num_guesses++;
        }
    }

    printf("Congratulations! You matched all the pairs in %d guesses.\n", num_guesses);

    return 0;
}