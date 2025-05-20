//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_PER_PLAYER 5
#define DECK_SIZE 52

typedef struct {
    char rank[3]; // 2-10, J, Q, K, A
    char suit[9]; // Hearts, Diamonds, Clubs, Spades
} Card;

Card deck[DECK_SIZE];
Card players[MAX_PLAYERS][CARDS_PER_PLAYER];

const char *ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
const char *suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

void initializeDeck() {
    int index = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(deck[index].rank, ranks[i]);
            strcpy(deck[index].suit, suits[j]);
            index++;
        }
    }
}

void shuffleDeck() {
    srand(time(0));
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards(int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < CARDS_PER_PLAYER; j++) {
            players[i][j] = deck[i * CARDS_PER_PLAYER + j];
        }
    }
}

void displayHands(int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d's hand:\n", i + 1);
        for (int j = 0; j < CARDS_PER_PLAYER; j++) {
            printf("%s of %s\n", players[i][j].rank, players[i][j].suit);
        }
        printf("\n");
    }
}

void playerTurn(int playerIndex) {
    printf("Player %d's turn:\n", playerIndex + 1);
    // For simplicity, we're just letting player take a card
    printf("Press 'Enter' to draw a card...\n");
    getchar();  // Wait for user to press Enter
    printf("Player %d is drawing a card...\n", playerIndex + 1);
    // Simulate drawing a card (for demo purposes)
    // In real game, you'd want to implement a more complex logic
}

int main() {
    int numPlayers;

    printf("Welcome to the Poker Game Simulator!\n");
    printf("Enter the number of players (2-4): ");
    scanf("%d", &numPlayers);

    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players! Exiting the game.\n");
        return 1;
    }

    initializeDeck();
    shuffleDeck();
    dealCards(numPlayers);
    displayHands(numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        playerTurn(i);
    }

    printf("Game Over! Thanks for playing!\n");

    return 0;
}