//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100

struct Card {
    int number;
    int marked;
};

struct Player {
    char name[20];
    int cards[MAX_CARDS];
};

void shuffle(struct Card* deck, int numCards) {
    for (int i = 0; i < numCards; i++) {
        int j = rand() % numCards;
        struct Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    int numPlayers;
    printf("How many players are playing? ");
    scanf("%d", &numPlayers);

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    struct Player players[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name of player %d: ", i+1);
        scanf("%s", players[i].name);
    }

    int numCards = 75;
    struct Card deck[numCards];
    for (int i = 0; i < numCards; i++) {
        deck[i].number = i+1;
        deck[i].marked = 0;
    }

    shuffle(deck, numCards);

    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 15; j++) {
            int card = deck[j].number;
            deck[j].marked = 1;
            players[i].cards[j] = card;
        }
    }

    int currentPlayer = 0;
    int currentCard = 0;
    while (1) {
        printf("Current player: %s\n", players[currentPlayer].name);
        printf("Current card: %d\n", deck[currentCard].number);

        if (deck[currentCard].marked == 1) {
            printf("Card already marked!\n");
        } else {
            deck[currentCard].marked = 1;
            players[currentPlayer].cards[currentCard] = deck[currentCard].number;
            currentCard++;
        }

        if (currentCard == 15) {
            currentCard = 0;
            currentPlayer++;
            if (currentPlayer == numPlayers) {
                printf("Game over!\n");
                return 0;
            }
        }
    }
}