//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 10

// Define the maximum length of a player's name
#define MAX_NAME_LENGTH 20

// Define the maximum length of a player's input
#define MAX_INPUT_LENGTH 100

// Create a struct to represent a player
typedef struct {
    char name[MAX_NAME_LENGTH];
    char input[MAX_INPUT_LENGTH];
} player_t;

// Create an array of players
player_t players[MAX_PLAYERS];

// Get the number of players
int get_num_players() {
    int num_players;
    printf("How many players are there? ");
    scanf("%d", &num_players);
    return num_players;
}

// Get the names of the players
void get_player_names(int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }
}

// Get the input from the players
void get_player_input(int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s, enter your input: ", players[i].name);
        scanf("%s", players[i].input);
    }
}

// Sanitize the input from the players
void sanitize_player_input(int num_players) {
    for (int i = 0; i < num_players; i++) {
        // Remove any special characters from the input
        for (int j = 0; j < strlen(players[i].input); j++) {
            if (!isalnum(players[i].input[j])) {
                players[i].input[j] = '\0';
            }
        }

        // Convert the input to lowercase
        for (int j = 0; j < strlen(players[i].input); j++) {
            players[i].input[j] = tolower(players[i].input[j]);
        }
    }
}

// Print the sanitized input from the players
void print_sanitized_player_input(int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s: %s\n", players[i].name, players[i].input);
    }
}

int main() {
    // Get the number of players
    int num_players = get_num_players();

    // Get the names of the players
    get_player_names(num_players);

    // Get the input from the players
    get_player_input(num_players);

    // Sanitize the input from the players
    sanitize_player_input(num_players);

    // Print the sanitized input from the players
    print_sanitized_player_input(num_players);

    return 0;
}