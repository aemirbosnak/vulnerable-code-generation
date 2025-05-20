//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PLAYERS 20

// Struct to hold player information
typedef struct Player {
    char username[20];
    bool logged_in;
} Player;

// Function to check if a username already exists
bool username_exists(Player players[], int num_players, char username[]) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].username, username) == 0) {
            return true;
        }
    }
    return false;
}

// Function to authenticate a player's login
bool authenticate_login(Player players[], int num_players, char username[]) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].username, username) == 0) {
            players[i].logged_in = true;
            return true;
        }
    }
    return false;
}

// Function to handle malicious activity
void handle_intrusion(Player players[], int num_players, char username[]) {
    printf("INTRUSION DETECTED: %s has been locked out of the game.\n", username);
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].username, username) == 0) {
            players[i].logged_in = false;
            break;
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players = 0;

    // Loop to add players to the game
    char choice;
    do {
        printf("Enter a username for a new player: ");
        char username[20];
        scanf("%s", username);

        // Check if username already exists
        if (username_exists(players, num_players, username)) {
            printf("That username already exists. Try again.\n");
            continue;
        }

        // Add player to game
        printf("Added player %s\n", username);
        strcpy(players[num_players].username, username);
        players[num_players].logged_in = false;
        num_players++;

        // Ask if user wants to add another player
        printf("Do you want to add another player? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Game loop
    char input[20];
    while (true) {
        printf("\nEnter a username to log in or 'quit' to exit: ");
        scanf("%s", input);

        // Quit game
        if (strcmp(input, "quit") == 0) {
            printf("Exiting game.\n");
            break;
        }

        // Authenticate login
        if (authenticate_login(players, num_players, input)) {
            printf("%s has logged in.\n", input);
        } else {
            printf("Invalid username.\n");
            continue;
        }

        // Check for malicious activity
        int num_logins = 0;
        for (int i = 0; i < num_players; i++) {
            if (strcmp(players[i].username, input) == 0 && players[i].logged_in) {
                num_logins++;
                if (num_logins > 1) {
                    handle_intrusion(players, num_players, input);
                    break;
                }
            }
        }
    }

    return 0;
}