//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PLAYERS 10

struct player {
    int id;
    int ram_usage;
};

struct player players[MAX_PLAYERS];
int num_players = 0;

void *monitor_thread(void *arg) {
    int player_id = *(int *) arg;

    while (1) {
        sleep(1);
        printf("Player %d RAM usage: %d bytes\n", player_id, players[player_id].ram_usage);
    }

    return NULL;
}

int main() {
    int i, choice;

    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = -1;
        players[i].ram_usage = 0;
    }

    while (1) {
        printf("\nRAM Usage Monitor\n");
        printf("1. Add player\n");
        printf("2. Remove player\n");
        printf("3. Display RAM usage\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_players >= MAX_PLAYERS) {
                    printf("Maximum number of players reached.\n");
                } else {
                    printf("Enter player ID: ");
                    scanf("%d", &players[num_players].id);
                    pthread_t thread_id;
                    pthread_create(&thread_id, NULL, monitor_thread, &players[num_players].id);
                    num_players++;
                }
                break;
            case 2:
                printf("Enter player ID to remove: ");
                scanf("%d", &players[num_players - 1].id);
                pthread_cancel(players[num_players - 1].id);
                num_players--;
                break;
            case 3:
                for (i = 0; i < num_players; i++) {
                    printf("Player %d RAM usage: %d bytes\n", players[i].id, players[i].ram_usage);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}