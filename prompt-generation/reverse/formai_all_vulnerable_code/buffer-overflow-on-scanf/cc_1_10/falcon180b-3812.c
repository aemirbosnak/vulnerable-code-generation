//Falcon-180B DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[20];
    int score;
} Player;

void init_player(Player* player) {
    strcpy(player->name, "Player");
    player->score = 0;
}

void print_player(Player player) {
    printf("%s: %d\n", player.name, player.score);
}

void start_game() {
    int num_players;
    printf("How many players? (1-4): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return;
    }

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        init_player(&players[i]);
    }

    int current_round = 1;
    while (current_round <= MAX_ROUNDS) {
        int dice_roll = rand() % 6 + 1;
        printf("Round %d: Rolled a %d\n", current_round, dice_roll);

        for (int i = 0; i < num_players; i++) {
            printf("Player %d's turn:\n", i+1);
            char choice;
            scanf(" %c", &choice);

            if (choice == 'r' || choice == 'R') {
                players[i].score += dice_roll;
                printf("%s rolled and scored %d points. New score: %d\n", players[i].name, dice_roll, players[i].score);
            } else if (choice =='s' || choice == 'S') {
                printf("%s saved their score.\n", players[i].name);
            } else {
                printf("Invalid choice. %s loses their turn.\n", players[i].name);
            }
        }

        current_round++;
    }

    printf("Game over!\n");

    for (int i = 0; i < num_players; i++) {
        print_player(players[i]);
    }
}

int main() {
    srand(time(NULL));
    start_game();
    return 0;
}