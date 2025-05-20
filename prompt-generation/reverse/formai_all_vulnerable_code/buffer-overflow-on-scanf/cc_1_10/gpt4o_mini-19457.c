//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define GALAXY_SIZE 10
#define RESOURCE_TYPES 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    int resources[RESOURCE_TYPES];
    int position;
} Player;

void initialize_players(Player players[], int player_count) {
    for (int i = 0; i < player_count; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        for (int j = 0; j < RESOURCE_TYPES; j++) {
            players[i].resources[j] = 0;
        }
        players[i].position = 0;
    }
}

void display_status(Player players[], int player_count) {
    printf("\n== Player Status ==\n");
    for (int i = 0; i < player_count; i++) {
        printf("Name: %s | Position: %d | Resources: [Gold: %d, Fuel: %d, Crystals: %d]\n",
               players[i].name, players[i].position,
               players[i].resources[0], players[i].resources[1], players[i].resources[2]);
    }
}

void move_player(Player *player) {
    player->position = (player->position + rand() % GALAXY_SIZE) % GALAXY_SIZE;
    printf("%s moves to position %d.\n", player->name, player->position);
}

void collect_resources(Player *player) {
    int resource_found = rand() % RESOURCE_TYPES;
    player->resources[resource_found]++;
    printf("%s collected 1 unit of ", player->name);
    switch (resource_found) {
        case 0: printf("Gold!\n"); break;
        case 1: printf("Fuel!\n"); break;
        case 2: printf("Crystals!\n"); break;
    }
}

void encounter_event(Player *player) {
    int event_type = rand() % 3;
    printf("%s has encountered an event: ", player->name);
    switch (event_type) {
        case 0:
            printf("Space Pirates! Lose 1 Fuel!\n");
            if (player->resources[1] > 0) player->resources[1]--;
            else printf("But no Fuel to lose!\n");
            break;
        case 1:
            printf("Salvage Crew! Gain 2 Gold!\n");
            player->resources[0] += 2;
            break;
        case 2:
            printf("Mysterious Space Anomaly! Lose 1 Crystal!\n");
            if (player->resources[2] > 0) player->resources[2]--;
            else printf("But no Crystals to lose!\n");
            break;
    }
}

void game_round(Player players[], int player_count) {
    for (int i = 0; i < player_count; i++) {
        move_player(&players[i]);
        collect_resources(&players[i]);
        encounter_event(&players[i]);
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int player_count;

    printf("Welcome to the Multiplayer Space Adventure!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &player_count);

    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting game.\n");
        return 1;
    }

    initialize_players(players, player_count);

    char play_again;
    do {
        display_status(players, player_count);
        game_round(players, player_count);
        printf("Continue to the next round? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y');

    printf("Thank you for playing! Goodbye!\n");

    return 0;
}