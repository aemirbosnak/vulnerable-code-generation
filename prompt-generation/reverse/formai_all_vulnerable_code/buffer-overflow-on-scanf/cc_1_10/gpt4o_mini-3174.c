//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 5
#define DECK_SIZE 52

typedef struct {
    char suit;
    char rank;
} Card;

typedef struct {
    Card hand[CARDS_IN_HAND];
    int player_id;
} Player;

Card deck[DECK_SIZE];
int top_card_index = 0;

void initialize_deck() {
    char suits[] = {'H', 'D', 'C', 'S'};
    char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[i * 13 + j].suit = suits[i];
            deck[i * 13 + j].rank = ranks[j];
        }
    }
    
    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
    
    top_card_index = 0;
}

Card deal_card() {
    return deck[top_card_index++];
}

void print_card(Card card) {
    printf("%c%c ", card.rank, card.suit);
}

void print_player_hand(Player player) {
    printf("Player %d's Hand: ", player.player_id);
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        print_card(player.hand[i]);
    }
    printf("\n");
}

void setup_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        players[i].player_id = i + 1;
        for (int j = 0; j < CARDS_IN_HAND; j++) {
            players[i].hand[j] = deal_card();
        }
        print_player_hand(players[i]);
    }
}

int main() {
    int num_players;
    Player players[MAX_PLAYERS];

    printf("Enter number of players (2-4): ");
    scanf("%d", &num_players);

    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    initialize_deck();
    setup_players(players, num_players);

    printf("Game Over: All players have been dealt their cards!\n");
    return 0;
}