//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100

typedef struct {
    int id;
    char name[32];
    int score;
    int cards[MAX_CARDS];
} Player;

void init_player(Player *player, int id, char *name) {
    player->id = id;
    strncpy(player->name, name, sizeof(player->name));
    player->score = 0;
    for (int i = 0; i < MAX_CARDS; i++) {
        player->cards[i] = 0;
    }
}

void print_player(Player *player) {
    printf("ID: %d\nName: %s\nScore: %d\nCards: ", player->id, player->name, player->score);
    for (int i = 0; i < MAX_CARDS; i++) {
        printf("%d ", player->cards[i]);
    }
    printf("\n");
}

int get_card() {
    int card = rand() % 15 + 1;
    return card;
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Welcome to the Post-Apocalyptic Bingo Simulator!\n");
    while (num_players < MAX_PLAYERS) {
        printf("Enter player name (or type 'quit' to start the game): ");
        char name[32];
        scanf("%s", name);
        if (strcmp(name, "quit") == 0) {
            break;
        }
        num_players++;
        init_player(&players[num_players - 1], num_players, name);
    }

    int current_player = 0;
    while (1) {
        printf("Player %d's turn:\n", current_player + 1);
        for (int i = 0; i < MAX_CARDS; i++) {
            int card = get_card();
            if (card == 15) {
                printf("Bingo!\n");
                players[current_player].score += 10;
            } else {
                printf("%d ", card);
            }
            players[current_player].cards[i] = card;
        }
        printf("\n");

        current_player = (current_player + 1) % num_players;
        if (current_player == 0) {
            for (int i = 0; i < num_players; i++) {
                print_player(&players[i]);
            }
        }
    }

    return 0;
}