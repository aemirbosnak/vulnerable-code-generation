//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEARTS "\xF0\x9F\x92\xA9"
#define DIAMONDS "\xF0\x9F\x92\xA6"
#define CLUBS "\xF0\x9F\x92\xA7"
#define SPADES "\xF0\x9F\x92\xA8"
#define EMPTY_CARD " "

#define ROWS 3
#define COLS 4
#define TOTAL_CARDS 6

// Function to initialize the deck of cards
void init_deck(char deck[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            deck[i][j] = EMPTY_CARD;
        }
    }
}

// Function to shuffle the deck of cards
void shuffle_deck(char deck[ROWS][COLS]) {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS - 1; j++) {
            for (k = 0; k < ROWS - i - 1; k++) {
                if (deck[k][j]!= EMPTY_CARD && deck[k][j]!= deck[k + 1][j]) {
                    char temp = deck[k][j];
                    deck[k][j] = deck[k + 1][j];
                    deck[k + 1][j] = temp;
                }
            }
        }
    }
}

// Function to print the deck of cards
void print_deck(char deck[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", deck[i][j]);
        }
        printf("\n");
    }
}

// Function to check if two cards match
int check_match(char card1, char card2) {
    if (card1 == card2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));
    char deck[ROWS][COLS];
    init_deck(deck);
    shuffle_deck(deck);
    int matches = 0, attempts = 0;
    char card1, card2;
    while (matches < TOTAL_CARDS) {
        printf("Attempts: %d\n", attempts);
        print_deck(deck);
        printf("Choose two cards: ");
        scanf(" %c %c", &card1, &card2);
        if (check_match(card1, card2)) {
            matches++;
        } else {
            printf("Incorrect match!\n");
        }
        attempts++;
        sleep(1);
    }
    printf("Congratulations! You won in %d attempts!\n", attempts);
    return 0;
}