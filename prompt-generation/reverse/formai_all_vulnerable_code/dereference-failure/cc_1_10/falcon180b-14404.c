//Falcon-180B DATASET v1.0 Category: Poker Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_PLAYERS 2
#define NUM_CARDS_DEALT 5

typedef struct {
    char suit;
    char rank;
} Card;

typedef struct {
    Card *cards;
    int num_cards;
} Hand;

typedef struct {
    Hand hand;
    int bet;
} Player;

Card deck[DECK_SIZE];
Player players[NUM_PLAYERS];

void shuffle_deck() {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].suit = (char) rand() % 4 + '2';
        deck[i].rank = (char) rand() % 13 + '2';
    }
}

void deal_cards() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_CARDS_DEALT; j++) {
            int card_index = rand() % DECK_SIZE;
            Card card = deck[card_index];
            players[i].hand.cards[j] = card;
            deck[card_index] = deck[DECK_SIZE - 1];
            deck[DECK_SIZE - 1] = card;
        }
    }
}

int evaluate_hand(Hand hand) {
    int score = 0;
    for (int i = 0; i < hand.num_cards; i++) {
        if (hand.cards[i].rank == 'A' || hand.cards[i].rank == 'K' || hand.cards[i].rank == 'Q' || hand.cards[i].rank == 'J') {
            score += 10;
        } else if (hand.cards[i].rank == '2' || hand.cards[i].rank == '3' || hand.cards[i].rank == '4' || hand.cards[i].rank == '5' || hand.cards[i].rank == '6' || hand.cards[i].rank == '7' || hand.cards[i].rank == '8' || hand.cards[i].rank == '9') {
            score += hand.cards[i].rank - '2';
        }
    }
    return score;
}

void display_hands() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand:\n", i + 1);
        for (int j = 0; j < players[i].hand.num_cards; j++) {
            printf("%c of %c\n", players[i].hand.cards[j].rank, players[i].hand.cards[j].suit);
        }
        printf("Hand score: %d\n\n", evaluate_hand(players[i].hand));
    }
}

int main() {
    shuffle_deck();
    deal_cards();
    display_hands();

    return 0;
}