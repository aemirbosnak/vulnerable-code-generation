//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>

#define NUM_PLAYERS 4
#define NUM_LIGHTS 10

typedef struct player {
    char name[20];
    int score;
    int lights[NUM_LIGHTS];
} player_t;

typedef struct game {
    player_t players[NUM_PLAYERS];
    int lights[NUM_LIGHTS];
    int turn;
} game_t;

void init_game(game_t *game) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        sprintf(game->players[i].name, "Player %d", i + 1);
        game->players[i].score = 0;
        for (int j = 0; j < NUM_LIGHTS; j++) {
            game->players[i].lights[j] = 0;
        }
    }

    for (int i = 0; i < NUM_LIGHTS; i++) {
        game->lights[i] = 0;
    }

    game->turn = 0;
}

void print_game(game_t *game) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s: %d\n", game->players[i].name, game->players[i].score);
        for (int j = 0; j < NUM_LIGHTS; j++) {
            printf("%d ", game->players[i].lights[j]);
        }
        printf("\n");
    }

    printf("Lights:");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("%d ", game->lights[i]);
    }
    printf("\n");
    printf("Turn: %d\n", game->turn);
}

int main() {
    game_t game;
    init_game(&game);

    // Game loop
    while (1) {
        // Get the current player
        player_t *player = &game.players[game.turn];

        // Get the player's input
        int light;
        printf("Player %s, choose a light: ", player->name);
        scanf("%d", &light);

        // Check if the player's input is valid
        if (light < 0 || light >= NUM_LIGHTS) {
            printf("Invalid light number. Try again.\n");
            continue;
        }

        // Toggle the light
        game.lights[light] = !game.lights[light];

        // Check if the player has won
        int all_lights_on = 1;
        for (int i = 0; i < NUM_LIGHTS; i++) {
            if (!game.lights[i]) {
                all_lights_on = 0;
                break;
            }
        }

        if (all_lights_on) {
            printf("Player %s wins!\n", player->name);
            break;
        }

        // Increment the player's score
        player->score++;

        // Advance to the next player
        game.turn = (game.turn + 1) % NUM_PLAYERS;
    }

    return 0;
}