//GEMINI-pro DATASET v1.0 Category: Poker Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 2

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

void create_deck(Deck *deck) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        deck->cards[i].rank = i % 13 + 1;
        deck->cards[i].suit = i / 13;
    }
}

void shuffle_deck(Deck *deck) {
    int i, j;
    Card temp;
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void deal_hand(Deck *deck, Hand *hand, int num_cards) {
    int i;
    for (i = 0; i < num_cards; i++) {
        hand->cards[i] = deck->cards[deck->num_cards - 1];
        deck->num_cards--;
        hand->num_cards++;
    }
}

void print_hand(Hand *hand) {
    int i;
    for (i = 0; i < hand->num_cards; i++) {
        printf("%s of %s\n", get_rank_name(hand->cards[i].rank), get_suit_name(hand->cards[i].suit));
    }
}

int get_rank_name(int rank) {
    switch (rank) {
        case 1:
            return "Ace";
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        default:
            return "Ten";
    }
}

int get_suit_name(int suit) {
    switch (suit) {
        case 0:
            return "Hearts";
        case 1:
            return "Diamonds";
        case 2:
            return "Clubs";
        case 3:
            return "Spades";
        default:
            return "Joker";
    }
}

int main() {
    srand(time(NULL));

    Deck deck;
    Hand player1_hand;
    Hand player2_hand;

    create_deck(&deck);
    shuffle_deck(&deck);

    deal_hand(&deck, &player1_hand, NUM_CARDS / 2);
    deal_hand(&deck, &player2_hand, NUM_CARDS / 2);

    printf("Player 1's hand:\n");
    print_hand(&player1_hand);
    printf("\nPlayer 2's hand:\n");
    print_hand(&player2_hand);

    return 0;
}