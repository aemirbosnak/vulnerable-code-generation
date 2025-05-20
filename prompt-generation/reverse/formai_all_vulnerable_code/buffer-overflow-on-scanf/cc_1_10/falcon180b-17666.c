//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5
#define NUM_CARDS (ROWS * COLS)

int deck[NUM_CARDS];
int cards_left;
int num_matches;

void init_deck(void) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i] = i + 1;
    }
    cards_left = NUM_CARDS;
    num_matches = 0;
}

void shuffle_deck(void) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_deck(void) {
    int i;
    printf("Deck:\n");
    for (i = 0; i < NUM_CARDS; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");
}

void flip_card(int card_num) {
    if (deck[card_num] == 0) {
        deck[card_num] = 1;
    } else {
        deck[card_num] = 0;
    }
}

int check_match(int card1, int card2) {
    if (deck[card1] == deck[card2]) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    int i, j, match_found;
    init_deck();
    shuffle_deck();
    print_deck();
    while (cards_left > 0) {
        printf("Enter two card numbers: ");
        scanf("%d %d", &i, &j);
        if (i >= 0 && i < ROWS * COLS && j >= 0 && j < ROWS * COLS) {
            flip_card(i);
            flip_card(j);
            match_found = check_match(i, j);
            if (match_found) {
                num_matches++;
            } else {
                flip_card(i);
                flip_card(j);
            }
        } else {
            printf("Invalid card numbers.\n");
        }
        cards_left--;
        if (cards_left % 2 == 0) {
            printf("Remaining cards: %d\n", cards_left);
        }
    }
    printf("Game over. You found %d matches.\n", num_matches);
    return 0;
}