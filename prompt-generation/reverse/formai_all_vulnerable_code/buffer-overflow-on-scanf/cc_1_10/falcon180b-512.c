//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 1000
#define MAX_PLAYERS 10

typedef struct {
    int id;
    char name[20];
    int cards[MAX_CARDS];
} Player;

void init_player(Player* player, int id, char* name) {
    player->id = id;
    strcpy(player->name, name);
    for (int i = 0; i < MAX_CARDS; i++) {
        player->cards[i] = 0;
    }
}

int main() {
    srand(time(0));

    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players\n");
        return 1;
    }

    Player players[num_players];
    for (int i = 0; i < num_players; i++) {
        char name[20];
        printf("Enter player %d's name: ", i+1);
        scanf("%s", name);

        init_player(&players[i], i+1, name);
    }

    int num_cards = 75;
    int cards[num_cards];
    for (int i = 0; i < num_cards; i++) {
        cards[i] = i+1;
    }

    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < MAX_CARDS; j++) {
            int card = cards[rand() % num_cards];
            players[i].cards[j] = card;
            cards[card-1] = 0;
        }
    }

    int current_card = 0;
    while (1) {
        printf("\n%s's turn\n", players[current_card-1].name);
        for (int i = 0; i < num_players; i++) {
            if (players[i].cards[current_card] == current_card) {
                printf("%s has card %d\n", players[i].name, current_card+1);
            }
        }
        printf("\n");
        current_card++;
        if (current_card > num_cards) {
            break;
        }
    }

    return 0;
}