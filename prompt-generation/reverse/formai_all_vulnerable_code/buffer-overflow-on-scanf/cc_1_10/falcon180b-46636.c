//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 75
#define MAX_ROUNDS 10

typedef struct {
    int id;
    char name[20];
    int cards[MAX_CARDS];
} Player;

void shuffle(int deck[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_deck(int deck[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Enter the number of players (up to %d): ", MAX_PLAYERS - 1);
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf(" %s", players[i].name);
        players[i].id = i + 1;
    }

    int deck[MAX_CARDS];
    for (int i = 1; i <= 75; i++) {
        deck[i - 1] = i;
    }

    shuffle(deck, 75);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\nRound %d:\n", round);
        for (int i = 0; i < num_players; i++) {
            for (int j = 0; j < 5; j++) {
                int card = deck[5 * i + j];
                players[i].cards[j] = card;
                deck[5 * i + j] = 0;
            }
        }

        printf("Player %s's hand:\n", players[0].name);
        print_deck(players[0].cards, 5);

        for (int i = 1; i < num_players; i++) {
            printf("\nPlayer %s's hand:\n", players[i].name);
            print_deck(players[i].cards, 5);
        }

        int winner = 0;
        for (int i = 1; i < num_players; i++) {
            if (players[i].cards[0] > players[winner].cards[0]) {
                winner = i;
            }
        }

        printf("\nPlayer %s wins round %d!\n\n", players[winner].name, round);
    }

    return 0;
}