//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100
#define MAX_NUMBERS 75

typedef struct {
    char name[20];
    int cards[MAX_CARDS];
} Player;

void shuffleDeck(int deck[MAX_NUMBERS]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUMBERS; i++) {
        deck[i] = rand() % MAX_NUMBERS + 1;
    }
}

void printCard(int card) {
    if (card < 10) {
        printf("0%d ", card);
    } else {
        printf("%d ", card);
    }
}

void printCards(int cards[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        printCard(cards[i]);
    }
    printf("\n");
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;
    printf("Enter number of players (1-10): ");
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name of player %d: ", i+1);
        scanf("%s", players[i].name);
    }

    int deck[MAX_NUMBERS];
    shuffleDeck(deck);

    int cardsPerPlayer = MAX_NUMBERS / numPlayers;
    int remainingCards = MAX_NUMBERS % numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < cardsPerPlayer; j++) {
            players[i].cards[j] = deck[i * cardsPerPlayer + j];
        }
        if (remainingCards > 0) {
            players[i].cards[cardsPerPlayer] = deck[i * cardsPerPlayer + cardsPerPlayer];
            remainingCards--;
        }
    }

    int currentPlayer = 0;
    int calledNumbers[MAX_NUMBERS];
    int numCalledNumbers = 0;

    while (numCalledNumbers < MAX_NUMBERS) {
        int number = deck[currentPlayer * cardsPerPlayer + numCalledNumbers % cardsPerPlayer];
        calledNumbers[numCalledNumbers++] = number;
        currentPlayer++;
        if (currentPlayer >= numPlayers) {
            currentPlayer = 0;
        }
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Player %s's cards:\n", players[i].name);
        printCards(players[i].cards);
    }

    return 0;
}