//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main characters
typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Character;

// Define the game state
typedef struct {
    Character romeo;
    Character juliet;
    int turn;
} GameState;

// Create a new game state
GameState *new_game_state() {
    GameState *state = malloc(sizeof(GameState));
    state->romeo.name = "Romeo";
    state->romeo.health = 100;
    state->romeo.attack = 10;
    state->romeo.defense = 5;
    state->juliet.name = "Juliet";
    state->juliet.health = 100;
    state->juliet.attack = 10;
    state->juliet.defense = 5;
    state->turn = 0;
    return state;
}

// Free the game state
void free_game_state(GameState *state) {
    free(state->romeo.name);
    free(state->juliet.name);
    free(state);
}

// Print the game state
void print_game_state(GameState *state) {
    printf("Romeo's health: %d\n", state->romeo.health);
    printf("Juliet's health: %d\n", state->juliet.health);
    printf("Turn: %d\n", state->turn);
}

// Handle a player's turn
void handle_turn(GameState *state) {
    // Get the player's input
    char input[100];
    printf("Enter your move (attack/defend): ");
    scanf("%s", input);

    // Process the player's input
    if (strcmp(input, "attack") == 0) {
        // Attack the opponent
        int damage = state->turn == 0 ? state->romeo.attack : state->juliet.attack;
        if (state->turn == 0) {
            state->juliet.health -= damage;
        } else {
            state->romeo.health -= damage;
        }
    } else if (strcmp(input, "defend") == 0) {
        // Defend against the opponent's attack
        int defense = state->turn == 0 ? state->romeo.defense : state->juliet.defense;
        if (state->turn == 0) {
            state->juliet.health -= defense;
        } else {
            state->romeo.health -= defense;
        }
    }

    // Switch to the other player's turn
    state->turn = (state->turn + 1) % 2;
}

// Check if the game is over
int is_game_over(GameState *state) {
    return state->romeo.health <= 0 || state->juliet.health <= 0;
}

// Play the game
void play_game() {
    // Create a new game state
    GameState *state = new_game_state();

    // Print the initial game state
    print_game_state(state);

    // Loop until the game is over
    while (!is_game_over(state)) {
        // Handle the current player's turn
        handle_turn(state);

        // Print the updated game state
        print_game_state(state);
    }

    // Print the game over message
    if (state->romeo.health <= 0) {
        printf("Juliet wins!\n");
    } else {
        printf("Romeo wins!\n");
    }

    // Free the game state
    free_game_state(state);
}

// Main function
int main() {
    // Play the game
    play_game();

    return 0;
}