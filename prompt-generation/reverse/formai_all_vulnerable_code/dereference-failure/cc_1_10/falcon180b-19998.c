//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 16
#define MAX_SUITS 4
#define MAX_RANKS 13

typedef struct {
    int rank;
    int suit;
} Card;

void init_deck(Card deck[MAX_CARDS]) {
    int i, j;
    for (i = 0; i < MAX_CARDS; i++) {
        deck[i].rank = i + 1;
        deck[i].suit = i % MAX_SUITS;
    }
}

void shuffle_deck(Card deck[MAX_CARDS]) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < MAX_CARDS * 7; i++) {
        j = rand() % MAX_CARDS;
        temp = deck[i].rank;
        deck[i].rank = deck[j].rank;
        deck[j].rank = temp;
        temp = deck[i].suit;
        deck[i].suit = deck[j].suit;
        deck[j].suit = temp;
    }
}

void print_card(Card card) {
    switch (card.rank) {
        case 1:
            printf("Ace");
            break;
        case 11:
            printf("Jack");
            break;
        case 12:
            printf("Queen");
            break;
        case 13:
            printf("King");
            break;
        default:
            printf("%d", card.rank);
    }
    printf(" of ");
    switch (card.suit) {
        case 0:
            printf("Clubs");
            break;
        case 1:
            printf("Diamonds");
            break;
        case 2:
            printf("Hearts");
            break;
        case 3:
            printf("Spades");
            break;
    }
}

int main() {
    Card deck[MAX_CARDS];
    int i, j, matches = 0;

    init_deck(deck);
    shuffle_deck(deck);

    printf("Let's play memory!\n");

    for (i = 0; i < MAX_CARDS / 2; i++) {
        printf("Card %d: ", i + 1);
        print_card(deck[i]);
        printf("\n");
    }

    for (i = 0; i < MAX_CARDS / 2; i++) {
        for (j = 0; j < MAX_CARDS / 2; j++) {
            if (deck[i].rank == deck[j].rank && deck[i].suit == deck[j].suit) {
                printf("Match!\n");
                matches++;
                break;
            }
        }
    }

    if (matches == MAX_CARDS / 2) {
        printf("You win!\n");
    } else {
        printf("Sorry, you lose.\n");
    }

    return 0;
}