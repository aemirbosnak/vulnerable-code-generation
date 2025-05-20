//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define NUM_PLAYERS 10
#define NUM_CARDS 5
#define NUM_SPOTS 25
#define WIN_CONDITION 5
#define BINGO "BINGO"

typedef struct {
    char player[10];
    char cards[NUM_CARDS][NUM_SPOTS];
} Player;

Player players[NUM_PLAYERS];
int cards_called[NUM_CARDS][NUM_SPOTS];

void init_players(void) {
    srand(time(NULL));
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter player name: ");
        scanf("%s", players[i].player);
        for (int j = 0; j < NUM_CARDS; j++) {
            for (int k = 0; k < NUM_SPOTS; k++) {
                int random_num = rand() % NUM_SPOTS;
                if (cards_called[j][random_num] == 0) {
                    cards_called[j][random_num] = 1;
                    players[i].cards[j][random_num] = random_num + 1;
                }
            }
        }
    }
}

void print_cards(void) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s's cards:\n", players[i].player);
        for (int j = 0; j < NUM_CARDS; j++) {
            printf("Card %d:\n", j + 1);
            for (int k = 0; k < NUM_SPOTS; k++) {
                if (cards_called[j][k] == 1) {
                    printf("%d ", players[i].cards[j][k]);
                } else {
                    printf("- ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

void call_card(int card_num) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (players[i].cards[card_num][cards_called[card_num][0]] == 0) {
            players[i].cards[card_num][cards_called[card_num][0]] = BINGO;
            cards_called[card_num][0]++;
            printf("%s calls card %d!\n", players[i].player, card_num + 1);
            if (cards_called[card_num][0] == NUM_SPOTS) {
                printf("%s wins!\n", players[i].player);
                return;
            }
        }
    }
}

void main(void) {
    init_players();
    while (1) {
        int random_card = rand() % NUM_CARDS;
        printf("Calling card %d...\n", random_card + 1);
        call_card(random_card);
    }
}