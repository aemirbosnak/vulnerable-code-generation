//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define DECK_SIZE 52
#define CARDS_PER_HAND 5

typedef struct {
    char suit[10];
    char rank[3];
} Card;

typedef struct {
    Card hand[CARDS_PER_HAND];
} Player;

Card deck[DECK_SIZE];
Player players[MAX_PLAYERS];
int num_players;

void initialize_deck() {
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int index = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(deck[index].suit, suits[i]);
            strcpy(deck[index].rank, ranks[j]);
            index++;
        }
    }
}

void shuffle_deck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        int random_index = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[random_index];
        deck[random_index] = temp;
    }
}

void deal_hands() {
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < CARDS_PER_HAND; j++) {
            players[i].hand[j] = deck[i * CARDS_PER_HAND + j];
        }
    }
}

void print_hand(Player player, int player_number) {
    printf("Player %d's Hand:\n", player_number + 1);
    for (int i = 0; i < CARDS_PER_HAND; i++) {
        printf("%s of %s\n", player.hand[i].rank, player.hand[i].suit);
    }
    printf("\n");
}

void determine_winner() {
    // In a complete implementation you would rank hands here
    // For simplicity, we will just declare Player 1 as the winner
    printf("The winner is Player 1!\n");
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to the Poker Game!\n");
    printf("Enter the number of players (2-4): ");
    scanf("%d", &num_players);
    
    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the game and enter a valid number.\n");
        return 1;
    }

    initialize_deck();
    shuffle_deck();
    deal_hands();

    for (int i = 0; i < num_players; i++) {
        print_hand(players[i], i);
    }
    
    determine_winner();

    return 0;
}