//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
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

void initialize_player(Player* player, int id, char* name) {
    player->id = id;
    strcpy(player->name, name);
    for (int i = 0; i < MAX_CARDS; i++) {
        player->cards[i] = 0;
    }
}

void print_player(Player player) {
    printf("Player %d: %s\n", player.id, player.name);
    for (int i = 0; i < MAX_CARDS; i++) {
        if (player.cards[i] == 1) {
            printf("%d ", i+1);
        }
    }
    printf("\n");
}

int main() {
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        char name[20];
        printf("Enter player %d's name: ", i+1);
        scanf("%s", name);
        initialize_player(&players[i], i+1, name);
    }

    int num_cards = 0;
    int card_num;
    while (num_cards < 75) {
        card_num = rand() % 75 + 1;
        if (card_num!= num_cards) {
            num_cards++;
        }
    }

    for (int i = 0; i < num_cards; i++) {
        int player_id = rand() % num_players;
        players[player_id].cards[i] = 1;
    }

    int game_over = 0;
    while (!game_over) {
        for (int i = 0; i < num_players; i++) {
            print_player(players[i]);
        }
        if (game_over) {
            break;
        }
    }

    return 0;
}