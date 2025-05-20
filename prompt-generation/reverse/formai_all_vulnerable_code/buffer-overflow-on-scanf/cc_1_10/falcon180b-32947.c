//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100

typedef struct {
    char name[20];
    int cards[MAX_CARDS];
} Player;

void init_cards(Player* player) {
    for (int i = 0; i < MAX_CARDS; i++) {
        player->cards[i] = i + 1;
    }
}

void print_card(int card) {
    if (card < 10) {
        printf("0%d ", card);
    } else {
        printf("%d ", card);
    }
}

void print_cards(Player* player) {
    for (int i = 0; i < MAX_CARDS; i++) {
        print_card(player->cards[i]);
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int num_players;
    printf("Enter number of players (1-10): ");
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player name: ");
        scanf("%s", players[i].name);
        init_cards(&players[i]);
    }

    int current_player = 0;
    int num_cards_drawn = 0;
    int cards_left = MAX_CARDS;

    while (cards_left > 0) {
        int card = rand() % MAX_CARDS + 1;
        if (card <= MAX_CARDS) {
            for (int i = 0; i < num_players; i++) {
                if (players[i].cards[card] == 0) {
                    players[i].cards[card] = 1;
                    num_cards_drawn++;
                    break;
                }
            }
        }
        cards_left--;
    }

    printf("\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %s's cards:\n", players[i].name);
        print_cards(&players[i]);
        printf("\n");
    }

    printf("Number of cards drawn: %d\n", num_cards_drawn);

    return 0;
}