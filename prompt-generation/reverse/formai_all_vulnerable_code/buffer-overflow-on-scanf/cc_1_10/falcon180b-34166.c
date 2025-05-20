//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PLAYERS 10
#define MAX_CARDS 75

typedef struct {
    char name[20];
    int card[MAX_CARDS];
} Player;

void initPlayer(Player* player, char* name) {
    strcpy(player->name, name);
    for (int i = 0; i < MAX_CARDS; i++) {
        player->card[i] = 0;
    }
}

void printCard(int card) {
    printf("%d ", card);
}

void printPlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %s\n", i + 1, players[i].name);
        for (int j = 0; j < MAX_CARDS; j++) {
            printCard(players[i].card[j]);
        }
        printf("\n");
    }
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
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
        char name[20];
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", name);
        initPlayer(&players[i], name);
    }
    int numCards = getRandomNumber(75, 100);
    printf("Number of cards: %d\n", numCards);
    int cards[numCards];
    for (int i = 0; i < numCards; i++) {
        cards[i] = getRandomNumber(1, 75);
    }
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < MAX_CARDS; j++) {
            if (j < numCards) {
                players[i].card[j] = cards[j];
            } else {
                players[i].card[j] = 0;
            }
        }
    }
    printPlayers(players, numPlayers);
    return 0;
}