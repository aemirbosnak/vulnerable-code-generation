//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/sysinfo.h>

#define MAX_PLAYERS 100
#define MAX_NAME_LEN 64

struct player {
    char name[MAX_NAME_LEN];
    int score;
    int ram_usage;
};

struct player players[MAX_PLAYERS];
int num_players = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* monitor_thread(void* arg) {
    while (1) {
        sleep(5);
        for (int i = 0; i < num_players; i++) {
            pthread_mutex_lock(&lock);
            struct player* player = &players[i];
            player->ram_usage = get_ram_usage();
            pthread_mutex_unlock(&lock);
        }
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, monitor_thread, NULL);

    while (1) {
        char input[MAX_NAME_LEN];
        printf("Enter your name: ");
        scanf("%s", input);

        if (num_players >= MAX_PLAYERS) {
            printf("Sorry, the game is full.\n");
            continue;
        }

        strcpy(players[num_players].name, input);
        players[num_players].score = 0;
        players[num_players].ram_usage = get_ram_usage();
        num_players++;

        printf("Welcome to the game, %s!\n", input);
        printf("Your score is 0 and your RAM usage is %d bytes.\n", players[num_players-1].ram_usage);
    }

    return 0;
}

int get_ram_usage() {
    struct sysinfo info;
    sysinfo(&info);
    return info.totalram - info.freeram;
}