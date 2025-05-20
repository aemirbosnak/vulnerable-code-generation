//Gemma-7B DATASET v1.0 Category: Temperature monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYER_COUNT 4

typedef struct Player {
    char name[20];
    int temperature;
    int is_active;
} Player;

void update_player_temperature(Player *player, int new_temperature) {
    player->temperature = new_temperature;
}

void print_player_temperature(Player *player) {
    printf("%s's temperature is %d degrees.\n", player->name, player->temperature);
}

int main() {
    Player players[MAX_PLAYER_COUNT];

    // Initialize players
    for (int i = 0; i < MAX_PLAYER_COUNT; i++) {
        players[i].name[0] = '\0';
        players[i].temperature = 0;
        players[i].is_active = 0;
    }

    // Get player names
    for (int i = 0; i < MAX_PLAYER_COUNT; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Start the game loop
    int game_loop = 1;
    while (game_loop) {
        // Get the current temperature
        int current_temperature = rand() % 100;

        // Update player temperatures
        for (int i = 0; i < MAX_PLAYER_COUNT; i++) {
            if (players[i].is_active) {
                update_player_temperature(&players[i], current_temperature);
            }
        }

        // Print player temperatures
        for (int i = 0; i < MAX_PLAYER_COUNT; i++) {
            if (players[i].is_active) {
                print_player_temperature(&players[i]);
            }
        }

        // Check if any player's temperature has reached the limit
        for (int i = 0; i < MAX_PLAYER_COUNT; i++) {
            if (players[i].is_active && players[i].temperature >= 40) {
                printf("%s has reached the temperature limit of 40 degrees!\n", players[i].name);
                players[i].is_active = 0;
            }
        }

        // Ask if the game should continue
        printf("Do you want to continue the game? (Y/N): ");
        char continue_game;
        scanf("%c", &continue_game);

        // Check if the game should continue
        if (continue_game != 'Y') {
            game_loop = 0;
        }
    }

    return 0;
}