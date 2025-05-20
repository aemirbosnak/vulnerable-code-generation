//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 52

struct player {
    char name[20];
    int cards[MAX_CARDS];
    int num_cards;
};

struct game {
    struct player players[MAX_PLAYERS];
    int num_players;
    int deck[MAX_CARDS];
    int num_cards_in_deck;
};

void deal_cards(struct game *game) {
    int i, j, k;

    for (i = 0; i < game->num_players; i++) {
        for (j = 0; j < 7; j++) {
            k = rand() % game->num_cards_in_deck;
            game->players[i].cards[j] = game->deck[k];
            game->deck[k] = game->deck[game->num_cards_in_deck - 1];
            game->num_cards_in_deck--;
        }
    }
}

void print_table(struct game *game) {
    int i, j;

    printf("   ");
    for (i = 0; i < game->num_players; i++) {
        printf("%s  ", game->players[i].name);
    }
    putchar('\n');

    for (i = 0; i < 7; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < game->num_players; j++) {
            printf("%d  ", game->players[j].cards[i]);
        }
        putchar('\n');
    }
}

int main() {
    struct game game;
    int i, j;

    game.num_players = 4;
    for (i = 0; i < game.num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", game.players[i].name);
    }

    for (i = 0; i < MAX_CARDS; i++) {
        game.deck[i] = i;
    }
    game.num_cards_in_deck = MAX_CARDS;

    deal_cards(&game);

    print_table(&game);

    return 0;
}