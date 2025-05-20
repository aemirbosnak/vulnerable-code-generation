//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 1000
#define MAX_PLAYERS 100

typedef struct {
    int id;
    char name[20];
} Player;

typedef struct {
    int id;
    char name[20];
    int score;
} Card;

void shuffleCards(Card cards[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void printCard(Card card) {
    printf("ID: %d\tName: %s\tScore: %d\n", card.id, card.name, card.score);
}

int main() {
    int nPlayers, nCards;
    printf("Enter the number of players: ");
    scanf("%d", &nPlayers);
    printf("Enter the number of cards: ");
    scanf("%d", &nCards);

    Player players[MAX_PLAYERS];
    Card cards[MAX_CARDS];

    for (int i = 0; i < nPlayers; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].id = i+1;
    }

    for (int i = 0; i < nCards; i++) {
        cards[i].id = i+1;
        printf("Enter card %d's name: ", i+1);
        scanf("%s", cards[i].name);
        cards[i].score = rand() % 100;
    }

    shuffleCards(cards, nCards);

    printf("Bingo cards:\n");
    for (int i = 0; i < nPlayers; i++) {
        int j = rand() % nCards;
        Card temp = cards[j];
        cards[j] = cards[nCards-1];
        cards[nCards-1] = temp;
        nCards--;

        printf("Player %d's card:\n", players[i].id);
        for (int k = 0; k < 5; k++) {
            printf("%d. ", cards[j].id);
            j++;
            if (j == nCards) j = 0;
        }
        printf("\n");
    }

    return 0;
}