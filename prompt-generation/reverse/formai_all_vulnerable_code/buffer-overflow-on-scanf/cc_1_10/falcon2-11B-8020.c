//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_DECK_SIZE 52

// Global variables
int players[MAX_PLAYERS];
int num_players = 0;
int num_rounds = 0;
int pot = 0;
int community_cards[MAX_DECK_SIZE];

void initialize_game() {
    srand(time(NULL));
    
    // Initialize players and set their initial bets
    players[0] = 100;
    players[1] = 100;
    players[2] = 100;
    players[3] = 100;
    num_players = 4;
    pot = 0;
}

void deal_cards() {
    // Deal 2 cards to each player
    int i;
    for (i = 0; i < num_players; i++) {
        int card1, card2;
        card1 = rand() % MAX_DECK_SIZE;
        card2 = rand() % MAX_DECK_SIZE;
        community_cards[card1] = 'C';
        community_cards[card2] = 'C';
        players[i] -= 2;
        printf("%d has cards %d and %d\n", i+1, card1, card2);
    }
}

void show_cards() {
    // Show the community cards
    printf("Community cards: ");
    for (int i = 0; i < MAX_DECK_SIZE; i++) {
        printf("%d ", community_cards[i]);
    }
    printf("\n");
}

void check_for_winners() {
    int i;
    for (i = 0; i < num_players; i++) {
        int hand_value = calculate_hand_value(players[i]);
        if (hand_value == 21) {
            printf("%d has Blackjack!\n", i+1);
            return;
        }
    }
}

int calculate_hand_value(int hand) {
    // Calculate the value of the player's hand
    int value = 0;
    if (hand == 0) {
        return 21;
    }
    else if (hand > 10) {
        value = 10;
    }
    else {
        value = hand;
    }
    return value;
}

void play_round() {
    // Start a new round
    printf("Round %d\n", num_rounds+1);
    printf("Current pot: %d\n", pot);
    printf("Community cards: ");
    for (int i = 0; i < MAX_DECK_SIZE; i++) {
        printf("%d ", community_cards[i]);
    }
    printf("\n");
    
    // Deal 1 more card to each player
    for (int i = 0; i < num_players; i++) {
        int card;
        card = rand() % MAX_DECK_SIZE;
        community_cards[card] = 'C';
        players[i] -= 1;
        printf("%d draws card %d\n", i+1, card);
    }
    
    // Check for winners
    check_for_winners();
    
    // Increment the number of rounds
    num_rounds++;
}

int main() {
    int choice;
    int bet;
    
    printf("Welcome to C Poker!\n");
    initialize_game();
    
    while (num_rounds < 5) {
        // Prompt the player to make a bet
        printf("Place your bet:\n");
        scanf("%d", &bet);
        
        // Check if the bet is valid
        if (bet > players[num_players-1] || bet < 0) {
            printf("Invalid bet!\n");
        }
        else {
            // Add the bet to the pot
            pot += bet;
            printf("Current pot: %d\n", pot);
            
            // Deal the cards
            deal_cards();
            
            // Show the cards
            show_cards();
            
            // Play the round
            play_round();
            
            // Decrement the number of players
            num_players--;
            
            // Check for winners
            check_for_winners();
        }
    }
    
    printf("Game over!\n");
    
    return 0;
}