//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define CARDS_PER_HAND 5
#define DECK_SIZE 52

typedef struct {
    char *rank;
    char *suit;
} Card;

typedef struct {
    char *name;
    Card hand[CARDS_PER_HAND];
    int score;
} Player;

Card deck[DECK_SIZE];
int topCardIndex = 0;

void initializeDeck() {
    char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[i * 4 + j].rank = ranks[i];
            deck[i * 4 + j].suit = suits[j];
        }
    }
    
    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Player *players, int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        for (int j = 0; j < CARDS_PER_HAND; j++) {
            players[i].hand[j] = deck[topCardIndex++];
        }
    }
}

void printHand(Player player) {
    printf("%s's hand:\n", player.name);
    for (int i = 0; i < CARDS_PER_HAND; i++) {
        printf("%s of %s\n", player.hand[i].rank, player.hand[i].suit);
    }
}

int calculateScore(Player player) {
    int score = 0;
    for (int i = 0; i < CARDS_PER_HAND; i++) {
        if (player.hand[i].rank[0] >= '2' && player.hand[i].rank[0] <= '9') {
            score += player.hand[i].rank[0] - '0';
        } else if (player.hand[i].rank[0] == 'J') {
            score += 10;
        } else if (player.hand[i].rank[0] == 'Q') {
            score += 10;
        } else if (player.hand[i].rank[0] == 'K') {
            score += 10;
        } else if (player.hand[i].rank[0] == 'A') {
            score += 11; // Count Ace as 11 for now
        }
    }
    return score;
}

void determineWinner(Player *players, int playerCount) {
    int winnerIndex = 0;
    for (int i = 1; i < playerCount; i++) {
        if (players[i].score > players[winnerIndex].score) {
            winnerIndex = i;
        }
    }
    
    printf("The winner is %s with a score of %d!\n", players[winnerIndex].name, players[winnerIndex].score);
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);

    // Ensure valid number of players
    if (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting game.\n");
        return 1;
    }

    // Set player names and initialize scores
    for (int i = 0; i < playerCount; i++) {
        players[i].name = (char *)malloc(20);
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    initializeDeck();
    dealCards(players, playerCount);

    // Calculate scores and print hands
    for (int i = 0; i < playerCount; i++) {
        players[i].score = calculateScore(players[i]);
        printHand(players[i]);
    }

    determineWinner(players, playerCount);

    // Free allocated memory for player names
    for (int i = 0; i < playerCount; i++) {
        free(players[i].name);
    }

    return 0;
}