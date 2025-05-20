//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PLAYERS 4
#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card cards[NUM_CARDS];
    int num_cards;
} Deck;

typedef struct {
    Card cards[NUM_CARDS];
    int num_cards;
} Hand;

typedef struct {
    int player_id;
    Hand hand;
} Player;

void print_card(Card card) {
    char rank_str[3];
    char suit_str[2];

    switch (card.rank) {
        case 0:
            strcpy(rank_str, "2");
            break;
        case 1:
            strcpy(rank_str, "3");
            break;
        case 2:
            strcpy(rank_str, "4");
            break;
        case 3:
            strcpy(rank_str, "5");
            break;
        case 4:
            strcpy(rank_str, "6");
            break;
        case 5:
            strcpy(rank_str, "7");
            break;
        case 6:
            strcpy(rank_str, "8");
            break;
        case 7:
            strcpy(rank_str, "9");
            break;
        case 8:
            strcpy(rank_str, "10");
            break;
        case 9:
            strcpy(rank_str, "J");
            break;
        case 10:
            strcpy(rank_str, "Q");
            break;
        case 11:
            strcpy(rank_str, "K");
            break;
        case 12:
            strcpy(rank_str, "A");
            break;
    }

    switch (card.suit) {
        case 0:
            strcpy(suit_str, "H");
            break;
        case 1:
            strcpy(suit_str, "D");
            break;
        case 2:
            strcpy(suit_str, "C");
            break;
        case 3:
            strcpy(suit_str, "S");
            break;
    }

    printf("%s%s ", rank_str, suit_str);
}

void print_hand(Hand hand) {
    for (int i = 0; i < hand.num_cards; i++) {
        print_card(hand.cards[i]);
    }

    printf("\n");
}

void print_deck(Deck deck) {
    for (int i = 0; i < deck.num_cards; i++) {
        print_card(deck.cards[i]);
    }

    printf("\n");
}

void shuffle_deck(Deck *deck) {
    for (int i = 0; i < deck->num_cards; i++) {
        int r = rand() % deck->num_cards;

        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[r];
        deck->cards[r] = temp;
    }
}

void deal_cards(Deck *deck, Player *players) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_CARDS / NUM_PLAYERS; j++) {
            players[i].hand.cards[players[i].hand.num_cards++] = deck->cards[deck->num_cards - 1];
            deck->num_cards--;
        }
    }
}

int main() {
    Deck deck;
    Player players[NUM_PLAYERS];

    // Initialize the deck
    for (int i = 0; i < NUM_RANKS; i++) {
        for (int j = 0; j < NUM_SUITS; j++) {
            deck.cards[deck.num_cards].rank = i;
            deck.cards[deck.num_cards].suit = j;
            deck.num_cards++;
        }
    }

    // Shuffle the deck
    shuffle_deck(&deck);

    // Deal the cards
    deal_cards(&deck, players);

    // Print the hands
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand:\n", i + 1);
        print_hand(players[i].hand);
    }

    return 0;
}