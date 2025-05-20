//FormAI DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void add_player(char* name) {
    if (num_players >= MAX_PLAYERS) {
        printf("Error: Maximum number of players reached.\n");
        return;
    }

    // Create player struct
    Player new_player;
    strncpy(new_player.name, name, MAX_NAME_LENGTH);
    new_player.score = 0;

    // Add player to array
    players[num_players] = new_player;
    num_players++;
}

void print_scoreboard() {
    printf("Scoreboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s - %d\n", players[i].name, players[i].score);
    }
}

int main() {
    printf("Welcome to my decentralized game!\n");

    // Add players
    add_player("Alice");
    add_player("Bob");
    add_player("Charlie");

    // Play game (score points for each player)
    for (int i = 0; i < num_players; i++) {
        printf("%s's turn. Enter their score: ", players[i].name);
        int score;
        scanf("%d", &score);
        players[i].score += score;
    }

    // Print final scoreboard
    print_scoreboard();

    return 0;
}