//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 10
#define MAX_DECK_SIZE 52

// Define the card struct
typedef struct {
    int rank;
    char suit;
} Card;

typedef struct {
    Card cards[MAX_CARDS];
    int num_cards;
} Deck;

// Define the hand struct
typedef struct {
    Card cards[MAX_CARDS];
    int num_cards;
    int value;
} Hand;

int compare_cards(const void *a, const void *b) {
    Card *ca = (Card*)a;
    Card *cb = (Card*)b;

    if (ca->rank < cb->rank) {
        return -1;
    } else if (ca->rank > cb->rank) {
        return 1;
    } else {
        return 0;
    }
}

// Function to shuffle the deck
void shuffle_deck(Deck *deck) {
    qsort(deck->cards, deck->num_cards, sizeof(Card), compare_cards);
}

// Function to deal a card to a hand
void deal_card(Hand *hand, Deck *deck) {
    Card card = deck->cards[0];
    deck->cards[0] = deck->cards[deck->num_cards];
    deck->num_cards--;

    hand->cards[hand->num_cards] = card;
    hand->num_cards++;
}

// Function to deal five cards to a player
void deal_five_cards(Hand *hand, Deck *deck) {
    for (int i = 0; i < 5; i++) {
        deal_card(hand, deck);
    }
}

int main() {
    // Create a deck
    Deck deck;
    for (int i = 0; i < MAX_DECK_SIZE; i++) {
        deck.cards[i].rank = i + 1;
        deck.cards[i].suit = 'C';
    }
    deck.num_cards = MAX_DECK_SIZE;

    // Shuffle the deck
    shuffle_deck(&deck);

    // Create a hand for the player
    Hand player_hand;
    for (int i = 0; i < 5; i++) {
        deal_card(&player_hand, &deck);
    }

    // Print the hand
    printf("Player's hand: ");
    for (int i = 0; i < 5; i++) {
        printf("%c%d ", player_hand.cards[i].suit, player_hand.cards[i].rank);
    }
    printf("\n");

    // Determine the value of the hand
    int value = 0;
    for (int i = 0; i < 5; i++) {
        if (player_hand.cards[i].rank == 1 || player_hand.cards[i].rank == 11) {
            value += 11;
        } else if (player_hand.cards[i].rank == 1) {
            value += 10;
        } else if (player_hand.cards[i].rank == 2) {
            value += 9;
        } else if (player_hand.cards[i].rank == 3) {
            value += 8;
        } else if (player_hand.cards[i].rank == 4) {
            value += 7;
        } else if (player_hand.cards[i].rank == 5) {
            value += 6;
        } else if (player_hand.cards[i].rank == 6) {
            value += 5;
        } else if (player_hand.cards[i].rank == 7) {
            value += 4;
        } else if (player_hand.cards[i].rank == 8) {
            value += 3;
        } else if (player_hand.cards[i].rank == 9) {
            value += 2;
        } else {
            value += 1;
        }
    }

    printf("Hand value: %d\n", value);

    return 0;
}