//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int id;
    char name[32];
    int score;
} player_t;

typedef struct {
    int num_players;
    player_t players[MAX_PLAYERS];
} game_state_t;

void parse_json(char *json, game_state_t *game_state) {
    char *start, *end, *key, *value;
    int i;

    // Parse the number of players
    start = strstr(json, "\"num_players\": ");
    if (start == NULL) {
        return;
    }
    start += strlen("\"num_players\": ");
    end = strchr(start, ',');
    if (end == NULL) {
        return;
    }
    game_state->num_players = atoi(start);

    // Parse the players
    for (i = 0; i < game_state->num_players; i++) {
        // Parse the player ID
        start = strstr(json, "\"id\": ");
        if (start == NULL) {
            return;
        }
        start += strlen("\"id\": ");
        end = strchr(start, ',');
        if (end == NULL) {
            return;
        }
        game_state->players[i].id = atoi(start);

        // Parse the player name
        start = strstr(json, "\"name\": ");
        if (start == NULL) {
            return;
        }
        start += strlen("\"name\": ");
        end = strchr(start, '"');
        if (end == NULL) {
            return;
        }
        strncpy(game_state->players[i].name, start, end - start);

        // Parse the player score
        start = strstr(json, "\"score\": ");
        if (start == NULL) {
            return;
        }
        start += strlen("\"score\": ");
        end = strchr(start, '}');
        if (end == NULL) {
            return;
        }
        game_state->players[i].score = atoi(start);
    }
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    game_state_t game_state;

    // Get the JSON data from the client
    printf("Enter the JSON data: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the JSON data
    parse_json(buffer, &game_state);

    // Print the game state
    printf("Game state:\n");
    printf("Number of players: %d\n", game_state.num_players);
    for (int i = 0; i < game_state.num_players; i++) {
        printf("Player %d:\n", game_state.players[i].id);
        printf("  Name: %s\n", game_state.players[i].name);
        printf("  Score: %d\n", game_state.players[i].score);
    }

    return 0;
}