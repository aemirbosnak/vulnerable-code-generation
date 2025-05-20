//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 4
#define NUM_CARDS (ROW * COL)

int cards[NUM_CARDS][2]; // [0] = rank, [1] = suit
int num_cards_flipped = 0;
int num_matches = 0;

void init_cards() {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        cards[i][0] = i + 1;
        cards[i][1] = i % 4 + 1;
    }
}

void display_cards() {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        printf("_ ");
    }
    printf("\n");
}

void flip_card(int row, int col) {
    if (row >= 0 && row < ROW && col >= 0 && col < COL) {
        if (cards[row * COL + col][1] == 0) {
            cards[row * COL + col][1] = 1;
            num_cards_flipped++;
        }
    }
}

void check_match(int row, int col) {
    int i;
    for (i = 0; i < num_cards_flipped; i++) {
        if (cards[i][0] == cards[row * COL + col][0] &&
            cards[i][1] == cards[row * COL + col][1]) {
            num_matches++;
            printf("Match found!\n");
        }
    }
}

int main() {
    srand(time(NULL));
    init_cards();
    int choice;
    while (num_cards_flipped < NUM_CARDS) {
        display_cards();
        printf("Enter row and column to flip a card: ");
        scanf("%d %d", &choice, &choice);
        flip_card(choice - 1, choice - 1);
    }
    printf("Congratulations! You have %d matches in %d flips.\n", num_matches, num_cards_flipped);
    return 0;
}