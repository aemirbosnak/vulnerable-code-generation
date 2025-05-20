//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 5
#define DECK_SIZE 52

typedef struct {
    char suit[10];
    char rank[3];
} Card;

typedef struct {
    char name[20];
    Card hand[CARDS_IN_HAND];
    int bet;
} Player;

Card deck[DECK_SIZE];
int deckIndex = 0;

void createDeck() {
    strcpy(deck[0].suit, "Hearts");
    strcpy(deck[1].suit, "Diamonds");
    strcpy(deck[2].suit, "Clubs");
    strcpy(deck[3].suit, "Spades");
    
    const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[i * 13 + j].rank[0] = '\0';
            strcat(deck[i * 13 + j].rank, ranks[j]);
        }
    }
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Player *players, int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        for (int j = 0; j < CARDS_IN_HAND; j++) {
            players[i].hand[j] = deck[deckIndex++];
        }
    }
}

void printHand(Player player) {
    printf("%s's hand:\n", player.name);
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        printf("%s of %s\n", player.hand[i].rank, player.hand[i].suit);
    }
}

void placeBets(Player *players, int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("%s, place your bet: ", players[i].name);
        scanf("%d", &players[i].bet);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Welcome to the Ada Lovelace Poker Game!\n");
    
    do {
        printf("Enter number of players (2-4): ");
        scanf("%d", &playerCount);
    } while (playerCount < 2 || playerCount > MAX_PLAYERS);

    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].bet = 0; // Initialize bets
    }

    createDeck();
    shuffleDeck();
    dealCards(players, playerCount);

    printf("\nAll cards dealt!\n");
    for (int i = 0; i < playerCount; i++) {
        printHand(players[i]);
    }

    placeBets(players, playerCount);
    
    // A simple demonstration of showing bets
    printf("\nBets placed:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s has placed a bet of %d.\n", players[i].name, players[i].bet);
    }

    printf("\nThank you for playing!\n");
    return 0;
}