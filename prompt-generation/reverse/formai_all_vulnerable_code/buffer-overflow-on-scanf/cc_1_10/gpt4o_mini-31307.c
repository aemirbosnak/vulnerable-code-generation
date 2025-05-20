//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 52
#define CARDS_PER_PLAYER 5

typedef struct {
    char suit;
    char value[3];
} Card;

typedef struct {
    char name[50];
    Card hand[CARDS_PER_PLAYER];
    int score;
} Player;

void initializeDeck(Card deck[]) {
    char suits[] = {'H', 'D', 'C', 'S'};
    char values[][3] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[index].suit = suits[i];
            snprintf(deck[index].value, sizeof(deck[index].value), "%s", values[j]);
            index++;
        }
    }
}

void shuffleDeck(Card deck[]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        int r = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards(Card deck[], Player players[], int playerCount) {
    int index = 0;
    for (int i = 0; i < playerCount; i++) {
        for (int j = 0; j < CARDS_PER_PLAYER; j++) {
            players[i].hand[j] = deck[index++];
        }
    }
}

void printPlayerHand(Player player) {
    printf("%s's hand:\n", player.name);
    for (int i = 0; i < CARDS_PER_PLAYER; i++) {
        printf("Card %d: %s%c\n", i + 1, player.hand[i].value, player.hand[i].suit);
    }
}

void calculateScores(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        players[i].score = 0;
        for (int j = 0; j < CARDS_PER_PLAYER; j++) {
            if (players[i].hand[j].value[0] >= '2' && players[i].hand[j].value[0] <= '9') {
                players[i].score += (players[i].hand[j].value[0] - '0');
            } else if (players[i].hand[j].value[0] == '1' || players[i].hand[j].value[0] == 'J' || 
                       players[i].hand[j].value[0] == 'Q' || players[i].hand[j].value[0] == 'K') {
                players[i].score += 10;
            } else if (players[i].hand[j].value[0] == 'A') {
                players[i].score += 11; // Assuming Ace is high
            }
        }
    }
}

void findWinner(Player players[], int playerCount) {
    int maxScore = 0;
    int winnerIndex = -1;
    
    for (int i = 0; i < playerCount; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            winnerIndex = i;
        }
    }
    
    printf("The winner is %s with a score of %d!\n", players[winnerIndex].name, players[winnerIndex].score);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    Card deck[MAX_CARDS];
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Welcome to the Card Game!\n");
    printf("Enter number of players (2 to %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    if (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }
    
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    initializeDeck(deck);
    shuffleDeck(deck);
    dealCards(deck, players, playerCount);
    
    for (int i = 0; i < playerCount; i++) {
        printPlayerHand(players[i]);
    }
    
    calculateScores(players, playerCount);
    findWinner(players, playerCount);
    
    return 0;
}