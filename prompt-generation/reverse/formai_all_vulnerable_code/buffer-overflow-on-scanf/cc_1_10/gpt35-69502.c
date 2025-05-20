//FormAI DATASET v1.0 Category: System event logger ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_EVENTS 100

// Define structures to hold the player data and event logs
struct Player {
    int id;
    char name[20];
};

struct Event {
    int id;
    char description[50];
    int player_id;
};

// Declare global variables
struct Player players[MAX_PLAYERS];
struct Event events[MAX_EVENTS];
int num_players = 0;
int num_events = 0;

// Function to add a new player to the game
void add_player() {
    if (num_players < MAX_PLAYERS) {
        printf("\nEnter the name of the new player: ");
        scanf("%s", players[num_players].name);
        players[num_players].id = num_players + 1;
        printf("\nNew player added with ID %d\n", players[num_players].id);
        num_players++;
    } else {
        printf("\nError: Maximum number of players already reached.\n");
    }
}

// Function to log a new event in the game
void log_event() {
    if (num_events < MAX_EVENTS) {
        int player_id;
        printf("\nEnter the ID of the player who triggered the event: ");
        scanf("%d", &player_id);
        if (player_id > 0 && player_id <= num_players) {
            printf("\nEnter a brief description of the event: ");
            scanf("%s", events[num_events].description);
            events[num_events].id = num_events + 1;
            events[num_events].player_id = player_id;
            printf("\nNew event logged with ID %d\n", events[num_events].id);
            num_events++;
        } else {
            printf("\nError: Invalid player ID.\n");
        }
    } else {
        printf("\nError: Maximum number of events already reached.\n");
    }
}

// Function to display a summary of all events in the game
void view_events() {
    printf("\nEvent Log:\n\n");
    for (int i = 0; i < num_events; i++) {
        printf("Event ID: %d\n", events[i].id);
        printf("Description: %s\n", events[i].description);
        printf("Player ID: %d\n", events[i].player_id);
        printf("Player Name: %s\n\n", players[events[i].player_id - 1].name);
    }
}

// Main function to run the game
int main() {
    int choice;
    printf("Welcome to the Game Event Logger!\n\n");
    printf("What would you like to do?\n");
    printf("1. Add a new player\n");
    printf("2. Log a new event\n");
    printf("3. View all events\n");
    printf("4. Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_player();
                break;
            case 2:
                log_event();
                break;
            case 3:
                view_events();
                break;
            case 4:
                exit(0);
            default:
                printf("\nError: Invalid choice.\n");
        }
    }
    return 0;
}