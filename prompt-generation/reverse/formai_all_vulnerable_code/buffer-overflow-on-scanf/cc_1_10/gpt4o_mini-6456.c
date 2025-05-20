//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define HAND_SIZE 5
#define DECK_SIZE 52

typedef struct {
    char suit;
    char rank;
} Card;

typedef struct {
    Card hand[HAND_SIZE];
    int handSize;
    char name[30];
} Player;

Card deck[DECK_SIZE];
int deckIndex = 0;

void initializeDeck() {
    char suits[] = {'H', 'D', 'C', 'S'};
    char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    int index = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[index].suit = suits[i];
            deck[index].rank = ranks[j];
            index++;
        }
    }

    // Shuffle the deck
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
    
    deckIndex = 0;
}

Card drawCard() {
    return deck[deckIndex++];
}

void initPlayer(Player *player, const char *name) {
    strncpy(player->name, name, sizeof(player->name));
    player->handSize = 0;
}

void addCardToPlayer(Player *player, Card card) {
    if (player->handSize < HAND_SIZE) {
        player->hand[player->handSize++] = card;
    }
}

void displayPlayerHand(Player *player) {
    printf("%s's Hand: ", player->name);
    for (int i = 0; i < player->handSize; i++) {
        printf("%c%c ", player->hand[i].rank, player->hand[i].suit);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Enter number of players (2-4): ");
    scanf("%d", &numPlayers);
    
    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    for (int i = 0; i < numPlayers; i++) {
        char name[30];
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", name);
        initPlayer(&players[i], name);
    }

    initializeDeck();

    // Play rounds
    for (int round = 0; round < HAND_SIZE; round++) {
        for (int i = 0; i < numPlayers; i++) {
            printf("\n%s's turn:\n", players[i].name);
            Card card = drawCard();
            addCardToPlayer(&players[i], card);
            displayPlayerHand(&players[i]);
        }
    }

    printf("\nFinal Hands:\n");
    for (int i = 0; i < numPlayers; i++) {
        displayPlayerHand(&players[i]);
    }

    return 0;
}