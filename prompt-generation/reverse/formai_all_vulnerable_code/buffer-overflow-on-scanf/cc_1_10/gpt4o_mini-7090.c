//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 2
#define NUM_BETS 5

typedef struct {
    char suit;
    char value;
} Card;

typedef struct {
    Card hand[5];
    int bet;
} Player;

Card deck[NUM_CARDS];
Player players[NUM_PLAYERS];

void initDeck() {
    char suits[] = {'H', 'D', 'C', 'S'};
    char values[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[index++] = (Card){suits[i], values[j]};
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < NUM_CARDS; i++) {
        int r = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < 5; j++) {
            players[i].hand[j] = deck[i * 5 + j];
            players[i].bet = 0;
        }
    }
}

void displayHand(Player player, int playerNum) {
    printf("Player %d's hand: ", playerNum+1);
    for (int i = 0; i < 5; i++) {
        printf("%c%c ", player.hand[i].value, player.hand[i].suit);
    }
    printf("\n");
}

void placeBets() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d, enter your bet: ", i + 1);
        scanf("%d", &players[i].bet);
        // paranoia check: only allow a bet between 1 and 100
        if (players[i].bet < 1 || players[i].bet > 100) {
            printf("That's suspicious! Bets must be between 1 and 100.\n");
            players[i].bet = 0; // Resetting the bet
        }
    }
}

void revealWinner() {
    // Basic logic to reveal the winner based on the first card, just for this example
    int winner = 0;
    if (players[1].hand[0].value > players[0].hand[0].value) {
        winner = 1;
    }
    printf("Player %d wins with a bet of %d!\n", winner + 1, players[winner].bet);
}

int main() {
    srand(time(0));
    initDeck();
    shuffleDeck();
    dealCards();

    for (int i = 0; i < NUM_PLAYERS; i++) {
        displayHand(players[i], i);
    }

    placeBets();
    revealWinner();

    return 0;
}