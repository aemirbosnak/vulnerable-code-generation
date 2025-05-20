//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 2
#define DECK_SIZE 52
#define MAX_BET 1000

typedef struct {
    char name[20];
    int chips;
} Player;

typedef struct {
    char value[3];
    char suit[10];
} Card;

Card deck[DECK_SIZE];
Card playerHands[MAX_PLAYERS][CARDS_IN_HAND];
int currentBet;
int numberOfPlayers;
Player players[MAX_PLAYERS];

void initializeDeck() {
    const char *values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int index = 0;

    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            snprintf(deck[index].value, sizeof(deck[index].value), "%s", values[i]);
            snprintf(deck[index].suit, sizeof(deck[index].suit), "%s", suits[j]);
            index++;
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < DECK_SIZE; ++i) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealHands() {
    for (int i = 0; i < numberOfPlayers; ++i) {
        for (int j = 0; j < CARDS_IN_HAND; ++j) {
            playerHands[i][j] = deck[i * CARDS_IN_HAND + j];
        }
    }
}

void displayHands() {
    for (int i = 0; i < numberOfPlayers; ++i) {
        printf("Player %s has: ", players[i].name);
        for (int j = 0; j < CARDS_IN_HAND; ++j) {
            printf("%s of %s, ", playerHands[i][j].value, playerHands[i][j].suit);
        }
        printf("\n");
    }
}

int playerBet(int playerIndex) {
    int bet;
    printf("%s, you have %d chips. Enter your bet (0 to fold): ", players[playerIndex].name, players[playerIndex].chips);
    scanf("%d", &bet);
    
    if (bet < 0 || bet > players[playerIndex].chips) {
        printf("Invalid bet, please try again.\n");
        return playerBet(playerIndex);
    }
    
    if (bet > 0) {
        players[playerIndex].chips -= bet;
        currentBet += bet;
    }
    
    return bet;
}

void gameLoop() {
    int round = 1;

    while (1) {
        printf("Round %d\n", round++);
        currentBet = 0;

        for (int i = 0; i < numberOfPlayers; ++i) {
            if (players[i].chips > 0) {
                playerBet(i);
            } else {
                printf("%s is all in!\n", players[i].name);
            }
        }

        printf("Current pot: %d\n", currentBet);
        
        char action;
        printf("Continue to next round? (y/n): ");
        scanf(" %c", &action);
        
        if (action != 'y') {
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Paranoid Poker Game!\n");

    printf("Enter number of players (2-4): ");
    scanf("%d", &numberOfPlayers);

    if (numberOfPlayers < 2 || numberOfPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    for (int i = 0; i < numberOfPlayers; ++i) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].chips = MAX_BET;
    }

    initializeDeck();
    shuffleDeck();
    dealHands();
    displayHands();
    gameLoop();

    // Show final chip counts
    printf("Final chip counts:\n");
    for (int i = 0; i < numberOfPlayers; ++i) {
        printf("%s has %d chips.\n", players[i].name, players[i].chips);
    }

    return 0;
}