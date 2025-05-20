//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the structure of a player
typedef struct {
    char name[32];
    int score;
} Player;

// Define the structure of the game state
typedef struct {
    Player players[MAX_PLAYERS];
    int current_player;
    int target_score;
} GameState;

// Initialize the game state
void init_game(GameState *state) {
    // Set the current player to the first player
    state->current_player = 0;

    // Set the target score to 100
    state->target_score = 100;

    // Initialize the players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(state->players[i].name, "");
        state->players[i].score = 0;
    }
}

// Print the game state
void print_game(GameState *state) {
    // Print the current player
    printf("Current player: %s\n", state->players[state->current_player].name);

    // Print the scores of all the players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", state->players[i].name, state->players[i].score);
    }

    // Print the target score
    printf("Target score: %d\n", state->target_score);
}

// Get the input from the current player
int get_input(GameState *state) {
    int input;

    // Prompt the player for input
    printf("%s, enter your input (1-6): ", state->players[state->current_player].name);

    // Get the input from the player
    scanf("%d", &input);

    // Return the input
    return input;
}

// Update the game state based on the input
void update_game(GameState *state, int input) {
    // Add the input to the current player's score
    state->players[state->current_player].score += input;

    // If the current player's score is greater than or equal to the target score, they win
    if (state->players[state->current_player].score >= state->target_score) {
        printf("%s wins!\n", state->players[state->current_player].name);

        // Exit the game
        exit(0);
    }

    // Switch to the next player
    state->current_player = (state->current_player + 1) % MAX_PLAYERS;
}

// Main game loop
int main() {
    // Initialize the game state
    GameState state;
    init_game(&state);

    // Print the game state
    print_game(&state);

    // Main game loop
    while (1) {
        // Get the input from the current player
        int input = get_input(&state);

        // Update the game state based on the input
        update_game(&state, input);

        // Print the game state
        print_game(&state);
    }

    return 0;
}