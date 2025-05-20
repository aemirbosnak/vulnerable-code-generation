//FormAI DATASET v1.0 Category: Log analysis ; Style: multiplayer
// Multiplayer Log Analysis Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_OF_PLAYERS 10
#define MAX_LOG_ENTRIES 100

struct LogEntry {
    char player[20];
    char action[50];
};

struct PlayerStats {
    char name[20];
    int num_of_actions;
    int total_actions_time;
};

int main() {
    // Declare variables
    int num_of_players;
    struct PlayerStats players[MAX_NUM_OF_PLAYERS];
    struct LogEntry log[MAX_LOG_ENTRIES];

    // Get number of players from user
    printf("Enter number of players (Maximum %d): ", MAX_NUM_OF_PLAYERS);
    scanf("%d", &num_of_players);

    // Get player names from user
    for (int i = 0; i < num_of_players; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].num_of_actions = 0;
        players[i].total_actions_time = 0;
    }

    // Get log entries from user
    int num_of_log_entries;
    printf("Enter number of log entries (Maximum %d): ", MAX_LOG_ENTRIES);
    scanf("%d", &num_of_log_entries);

    for (int i = 0; i < num_of_log_entries; i++) {
        printf("Enter log entry %d player name: ", i + 1);
        scanf("%s", log[i].player);
        printf("Enter log entry %d action: ", i + 1);
        scanf("%s", log[i].action);
    }

    // Calculate player stats
    for (int i = 0; i < num_of_log_entries; i++) {
        for (int j = 0; j < num_of_players; j++) {
            if (strcmp(log[i].player, players[j].name) == 0) {
                players[j].num_of_actions++;
                players[j].total_actions_time += strlen(log[i].action);
            }
        }
    }

    // Display player stats
    printf("\nPlayer Stats\n");
    printf("-------------\n");

    for (int i = 0; i < num_of_players; i++) {
        printf("%s\n", players[i].name);
        printf("Number of actions: %d\n", players[i].num_of_actions);
        printf("Total actions time: %d\n", players[i].total_actions_time);
        printf("\n");
    }

    return 0;
}