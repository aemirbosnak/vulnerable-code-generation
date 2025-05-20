//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/sysinfo.h>
#include <sys/time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 20

typedef struct player {
    char name[MAX_NAME_LEN];
    int id;
    int ram_usage;
} Player;

int player_count = 0;
Player players[MAX_PLAYERS];

void *monitor_ram(void *arg) {
    int id = *(int *) arg;
    Player *player = &players[id];

    while (1) {
        struct sysinfo info;
        sysinfo(&info);
        player->ram_usage = info.totalram - info.freeram;

        sleep(1);
    }

    return NULL;
}

int main() {
    int i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = -1;
    }

    pthread_t threads[MAX_PLAYERS];

    while (1) {
        printf("Enter player name: ");
        scanf("%s", players[player_count].name);
        players[player_count].id = player_count;
        player_count++;

        if (player_count == MAX_PLAYERS) {
            break;
        }
    }

    for (i = 0; i < player_count; i++) {
        pthread_create(&threads[i], NULL, monitor_ram, &players[i].id);
    }

    while (1) {
        printf("\nPlayer ID | Player Name | RAM Usage\n");
        for (i = 0; i < player_count; i++) {
            printf("%d | %s | %d KB\n", players[i].id, players[i].name, players[i].ram_usage / 1024);
        }

        sleep(1);
    }

    return 0;
}