//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum number of failed attempts
#define MAX_FAILED_ATTEMPTS 3

// Define the structure of a player
typedef struct {
    char username[20];
    char password[20];
    int failed_attempts;
} player;

// Define the array of players
player players[MAX_PLAYERS];

// Define the main function
int main() {
    // Initialize the array of players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].username, "");
        strcpy(players[i].password, "");
        players[i].failed_attempts = 0;
    }

    // Get the number of players
    int num_players;
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    // Get the username and password for each player
    for (int i = 0; i < num_players; i++) {
        printf("Player %d, enter your username: ", i + 1);
        scanf("%s", players[i].username);

        printf("Player %d, enter your password: ", i + 1);
        scanf("%s", players[i].password);
    }

    // Play the game
    int current_player = 0;
    while (1) {
        // Get the current player's guess
        char guess[20];
        printf("Player %d, enter your guess: ", current_player + 1);
        scanf("%s", guess);

        // Check if the guess is correct
        if (strcmp(guess, players[current_player].password) == 0) {
            // The guess is correct, so the player wins
            printf("Player %d wins!\n", current_player + 1);
            break;
        } else {
            // The guess is incorrect, so the player's failed attempts increase
            players[current_player].failed_attempts++;

            // Check if the player has reached the maximum number of failed attempts
            if (players[current_player].failed_attempts >= MAX_FAILED_ATTEMPTS) {
                // The player has reached the maximum number of failed attempts, so they lose
                printf("Player %d loses!\n", current_player + 1);
                break;
            }
        }

        // Move to the next player
        current_player = (current_player + 1) % num_players;
    }

    return 0;
}