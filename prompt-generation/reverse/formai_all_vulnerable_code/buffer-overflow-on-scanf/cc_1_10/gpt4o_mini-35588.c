//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLAYERS 4

typedef struct {
    int id;
    char name[50];
    int is_connected;
} Player;

void initialize_players(Player players[], int size) {
    for (int i = 0; i < size; i++) {
        players[i].id = i + 1;
        players[i].is_connected = 0;  // All players are initially disconnected
        strcpy(players[i].name, "");  // Empty name
    }
}

void print_players(Player players[], int size) {
    printf("Current Players:\n");
    for (int i = 0; i < size; i++) {
        if (players[i].is_connected) {
            printf("ID: %d, Name: %s\n", players[i].id, players[i].name);
        }
    }
}

int connect_player(Player players[], int size) {
    for (int i = 0; i < size; i++) {
        if (!players[i].is_connected) {
            players[i].is_connected = 1;  // Mark player as connected
            return i;  // return the index of the new player
        }
    }
    fprintf(stderr, "Error: Maximum players reached. Cannot connect a new player.\n");
    return -1;  // Indicate failure
}

void disconnect_player(Player players[], int index) {
    if (players[index].is_connected) {
        players[index].is_connected = 0;  // Mark player as disconnected
        printf("Player %s has disconnected.\n", players[index].name);
        strcpy(players[index].name, "");  // Clear name
    } else {
        fprintf(stderr, "Error: Player ID %d is already disconnected.\n", players[index].id);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    initialize_players(players, MAX_PLAYERS);

    int operation;
    char player_name[50];

    while (1) {
        printf("\nMultiplayer Game Menu:\n");
        printf("1. Connect Player\n");
        printf("2. Disconnect Player\n");
        printf("3. Display Players\n");
        printf("4. Exit Game\n");
        printf("Select an operation: ");
        scanf("%d", &operation);

        switch (operation) {
            case 1: // Connect Player
                printf("Enter player name: ");
                scanf("%s", player_name);
                int player_index = connect_player(players, MAX_PLAYERS);
                if (player_index != -1) {
                    strcpy(players[player_index].name, player_name); // Assign name
                    printf("Player %s connected with ID %d\n", players[player_index].name, players[player_index].id);
                }
                break;

            case 2: // Disconnect Player
                printf("Enter player ID to disconnect (1 to %d): ", MAX_PLAYERS);
                int disconnect_id;
                scanf("%d", &disconnect_id);
                if (disconnect_id < 1 || disconnect_id > MAX_PLAYERS) {
                    fprintf(stderr, "Error: Invalid player ID. Please enter a valid ID.\n");
                } else {
                    disconnect_player(players, disconnect_id - 1); // Convert ID to index
                }
                break;

            case 3: // Display Players
                print_players(players, MAX_PLAYERS);
                break;

            case 4: // Exit Game
                printf("Exiting game.\n");
                exit(0);
                break;

            default:
                fprintf(stderr, "Error: Invalid operation selected. Please try again.\n");
                break;
        }
    }

    return 0;
}