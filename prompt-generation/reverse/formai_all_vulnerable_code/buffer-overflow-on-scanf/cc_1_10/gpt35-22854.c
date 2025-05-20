//FormAI DATASET v1.0 Category: Log analysis ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of players
#define MAX_PLAYERS 6

// Define the maximum number of turns
#define MAX_TURNS 10

// Define the maximum length of each log entry
#define LOG_ENTRY_LENGTH 100

// Define the maximum length of each player name
#define PLAYER_NAME_LENGTH 20

// Define the struct for the log entry
struct LogEntry {
    char message[LOG_ENTRY_LENGTH];
};

// Define the struct for each player
struct Player {
    char name[PLAYER_NAME_LENGTH];
    struct LogEntry log[MAX_TURNS];
    int num_turns_played;
};

// Define the function to get the name of a player
void get_player_name(char* name) {
    printf("Please enter the name of the player: ");
    scanf("%s", name);
}

// Define the function to get the log entry for a turn
void get_log_entry(char* entry) {
    printf("Please enter the log entry for this turn: ");
    scanf("%s", entry);
}

int main() {
    // Declare the array of players
    struct Player players[MAX_PLAYERS];

    // Declare the number of players
    int num_players;

    // Get the number of players
    do {
        printf("How many players are playing? (1-%d) ", MAX_PLAYERS);
        scanf("%d", &num_players);
    } while (num_players < 1 || num_players > MAX_PLAYERS);

    // Get the names of all the players
    for (int i = 0; i < num_players; i++) {
        get_player_name(players[i].name);
    }

    // Declare the current turn
    int current_turn = 1;

    // Loop through all turns
    while (current_turn <= MAX_TURNS) {
        printf("Turn %d:\n", current_turn);

        // Loop through all players
        for (int i = 0; i < num_players; i++) {
            printf("%s's turn:\n", players[i].name);

            // Get the log entry for this turn
            get_log_entry(players[i].log[players[i].num_turns_played].message);

            // Increment the number of turns played for this player
            players[i].num_turns_played++;
        }

        // Print the log for this turn
        printf("\nTurn %d Log:\n", current_turn);
        for (int i = 0; i < num_players; i++) {
            printf("%s's log: ", players[i].name);
            for (int j = 0; j < players[i].num_turns_played; j++) {
                printf("%s ", players[i].log[j].message);
            }
            printf("\n");
        }

        // Increment the current turn
        current_turn++;
    }

    return 0;
}