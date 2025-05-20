//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: happy
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

void shuffle(int *deck, int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(int card) {
    if (card < 10) {
        printf("0%d ", card);
    } else {
        printf("%d ", card);
    }
}

int main() {
    srand(time(NULL));

    int num_players = 5;
    Player players[MAX_PLAYERS];

    for (int i = 0; i < num_players; i++) {
        players[i].id = i + 1;
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    int num_cards = 75;
    int deck[MAX_CARDS];

    for (int i = 0; i < num_cards; i++) {
        deck[i] = i + 1;
    }

    shuffle(deck, num_cards);

    for (int i = 0; i < num_players; i++) {
        players[i].cards[0] = deck[i * 15];
        for (int j = 1; j < 15; j++) {
            players[i].cards[j] = deck[(i * 15) + j];
        }
    }

    printf("\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: ", i + 1);
        for (int j = 0; j < 15; j++) {
            print_card(players[i].cards[j]);
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}