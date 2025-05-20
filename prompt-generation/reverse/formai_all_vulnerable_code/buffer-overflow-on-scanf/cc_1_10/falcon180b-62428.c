//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PLAYERS 10
#define MAX_RAM_USAGE 10000000

typedef struct {
    char name[20];
    int ram_usage;
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void *monitor_ram_usage(void *arg) {
    int i;
    struct rusage usage;
    int ram_usage;

    while (1) {
        getrusage(RUSAGE_SELF, &usage);
        ram_usage = (int) (usage.ru_maxrss / 1024);

        for (i = 0; i < num_players; i++) {
            if (ram_usage > players[i].ram_usage) {
                players[i].ram_usage = ram_usage;
                players[i].score++;
            }
        }

        usleep(100000);
    }

    return NULL;
}

int main() {
    int i, j, choice;
    char input[20];

    num_players = 0;

    while (1) {
        system("clear");
        printf("RAM Usage Monitor\n");

        for (i = 0; i < num_players; i++) {
            printf("%s - RAM Usage: %d KB - Score: %d\n", players[i].name, players[i].ram_usage, players[i].score);
        }

        printf("Enter player name (max 20 characters): ");
        scanf("%s", input);

        for (i = 0; i < num_players; i++) {
            if (strcmp(input, players[i].name) == 0) {
                printf("%s is already playing.\n", input);
                break;
            }
        }

        if (i == num_players) {
            if (num_players < MAX_PLAYERS) {
                strcpy(players[num_players].name, input);
                players[num_players].ram_usage = 0;
                players[num_players].score = 0;
                num_players++;

                pthread_t thread_id;
                pthread_create(&thread_id, NULL, monitor_ram_usage, NULL);

                printf("%s has joined the game.\n", input);
            } else {
                printf("Maximum number of players reached.\n");
            }
        }

        printf("Press 1 to quit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            break;
        }
    }

    return 0;
}