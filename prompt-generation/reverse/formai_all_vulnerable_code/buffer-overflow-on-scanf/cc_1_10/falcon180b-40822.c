//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_PLAYERS 10

struct player {
    int id;
    char name[20];
    int score;
};

struct player players[MAX_PLAYERS];
int num_players = 0;

void add_player(int id, char* name) {
    if (num_players >= MAX_PLAYERS) {
        printf("Maximum number of players reached!\n");
        return;
    }
    players[num_players].id = id;
    strcpy(players[num_players].name, name);
    num_players++;
}

void remove_player(int id) {
    int i;
    for (i = 0; i < num_players; i++) {
        if (players[i].id == id) {
            printf("Player %s removed from the game.\n", players[i].name);
            num_players--;
            return;
        }
    }
    printf("Player not found!\n");
}

void display_players() {
    int i;
    printf("Players:\n");
    for (i = 0; i < num_players; i++) {
        printf("%d. %s\n", i+1, players[i].name);
    }
}

void* monitor_cpu_usage(void* arg) {
    int i;
    while (1) {
        for (i = 0; i < num_players; i++) {
            FILE* fp;
            char filename[50];
            sprintf(filename, "cpu_usage_%d.txt", players[i].id);
            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("Player %s disconnected!\n", players[i].name);
                remove_player(players[i].id);
                break;
            }
            fclose(fp);
        }
        sleep(5);
    }
}

int main() {
    int i;
    pthread_t threads[MAX_PLAYERS];

    printf("Multiplayer CPU Usage Monitor\n");
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i+1);
        scanf("%s", players[i].name);
        players[i].id = i+1;
        players[i].score = 0;
        pthread_create(&threads[i], NULL, monitor_cpu_usage, (void*)&players[i]);
    }

    while (1) {
        display_players();
        sleep(10);
    }

    return 0;
}