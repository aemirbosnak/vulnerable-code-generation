//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

enum suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

struct card {
    enum suit suit;
    enum rank rank;
};

void init_deck(struct card deck[]) {
    int i;
    for (i = 0; i < 52; i++) {
        deck[i].suit = (enum suit) (i / 13);
        deck[i].rank = (enum rank) (i % 13 + 1);
    }
}

void shuffle_deck(struct card deck[]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(struct card card) {
    switch (card.rank) {
        case ACE:
            printf("Ace");
            break;
        case TWO:
            printf("Two");
            break;
        case THREE:
            printf("Three");
            break;
        case FOUR:
            printf("Four");
            break;
        case FIVE:
            printf("Five");
            break;
        case SIX:
            printf("Six");
            break;
        case SEVEN:
            printf("Seven");
            break;
        case EIGHT:
            printf("Eight");
            break;
        case NINE:
            printf("Nine");
            break;
        case TEN:
            printf("Ten");
            break;
        case JACK:
            printf("Jack");
            break;
        case QUEEN:
            printf("Queen");
            break;
        case KING:
            printf("King");
            break;
    }
    switch (card.suit) {
        case HEARTS:
            printf(" of Hearts");
            break;
        case DIAMONDS:
            printf(" of Diamonds");
            break;
        case CLUBS:
            printf(" of Clubs");
            break;
        case SPADES:
            printf(" of Spades");
            break;
    }
}

int main() {
    struct card deck[52];
    init_deck(deck);
    shuffle_deck(deck);

    int num_cards = 0;
    printf("How many cards would you like to draw? ");
    scanf("%d", &num_cards);

    printf("Your cards:\n");
    for (int i = 0; i < num_cards; i++) {
        struct card card = deck[i];
        print_card(card);
        printf("\n");
    }

    return 0;
}