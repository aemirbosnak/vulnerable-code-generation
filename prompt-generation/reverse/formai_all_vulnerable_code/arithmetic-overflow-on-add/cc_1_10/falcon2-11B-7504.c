//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CARDS 7
#define MAX_DECK_SIZE 52
#define MAX_HAND_SIZE 5

typedef struct card {
    char suit[3];
    char rank[3];
} card;

typedef struct deck {
    card cards[MAX_DECK_SIZE];
    int num_cards;
} deck;

typedef struct hand {
    int num_cards;
    card cards[MAX_HAND_SIZE];
} hand;

typedef struct player {
    char name[30];
    int chips;
    hand hand;
} player;

void shuffle_deck(deck *deck) {
    int i, j;
    for (i = MAX_DECK_SIZE - 1; i > 0; i--) {
        j = rand() % (i + 1);
        card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void print_deck(deck *deck) {
    int i;
    printf("Deck:\n");
    for (i = 0; i < deck->num_cards; i++) {
        printf("  %s of %s\n", deck->cards[i].rank, deck->cards[i].suit);
    }
}

void print_hand(hand *hand) {
    int i;
    printf("Hand:\n");
    for (i = 0; i < hand->num_cards; i++) {
        printf("  %s of %s\n", hand->cards[i].rank, hand->cards[i].suit);
    }
}

void print_player(player *player) {
    printf("Player: %s\n", player->name);
    printf("Chips: %d\n", player->chips);
    print_hand(&player->hand);
}

int main() {
    deck deck;
    player player1, player2;
    hand hand1, hand2;

    // Initialize the deck
    for (int i = 0; i < MAX_DECK_SIZE; i++) {
        deck.cards[i].rank[0] = 'A' + i % 13;
        deck.cards[i].rank[1] = '0' + i / 13;
        deck.cards[i].suit[0] = 'C' + i % 4;
        deck.cards[i].suit[1] = 'S' + i / 4;
        deck.cards[i].suit[2] = '\0';
        deck.num_cards++;
    }
    shuffle_deck(&deck);

    // Deal 5 cards to each player
    for (int i = 0; i < MAX_HAND_SIZE; i++) {
        hand1.cards[i] = deck.cards[i];
        hand2.cards[i] = deck.cards[i];
        deck.num_cards--;
    }

    // Print the deck
    print_deck(&deck);

    // Print the hands
    print_hand(&hand1);
    print_hand(&hand2);

    // Print the players
    print_player(&player1);
    print_player(&player2);

    return 0;
}