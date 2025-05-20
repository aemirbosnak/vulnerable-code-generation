//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 100
#define MAX_CARDS 1000
#define MAX_NUMBERS 75

typedef struct {
    int id;
    char name[20];
} Player;

typedef struct {
    int value;
    int marked;
} Card;

void init_card(Card *card) {
    card->value = rand() % MAX_NUMBERS + 1;
    card->marked = 0;
}

void print_card(Card card) {
    if (card.marked) {
        printf("%d\t", card.value);
    } else {
        printf("%d\t", 0);
    }
}

void init_player(Player *player) {
    player->id = rand() % MAX_PLAYERS + 1;
    sprintf(player->name, "Player %d", player->id);
}

void print_player(Player player) {
    printf("%s\t", player.name);
}

int main() {
    srand(time(NULL));

    int num_players, num_cards;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        init_player(&players[i]);
        printf("%s joined the game.\n", players[i].name);
    }

    printf("\n");

    int num_cards_per_player = MAX_CARDS / num_players;
    num_cards = num_cards_per_player * num_players;

    Card cards[MAX_CARDS];
    for (int i = 0; i < num_cards; i++) {
        init_card(&cards[i]);
    }

    int current_card = 0;
    while (current_card < num_cards) {
        printf("\nRound %d:\n", current_card / num_cards_per_player + 1);
        for (int i = 0; i < num_players; i++) {
            print_player(players[i]);
            printf("\t");
        }
        printf("\n");

        for (int i = 0; i < num_cards_per_player; i++) {
            print_card(cards[current_card]);
            if (current_card % num_cards_per_player == num_cards_per_player - 1) {
                printf("\n");
            }
            current_card++;
        }

        printf("\n");
    }

    return 0;
}