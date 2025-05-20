//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define TABLE_CARDS 5
#define TOTAL_CARDS 52

typedef struct {
    char *name;
    int cards[5];
    int score;
} Player;

const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

void shuffleDeck(int *deck) {
    for (int i = 0; i < TOTAL_CARDS; i++) {
        deck[i] = i;
    }

    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(int *deck, Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 5; j++) {
            players[i].cards[j] = deck[i * 5 + j];
        }
        players[i].score = 0; // reset score
    }
}

void displayCards(Player player) {
    printf("%s's cards: ", player.name);
    for (int i = 0; i < 5; i++) {
        if (player.cards[i] != -1) {
            printf("%s of %s ", values[player.cards[i] % 13], suits[player.cards[i] / 13]);
        }
    }
    printf("\n");
}

void calculateScores(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        players[i].score = 0; // Initialize score
        for (int j = 0; j < 5; j++) {
            players[i].score += (players[i].cards[j] % 13) + 2; // Add card value
        }
    }
}

void determineWinner(Player *players, int numPlayers) {
    int highestScore = -1;
    int winnerIndex = -1;

    for (int i = 0; i < numPlayers; i++) {
        printf("%s's score: %d\n", players[i].name, players[i].score);
        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            winnerIndex = i;
        }
    }
    
    printf("The winner is %s with a score of %d!\n", players[winnerIndex].name, highestScore);
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int deck[TOTAL_CARDS];
    int numPlayers;

    printf("Enter number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }

    for (int i = 0; i < numPlayers; i++) {
        players[i].name = malloc(20 * sizeof(char));
        printf("Enter Player %d name: ", i + 1);
        scanf("%s", players[i].name);
    }

    shuffleDeck(deck);
    dealCards(deck, players, numPlayers);
    
    for (int i = 0; i < numPlayers; i++) {
        displayCards(players[i]);
    }

    calculateScores(players, numPlayers);
    determineWinner(players, numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        free(players[i].name);
    }

    return 0;
}