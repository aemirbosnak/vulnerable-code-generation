//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_MSG_LEN 1024
#define PORT 8080

typedef struct {
    char name[MAX_NAME_LEN];
    int sock;
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void *handle_client(void *arg) {
    int client_sock = *(int *) arg;
    char msg[MAX_MSG_LEN];
    while (true) {
        memset(msg, 0, MAX_MSG_LEN);
        int len = recv(client_sock, msg, MAX_MSG_LEN, 0);
        if (len <= 0) {
            break;
        }
        printf("Client %s sent message: %s\n", players[client_sock - 3].name, msg);
        for (int i = 0; i < num_players; i++) {
            if (i!= client_sock - 3) {
                send(players[i].sock, msg, strlen(msg), 0);
            }
        }
    }
    close(client_sock);
    return NULL;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, 5);

    printf("Server started on port %d\n", PORT);

    while (true) {
        int client_sock = accept(server_sock, NULL, NULL);
        if (num_players >= MAX_PLAYERS) {
            send(client_sock, "Server full", strlen("Server full"), 0);
            close(client_sock);
            continue;
        }
        players[num_players].sock = client_sock;
        printf("Client %d connected\n", num_players + 3);
        num_players++;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_sock);
    }

    return 0;
}