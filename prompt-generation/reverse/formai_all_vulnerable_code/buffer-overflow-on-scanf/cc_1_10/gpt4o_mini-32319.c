//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_CARDS_PER_PLAYER 10
#define TOTAL_CARDS 52

typedef struct {
    char suit;
    char rank;
} Card;

typedef struct {
    char name[20];
    Card hand[MAX_CARDS_PER_PLAYER];
    int cardCount;
} Player;

Card deck[TOTAL_CARDS];
int topCardIndex = 0;

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
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < TOTAL_CARDS; i++) {
        int randomIndex = rand() % TOTAL_CARDS;
        Card temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

void dealCards(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        players[i].cardCount = 0;
        for (int j = 0; j < MAX_CARDS_PER_PLAYER; j++) {
            if (topCardIndex < TOTAL_CARDS) {
                players[i].hand[j] = deck[topCardIndex++];
                players[i].cardCount++;
            }
        }
    }
}

void printPlayerHand(Player player) {
    printf("%s's Hand: ", player.name);
    for (int i = 0; i < player.cardCount; i++) {
        printf("%c%c ", player.hand[i].rank, player.hand[i].suit);
    }
    printf("\n");
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Welcome to the Curious Card Game!\n");
    printf("How many players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);

    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    initializeDeck();
    shuffleDeck();

    dealCards(players, playerCount);

    printf("\nDealt Cards:\n");
    for (int i = 0; i < playerCount; i++) {
        printPlayerHand(players[i]);
    }

    printf("Let's start the game! Each player will now draw a card...\n");
    for (int i = 0; i < playerCount; i++) {
        if (players[i].cardCount > 0) {
            Card drawnCard = players[i].hand[--(players[i].cardCount)];
            printf("%s draws a %c%c.\n", players[i].name, drawnCard.rank, drawnCard.suit);
        } else {
            printf("%s has no cards left to draw.\n", players[i].name);
        }
    }

    printf("Game Over! Thank you for playing the Curious Card Game!\n");

    return 0;
}