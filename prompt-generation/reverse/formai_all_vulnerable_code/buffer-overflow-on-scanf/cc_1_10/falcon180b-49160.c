//Falcon-180B DATASET v1.0 Category: System event logger ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 100

struct player {
    char name[20];
    int events[MAX_EVENTS];
    int num_events;
};

void add_event(struct player *player, char *event) {
    int i;
    for (i = 0; i < player->num_events; i++) {
        if (strcmp(player->events[i], event) == 0) {
            return;
        }
    }
    strcpy(player->events[player->num_events], event);
    player->num_events++;
}

void print_events(struct player *player) {
    int i;
    for (i = 0; i < player->num_events; i++) {
        printf("%s\n", player->events[i]);
    }
}

int main() {
    struct player players[MAX_PLAYERS];
    int num_players = 0;
    char input[MAX_EVENT_LENGTH];
    time_t start_time;
    time(&start_time);
    srand(start_time);

    while (num_players < MAX_PLAYERS) {
        printf("Enter a player name: ");
        scanf("%s", input);
        int i;
        for (i = 0; i < num_players; i++) {
            if (strcmp(players[i].name, input) == 0) {
                printf("Player already exists.\n");
                break;
            }
        }
        if (i == num_players) {
            strcpy(players[num_players].name, input);
            num_players++;
        }
    }

    int player_index;
    while (1) {
        printf("Enter player index: ");
        scanf("%d", &player_index);
        if (player_index >= 0 && player_index < num_players) {
            break;
        }
        printf("Invalid player index.\n");
    }

    while (1) {
        printf("Enter event: ");
        scanf("%s", input);
        add_event(&players[player_index], input);
        printf("Event added.\n");
    }

    return 0;
}