//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define MAX_PLAYERS 5
#define PING_COUNT 4

typedef struct {
    char ip[16];
    int player_id;
    int ping_results[PING_COUNT];
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* ping_player(void* arg) {
    Player* player = (Player*) arg;
    struct sockaddr_in addr;
    int sockfd;
    char command[100];
    
    for (int i = 0; i < PING_COUNT; i++) {
        snprintf(command, sizeof(command), "ping -c 1 %s > /dev/null 2>&1", player->ip);
        clock_t start = clock();
        if (system(command) == 0) {
            clock_t end = clock();
            player->ping_results[i] = (int)((end - start) * 1000 / CLOCKS_PER_SEC); // ms
        } else {
            player->ping_results[i] = -1; // mark as unreachable
        }
        sleep(1); // pause between pings
    }
    
    return NULL;
}

void display_results() {
    for (int i = 0; i < player_count; i++) {
        printf("Player %d (IP: %s) Ping Results: ", players[i].player_id, players[i].ip);
        for (int j = 0; j < PING_COUNT; j++) {
            if (players[i].ping_results[j] == -1) {
                printf("Timeout ");
            } else {
                printf("%dms ", players[i].ping_results[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char buffer[100];
    pthread_t threads[MAX_PLAYERS];

    printf("Welcome to the Multiplayer Network Ping Test!\n");
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    fgets(buffer, sizeof(buffer), stdin);
    player_count = atoi(buffer);
    if (player_count > MAX_PLAYERS) {
        player_count = MAX_PLAYERS;
    }

    for (int i = 0; i < player_count; i++) {
        printf("Enter the IP address for Player %d: ", i + 1);
        fgets(players[i].ip, sizeof(players[i].ip), stdin);
        players[i].ip[strcspn(players[i].ip, "\n")] = 0; // removing newline
        players[i].player_id = i + 1;

        pthread_create(&threads[i], NULL, ping_player, (void*) &players[i]);
    }

    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL); // waits for all threads to finish
    }

    display_results();

    return 0;
}