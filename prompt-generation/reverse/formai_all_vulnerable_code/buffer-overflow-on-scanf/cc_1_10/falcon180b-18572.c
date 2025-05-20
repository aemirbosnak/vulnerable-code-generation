//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8

void init_cards(char cards[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            cards[i][j] = '-';
        }
    }
}

void init_deck(char deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i] = '2' + (i % 13);
    }
}

void shuffle_deck(char deck[NUM_CARDS]) {
    int i, j;
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        char temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_cards(char cards[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", cards[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char cards[ROWS][COLS];
    char deck[NUM_CARDS];
    init_cards(cards);
    init_deck(deck);
    shuffle_deck(deck);
    int matches = 0;
    int attempts = 0;
    while (matches < NUM_CARDS) {
        int choice1, choice2;
        printf("Attempts: %d\n", attempts);
        print_cards(cards);
        printf("Choose two cards:\n");
        scanf("%d %d", &choice1, &choice2);
        if (choice1 >= 0 && choice1 < ROWS && choice2 >= 0 && choice2 < ROWS) {
            if (cards[choice1][0] == cards[choice2][0]) {
                matches++;
                cards[choice1][0] = '-';
                cards[choice2][0] = '-';
            } else {
                cards[choice1][0] = 'X';
                cards[choice2][0] = 'X';
                attempts++;
            }
        } else {
            printf("Invalid choice.\n");
        }
    }
    printf("Congratulations! You matched all the cards in %d attempts.\n", attempts);
    return 0;
}