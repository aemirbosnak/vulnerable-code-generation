//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 1000
#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int card[MAX_CARDS];
} Player;

void printCard(int card[5]) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", card[i]);
    }
    printf("\n");
}

void shuffle(int cards[MAX_CARDS]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
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

    int cards[MAX_CARDS];
    for (int i = 0; i < MAX_CARDS; i++) {
        cards[i] = i + 1;
    }

    shuffle(cards);

    for (int i = 0; i < MAX_CARDS; i += 5) {
        for (int j = 0; j < numPlayers; j++) {
            for (int k = 0; k < 5; k++) {
                players[j].card[i + k] = cards[i + k];
            }
        }
    }

    int currentCard = 0;
    while (currentCard < MAX_CARDS) {
        printf("Current card: ");
        printCard(cards[currentCard]);
        for (int i = 0; i < numPlayers; i++) {
            if (players[i].card[currentCard] == cards[currentCard]) {
                printf("%s wins!\n", players[i].name);
                return 0;
            }
        }
        currentCard++;
    }

    printf("Tie game.\n");

    return 0;
}