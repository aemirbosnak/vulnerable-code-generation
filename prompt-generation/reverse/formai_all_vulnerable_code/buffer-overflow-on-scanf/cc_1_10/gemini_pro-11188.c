//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 104

typedef struct {
    int value;
    char suit;
} Card;

typedef struct {
    Card cards[MAX_CARDS];
    int num_cards;
} Hand;

typedef struct {
    int player_id;
    Hand hand;
} Player;

void shuffle(Card *deck) {
    int i, j;
    Card temp;
    for (i = 0; i < MAX_CARDS; i++) {
        j = rand() % MAX_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(Card *deck, Player *players, int num_players) {
    int i, j;
    for (i = 0; i < num_players; i++) {
        for (j = 0; j < 13; j++) {
            players[i].hand.cards[j] = deck[i * 13 + j];
        }
        players[i].hand.num_cards = 13;
    }
}

void print_hand(Hand *hand) {
    int i;
    for (i = 0; i < hand->num_cards; i++) {
        printf("%c%d ", hand->cards[i].suit, hand->cards[i].value);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Card deck[MAX_CARDS];
    Player players[MAX_PLAYERS];
    int num_players;

    printf("Enter the number of players (2-4): ");
    scanf("%d", &num_players);

    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        deck[i].value = (i % 13) + 1;
        deck[i].suit = "SHDC"[i / 13];
    }

    shuffle(deck);
    deal(deck, players, num_players);

    for (i = 0; i < num_players; i++) {
        printf("Player %d's hand:\n", i + 1);
        print_hand(&players[i].hand);
    }

    return 0;
}