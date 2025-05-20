//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct {
    char suit[10];
    char rank[3];
} Card;

typedef struct {
    char name[30];
    Card hand[HAND_SIZE];
    int chips;
} Player;

Card deck[DECK_SIZE];
int deckIndex = 0;

void initDeck() {
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(deck[DECK_SIZE - (i * 13 + j) - 1].suit, suits[i]);
            strcpy(deck[DECK_SIZE - (i * 13 + j) - 1].rank, ranks[j]);
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = deck[deckIndex++];
        }
    }
}

void printCard(const Card *card) {
    printf("%s of %s ", card->rank, card->suit);
}

void printHand(const Player *player) {
    printf("%s's hand: ", player->name);
    for (int i = 0; i < HAND_SIZE; i++) {
        printCard(&player->hand[i]);
    }
    printf("\n");
}

void initPlayers(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].chips = 100;  // Start with 100 chips
    }
}

void printPlayerStatus(const Player *players, int numPlayers) {
    printf("\nPlayer status:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d chips\n", players[i].name, players[i].chips);
    }
}

void cleanUp() {
    printf("\nIn the dusty remnants of society, only ashes of yesterday's glories remain. Remember this:\n");
    printf("In the end, it was just a game. But even a game can hold meaning in the apocalypse.\n");
}

int main() {
    srand(time(NULL));
    
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Post-Apocalyptic Poker Game!\n");
    printf("How many players (1 - 4): ");
    scanf("%d", &numPlayers);
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    initDeck();
    shuffleDeck();
    dealCards(players, numPlayers);
    initPlayers(players, numPlayers);
    printPlayerStatus(players, numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printHand(&players[i]);
    }
    
    cleanUp();

    return 0;
}