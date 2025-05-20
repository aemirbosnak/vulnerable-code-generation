//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    int id;
    char name[20];
    Point position;
    int score;
} Player;

void init_player(Player *player, int id, char *name) {
    player->id = id;
    strcpy(player->name, name);
    player->position.x = rand() % 800 + 50;
    player->position.y = rand() % 600 + 50;
    player->score = 0;
}

void draw_player(Player player) {
    printf("Player %d (%s) is at (%d, %d)\n", player.id, player.name, player.position.x, player.position.y);
}

void move_player(Player *player, int dx, int dy) {
    player->position.x += dx;
    player->position.y += dy;
}

void update_player_score(Player *player) {
    player->score++;
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Enter number of players (1-4): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        char name[20];
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", name);

        init_player(&players[i], i + 1, name);
    }

    int round = 1;
    while (round <= MAX_ROUNDS) {
        printf("Round %d\n", round);

        for (int i = 0; i < num_players; i++) {
            draw_player(players[i]);
        }

        int winner = 0;
        for (int i = 0; i < num_players; i++) {
            if (players[i].score > winner) {
                winner = i;
            }
        }

        printf("Player %d wins round %d!\n", winner + 1, round);
        update_player_score(&players[winner]);

        round++;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Final score for player %d: %d\n", i + 1, players[i].score);
    }

    return 0;
}