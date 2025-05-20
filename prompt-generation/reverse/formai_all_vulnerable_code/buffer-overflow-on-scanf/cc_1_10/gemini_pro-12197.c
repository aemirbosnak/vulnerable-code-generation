//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of players
#define MAX_PLAYERS 4

// Maximum length of a player's name
#define MAX_NAME_LENGTH 20

// Maximum length of a player's summary
#define MAX_SUMMARY_LENGTH 200

// The game state
struct game_state {
    int num_players;
    char players[MAX_PLAYERS][MAX_NAME_LENGTH];
    char summaries[MAX_PLAYERS][MAX_SUMMARY_LENGTH];
};

// Initialize the game state
void init_game_state(struct game_state *game_state) {
    game_state->num_players = 0;
}

// Add a player to the game state
void add_player(struct game_state *game_state, char *name) {
    if (game_state->num_players < MAX_PLAYERS) {
        strcpy(game_state->players[game_state->num_players], name);
        game_state->num_players++;
    }
}

// Get a player's summary
char *get_summary(struct game_state *game_state, char *name) {
    for (int i = 0; i < game_state->num_players; i++) {
        if (strcmp(game_state->players[i], name) == 0) {
            return game_state->summaries[i];
        }
    }
    return NULL;
}

// Set a player's summary
void set_summary(struct game_state *game_state, char *name, char *summary) {
    for (int i = 0; i < game_state->num_players; i++) {
        if (strcmp(game_state->players[i], name) == 0) {
            strcpy(game_state->summaries[i], summary);
            return;
        }
    }
}

// Print the game state
void print_game_state(struct game_state *game_state) {
    printf("Players:\n");
    for (int i = 0; i < game_state->num_players; i++) {
        printf("  %s\n", game_state->players[i]);
    }
    printf("\nSummaries:\n");
    for (int i = 0; i < game_state->num_players; i++) {
        printf("  %s: %s\n", game_state->players[i], game_state->summaries[i]);
    }
}

// Main game loop
void game_loop(struct game_state *game_state) {
    while (1) {
        // Print the game state
        print_game_state(game_state);

        // Get the next player's name
        char name[MAX_NAME_LENGTH];
        printf("Enter your name: ");
        scanf("%s", name);

        // Add the player to the game state
        add_player(game_state, name);

        // Get the player's summary
        char summary[MAX_SUMMARY_LENGTH];
        printf("Enter your summary: ");
        scanf(" %[^\n]%*c", summary);

        // Set the player's summary
        set_summary(game_state, name, summary);
    }
}

// Main function
int main() {
    // Initialize the game state
    struct game_state game_state;
    init_game_state(&game_state);

    // Start the game loop
    game_loop(&game_state);

    return 0;
}