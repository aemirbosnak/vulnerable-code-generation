//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100

typedef struct {
    int id;
    char name[20];
    int cards[MAX_CARDS];
} Player;

void generateCard(int *card) {
    *card = rand() % 75 + 1;
}

void printCard(int card) {
    if (card < 10) {
        printf("0%d ", card);
    } else {
        printf("%d ", card);
    }
}

void printCards(int cards[], int n) {
    for (int i = 0; i < n; i++) {
        printCard(cards[i]);
    }
    printf("\n");
}

int compareCards(const void *a, const void *b) {
    int cardA = *(int *)a;
    int cardB = *(int *)b;

    if (cardA > cardB) {
        return 1;
    } else if (cardA < cardB) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    int numPlayers;
    printf("Enter the number of players (1-10): ");
    scanf("%d", &numPlayers);

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    Player players[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);

        for (int j = 0; j < MAX_CARDS; j++) {
            generateCard(&players[i].cards[j]);
        }
    }

    qsort(players, numPlayers, sizeof(Player), compareCards);

    printf("Player cards:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: ", i + 1);
        printCards(players[i].cards, MAX_CARDS);
    }

    return 0;
}