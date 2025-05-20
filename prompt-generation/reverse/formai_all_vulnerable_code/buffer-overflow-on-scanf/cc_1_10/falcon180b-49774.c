//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_MSG_LEN 1024

typedef struct player {
    char name[32];
    char msg[MAX_MSG_LEN];
    int len;
} player_t;

player_t players[MAX_PLAYERS];
int num_players;

void add_player() {
    if (num_players >= MAX_PLAYERS) {
        printf("Maximum number of players reached.\n");
        return;
    }

    int i = num_players;
    printf("Enter name for player %d:\n", i);
    scanf("%s", players[i].name);
    printf("Welcome, %s!\n", players[i].name);

    num_players++;
}

void remove_player(int id) {
    if (id < 0 || id >= num_players) {
        printf("Invalid player ID.\n");
        return;
    }

    printf("Player %s has left the game.\n", players[id].name);

    for (int i = id; i < num_players - 1; i++) {
        memcpy(&players[i], &players[i+1], sizeof(player_t));
    }

    num_players--;
}

void send_message(int id) {
    if (id < 0 || id >= num_players) {
        printf("Invalid player ID.\n");
        return;
    }

    printf("Enter message for player %s:\n", players[id].name);
    scanf("%s", players[id].msg);
    players[id].len = strlen(players[id].msg);
}

void summarize_messages() {
    for (int i = 0; i < num_players; i++) {
        if (players[i].len > 0) {
            printf("Player %s: %s\n", players[i].name, players[i].msg);
        }
    }
}

int main() {
    num_players = 0;

    while (1) {
        printf("1. Add player\n2. Remove player\n3. Send message\n4. Summarize messages\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_player();
                break;
            case 2:
                printf("Enter player ID to remove:\n");
                int id;
                scanf("%d", &id);
                remove_player(id);
                break;
            case 3:
                printf("Enter player ID to send message:\n");
                int send_id;
                scanf("%d", &send_id);
                send_message(send_id);
                break;
            case 4:
                summarize_messages();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}