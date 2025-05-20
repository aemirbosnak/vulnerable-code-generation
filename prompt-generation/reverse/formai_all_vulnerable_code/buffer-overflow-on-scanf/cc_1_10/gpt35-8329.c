//FormAI DATASET v1.0 Category: Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 10

typedef struct {
    int id;
    int level;
    int score;
} Player;

void initialize_players(Player *players, int num_players);
void display_player_stats(Player *player);
int get_random_score();

int main() {
    Player players[MAX_PLAYERS];
    int num_players;

    printf("Welcome to the game!\n");
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    initialize_players(players, num_players);

    printf("\nLet's play the game!\n");

    for (int i = 0; i < num_players; i++) {
        printf("\nPlayer %d's turn: ", i+1);
        Player player = players[i];
        display_player_stats(&player);

        int score = get_random_score();
        printf("You scored %d!\n", score);

        player.score += score;
        player.level = player.score / 10;

        printf("Your updated stats:\n");
        display_player_stats(&player);

        players[i] = player;
    }

    printf("\nGame over! Here are the final scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %d\n", players[i].id, players[i].score);
    }

    return 0;
}

void initialize_players(Player *players, int num_players) {
    printf("\nInitializing players...\n");
    for (int i = 0; i < num_players; i++) {
        Player player;
        player.id = i+1;
        player.level = 0;
        player.score = 0;
        players[i] = player;
        printf("Player %d initialized.\n", player.id);
    }
}

void display_player_stats(Player *player) {
    printf("Player %d | Level %d | Score %d\n", player->id, player->level, player->score);
}

int get_random_score() {
    int min = 1;
    int max = 10;
    return (rand() % (max - min + 1)) + min;
}