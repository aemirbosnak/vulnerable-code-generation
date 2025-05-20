//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define NUM_CARDS 5
#define DECK_SIZE 52

typedef struct {
    char suit;
    int rank; // 1-13 for Ace to King
} Card;

typedef struct {
    char name[30];
    Card hand[NUM_CARDS];
    int chips;
    int is_active;
    int current_bet;
} Player;

Card deck[DECK_SIZE];
Player players[MAX_PLAYERS];
int total_players, pot = 0;

void initialize_deck() {
    char suits[] = {'H', 'D', 'C', 'S'};
    int index = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            deck[index].suit = suits[i];
            deck[index].rank = j;
            index++;
        }
    }

    // Shuffle the deck
    for (int i = 0; i < DECK_SIZE; i++) {
        int rand_index = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[rand_index];
        deck[rand_index] = temp;
    }
}

void print_card(Card card) {
    char *ranks[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    printf("%s%c ", ranks[card.rank], card.suit);
}

void setup_players() {
    for (int i = 0; i < total_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].chips = 100; // Each player starts with 100 chips
        players[i].is_active = 1;
        players[i].current_bet = 0;
    }
}

void deal_cards() {
    for (int i = 0; i < total_players; i++) {
        for (int j = 0; j < NUM_CARDS; j++) {
            players[i].hand[j] = deck[i * NUM_CARDS + j];
        }
    }
}

void print_hands() {
    for (int i = 0; i < total_players; i++) {
        if (players[i].is_active) {
            printf("%s's hand: ", players[i].name);
            for (int j = 0; j < NUM_CARDS; j++) {
                print_card(players[i].hand[j]);
            }
            printf("\n");
        }
    }
}

int get_highest_card(Player *player) {
    int highest = 0;
    for (int i = 0; i < NUM_CARDS; i++) {
        if (player->hand[i].rank > highest) {
            highest = player->hand[i].rank;
        }
    }
    return highest;
}

void betting_round() {
    int current_bet = 0;
    for (int i = 0; i < total_players; i++) {
        if (players[i].is_active) {
            printf("%s, you have %d chips. Current bet: ", players[i].name, players[i].chips);
            scanf("%d", &players[i].current_bet);
            if (players[i].current_bet > players[i].chips) {
                printf("Not enough chips! Setting your bet to all-in (%d).\n", players[i].chips);
                players[i].current_bet = players[i].chips;
            }
            pot += players[i].current_bet;
            players[i].chips -= players[i].current_bet;
            current_bet = current_bet > players[i].current_bet ? current_bet : players[i].current_bet;
        }
    }
}

void determine_winner() {
    int max_card = 0;
    Player *winner = NULL;

    for (int i = 0; i < total_players; i++) {
        if (players[i].is_active) {
            int high_card = get_highest_card(&players[i]);
            if (high_card > max_card) {
                max_card = high_card;
                winner = &players[i];
            }
        }
    }

    if (winner) {
        printf("The winner is %s with the highest card %d! They win the pot of %d chips.\n",
               winner->name, max_card, pot);
        winner->chips += pot;
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Multiplayer Poker Game!\n");
    printf("Enter number of players (Max %d): ", MAX_PLAYERS);
    scanf("%d", &total_players);
    if (total_players < 2 || total_players > MAX_PLAYERS) {
        printf("Invalid number of players. Must be between 2 and %d.\n", MAX_PLAYERS);
        return 1;
    }

    initialize_deck();
    setup_players();

    for (int round = 1; round <= 3; round++) {
        printf("\n--- Round %d ---\n", round);
        deal_cards();
        print_hands();
        betting_round();
        determine_winner();
        pot = 0; // Reset pot for next round
    }

    printf("Game over! Final chip counts:\n");
    for (int i = 0; i < total_players; i++) {
        printf("%s has %d chips.\n", players[i].name, players[i].chips);
    }

    return 0;
}