//Code Llama-13B DATASET v1.0 Category: Poker Game ; Style: shocked
/*
 * Unique C Poker Game Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 4
#define MAX_HAND_SIZE 5

// Card structure
typedef struct {
    int rank;
    int suit;
} Card;

// Player structure
typedef struct {
    char name[20];
    int chips;
    Card hand[MAX_HAND_SIZE];
} Player;

// Deck structure
typedef struct {
    Card cards[NUM_CARDS];
    int num_cards;
} Deck;

// Function prototypes
void shuffle(Deck *deck);
void deal_cards(Deck *deck, Player *players, int num_players);
void print_hands(Player *players, int num_players);

int main() {
    // Initialize players
    Player players[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].chips = 100;
        for (int j = 0; j < MAX_HAND_SIZE; j++) {
            players[i].hand[j].rank = -1;
            players[i].hand[j].suit = -1;
        }
    }

    // Shuffle the deck
    Deck deck;
    for (int i = 0; i < NUM_CARDS; i++) {
        deck.cards[i].rank = i % 13 + 1;
        deck.cards[i].suit = i / 13;
    }
    deck.num_cards = NUM_CARDS;
    shuffle(&deck);

    // Deal the cards
    deal_cards(&deck, players, NUM_PLAYERS);

    // Print the hands
    print_hands(players, NUM_PLAYERS);

    return 0;
}

void shuffle(Deck *deck) {
    srand(time(NULL));
    for (int i = 0; i < deck->num_cards; i++) {
        int rand_idx = rand() % deck->num_cards;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[rand_idx];
        deck->cards[rand_idx] = temp;
    }
}

void deal_cards(Deck *deck, Player *players, int num_players) {
    for (int i = 0; i < deck->num_cards; i++) {
        int player_idx = i % num_players;
        int card_idx = i / num_players;
        players[player_idx].hand[card_idx] = deck->cards[i];
    }
}

void print_hands(Player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Player %d's hand: ", i + 1);
        for (int j = 0; j < MAX_HAND_SIZE; j++) {
            if (players[i].hand[j].rank != -1) {
                printf("%d of %d, ", players[i].hand[j].rank, players[i].hand[j].suit);
            }
        }
        printf("\n");
    }
}