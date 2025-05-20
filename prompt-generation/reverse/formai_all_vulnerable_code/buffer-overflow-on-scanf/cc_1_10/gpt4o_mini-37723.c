//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 10
#define MAX_CARDS 5

typedef struct {
    char name[30];
    int score;
    int cards[MAX_CARDS];
    int cardCount;
} Player;

void initializePlayers(Player players[], int numPlayers);
void dealCards(Player *player);
void displayPlayerStatus(Player players[], int numPlayers);
bool isBluff(Player *bluffer, int *deck, int cardRequested);
void playTurn(Player *currentPlayer, Player players[], int numPlayers);
void updateScores(Player players[], int numPlayers, bool successfulBluff);
void displayFinalScores(Player players[], int numPlayers);

int main() {
    int numPlayers;
    Player players[MAX_PLAYERS];
    srand(time(NULL));

    printf("Welcome to Bluff Under the Stars!\n");
    printf("Enter the number of players (2-4): ");
    scanf("%d", &numPlayers);
    
    if(numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        fprintf(stderr, "Invalid number of players!\n");
        return 1;
    }

    initializePlayers(players, numPlayers);

    for (int turn = 0; turn < MAX_TURNS; turn++) {
        for (int i = 0; i < numPlayers; i++) {
            playTurn(&players[i], players, numPlayers);
        }
    }

    displayFinalScores(players, numPlayers);
    return 0;
}

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of Player %d: ", (i + 1));
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].cardCount = 0;
        dealCards(&players[i]);
    }
}

void dealCards(Player *player) {
    for (int i = 0; i < MAX_CARDS; i++) {
        player->cards[i] = rand() % 10; // Cards numbered 0-9
        player->cardCount++;
    }
}

void displayPlayerStatus(Player players[], int numPlayers) {
    printf("\nPlayer Status:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s has a score of %d and holds cards: ", players[i].name, players[i].score);
        for (int j = 0; j < players[i].cardCount; j++) {
            printf("%d ", players[i].cards[j]);
        }
        printf("\n");
    }
}

bool isBluff(Player *bluffer, int *deck, int cardRequested) {
    // Simple bluff check based on card presence
    for (int i = 0; i < bluffer->cardCount; i++) {
        if (bluffer->cards[i] == cardRequested) {
            return false; // Bluff unsuccessful
        }
    }
    return true; // Bluff successful
}

void playTurn(Player *currentPlayer, Player players[], int numPlayers) {
    int cardRequested;
    char bluffChoice;
    printf("\n%s's turn:\n", currentPlayer->name);
    
    // Display current status
    displayPlayerStatus(players, numPlayers);
    
    printf("Request a card (0-9): ");
    scanf("%d", &cardRequested);
    
    printf("Do you want to bluff? (y/n): ");
    scanf(" %c", &bluffChoice);

    bool success = !bluffChoice || !isBluff(currentPlayer, currentPlayer->cards, cardRequested);

    if (success) {
        currentPlayer->score += cardRequested;
        printf("%s successfully requested %d!\n", currentPlayer->name, cardRequested);
    } else {
        currentPlayer->score -= cardRequested;
        printf("%s failed to bluff about %d!\n", currentPlayer->name, cardRequested);
    }

    updateScores(players, numPlayers, success);
}

void updateScores(Player players[], int numPlayers, bool successfulBluff) {
    for (int i = 0; i < numPlayers; i++) {
        // Update based on bluffing success
        players[i].score += successfulBluff ? 1 : -1;
    }
}

void displayFinalScores(Player players[], int numPlayers) {
    printf("\nFinal Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}