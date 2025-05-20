//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 5
#define DECK_SIZE 52

typedef struct {
    int value; // 1-13 for Ace to King
    char suit; // 'H', 'D', 'C', 'S'
} Card;

typedef struct {
    char name[30];
    Card hand[CARDS_IN_HAND];
    int score;
} Player;

Card deck[DECK_SIZE];
int deckIndex = 0;

void initializeDeck() {
    char suits[] = {'H', 'D', 'C', 'S'};
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            deck[deckIndex].value = j;
            deck[deckIndex].suit = suits[i];
            deckIndex++;
        }
    }
    deckIndex = DECK_SIZE; // Reset index to the end of the deck
}

void shuffleDeck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards(Player *player) {
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        player->hand[i] = deck[--deckIndex];
    }
}

void displayPlayerHand(Player *player) {
    printf("%s's hand:\n", player->name);
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        printf("Card %d: %d%c  ", i + 1, player->hand[i].value, player->hand[i].suit);
    }
    printf("\n");
}

void calculateScore(Player *player) {
    player->score = 0;
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        player->score += player->hand[i].value;
    }
}

void displayScores(Player players[], int numPlayers) {
    printf("Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
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
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }
    
    initializeDeck();
    shuffleDeck();
    
    // Deal cards to players
    for (int i = 0; i < numPlayers; i++) {
        dealCards(&players[i]);
        calculateScore(&players[i]);
        displayPlayerHand(&players[i]);
    }

    // Display scores
    displayScores(players, numPlayers);
    
    // Determine winner
    int highestScore = 0;
    char winner[30];
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            strcpy(winner, players[i].name);
        }
    }
    
    printf("The winner is %s with a score of %d!\n", winner, highestScore);
    return 0;
}