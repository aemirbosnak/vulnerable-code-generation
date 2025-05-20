//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 5
#define DECK_SIZE 52

typedef struct {
    char suit;
    char value;
} Card;

typedef struct {
    Card hand[CARDS_IN_HAND];
    char name[30];
} Player;

Card deck[DECK_SIZE];

void initializeDeck() {
    char suits[] = {'H', 'D', 'S', 'C'};
    char values[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    int index = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[index].suit = suits[i];
            deck[index].value = values[j];
            index++;
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < CARDS_IN_HAND; j++) {
            players[i].hand[j] = deck[i * CARDS_IN_HAND + j];
        }
    }
}

void printCard(Card card) {
    printf("%c%c ", card.value, card.suit);
}

void printPlayerHand(Player player) {
    printf("%s's Hand: ", player.name);
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        printCard(player.hand[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Poker Game!\n");
    printf("Enter number of players (1-4): ");
    scanf("%d", &numPlayers);

    while (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players! Please enter between 1 and 4: ");
        scanf("%d", &numPlayers);
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    initializeDeck();
    shuffleDeck();
    dealCards(players, numPlayers);

    printf("\nDealt Cards:\n");
    for (int i = 0; i < numPlayers; i++) {
        printPlayerHand(players[i]);
    }

    // Game continuation logic can be added here...

    printf("\nThanks for playing!\n");
    return 0;
}