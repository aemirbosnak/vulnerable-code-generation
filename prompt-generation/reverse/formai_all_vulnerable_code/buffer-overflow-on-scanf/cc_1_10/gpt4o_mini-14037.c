//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 5
#define TOTAL_CARDS 52

typedef struct {
    char rank[3]; // 2-10, J, Q, K, A
    char suit;    // H, D, C, S
} Card;

typedef struct {
    Card hand[CARDS_IN_HAND];
    char name[20];
} Player;

Card deck[TOTAL_CARDS];
int deckIndex = 0;

void initializeDeck() {
    const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const char suits[] = {'H', 'D', 'C', 'S'};

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(deck[i * 4 + j].rank, ranks[i]);
            deck[i * 4 + j].suit = suits[j];
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < TOTAL_CARDS; i++) {
        int j = rand() % TOTAL_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        for (int j = 0; j < CARDS_IN_HAND; j++) {
            players[i].hand[j] = deck[deckIndex++];
        }
    }
}

void printCard(Card card) {
    printf("%s%c ", card.rank, card.suit);
}

void printPlayerHand(Player player) {
    printf("%s's Hand: ", player.name);
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        printCard(player.hand[i]);
    }
    printf("\n");
}

void initPlayer(Player *player, const char *name) {
    strcpy(player->name, name);
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        player->hand[i].rank[0] = '\0'; // Initializing hand with empty cards
    }
}

void playPokerGame() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Welcome to the Galactic Poker Table!\n");
    printf("How many players? (Max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    if (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players! Exiting.\n");
        return;
    }

    // Initialize players
    for (int i = 0; i < playerCount; i++) {
        char playerName[20];
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", playerName);
        initPlayer(&players[i], playerName);
    }

    // Initialize and shuffle the deck
    initializeDeck();
    shuffleDeck();

    // Deal the cards
    dealCards(players, playerCount);

    // Display each player's hand
    for (int i = 0; i < playerCount; i++) {
        printPlayerHand(players[i]);
    }
}

int main() {
    srand(time(0)); // Seed random number generator
    playPokerGame();
    return 0;
}