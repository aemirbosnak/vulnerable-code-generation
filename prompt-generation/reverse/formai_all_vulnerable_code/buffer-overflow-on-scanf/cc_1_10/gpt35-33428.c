//FormAI DATASET v1.0 Category: System event logger ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10

struct Event {
    int player_id;
    char description[100];
    time_t timestamp;
};

int num_players;
int num_events;

struct Event events[1000];
int event_index = 0;

void add_event(int player_id, char *desc) {
    events[event_index].player_id = player_id;
    strcpy(events[event_index].description, desc);
    events[event_index].timestamp = time(NULL);
    event_index++;
    printf("Event added for Player %d: %s\n", player_id, desc);
}

void list_events() {
    printf("Event Log:\n");
    for (int i = 0; i < event_index; i++) {
        printf("%d: Player %d - %s (%s)", i+1, events[i].player_id, events[i].description, ctime(&events[i].timestamp));
    }
}

int main() {
    printf("Welcome to the Multiplayer System Event Logger!\n");
    printf("How many players? (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    if (num_players <= 0 || num_players > MAX_PLAYERS) {
        printf("Invalid input. Terminating program.\n");
        exit(1);
    }

    char player_names[num_players][20];
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for Player %d: ", i+1);
        scanf("%s", player_names[i]);
    }

    char choice = ' ';
    while (choice != 'q') {
        printf("\nChoose an option:\n");
        printf("a) Add event\n");
        printf("b) List all events\n");
        printf("q) Quit program\n");
        printf(">> ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': {
                int player_id;
                printf("Enter player ID (1-%d): ", num_players);
                scanf("%d", &player_id);
                if (player_id < 1 || player_id > num_players) {
                    printf("Invalid ID. Try again.\n");
                    break;
                }
                char desc[100];
                printf("Enter event description: ");
                scanf("%s", desc);
                add_event(player_id, desc);
                break;
            }
            case 'b':
                list_events();
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}