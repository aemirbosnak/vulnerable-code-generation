//FormAI DATASET v1.0 Category: Networking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_PLAYER 4
#define BUF_SIZE 1024

int player_count = 0;
int players[MAX_PLAYER];
int scores[MAX_PLAYER];

void *player_thread(void *player_id);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[1]);

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY,
    };
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }
    if (listen(server_sock, MAX_PLAYER) == -1) {
        perror("listen");
        exit(1);
    }
    printf("Waiting for %d players...\n", MAX_PLAYER);

    while (player_count < MAX_PLAYER) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }
        players[player_count++] = client_sock;
        printf("Player %d joined\n", player_count);
    }

    printf("All players have joined\n");

    pthread_t threads[MAX_PLAYER];
    for (int i = 0; i < MAX_PLAYER; i++) {
        if (pthread_create(&threads[i], NULL, player_thread, &players[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    for (int i = 0; i < MAX_PLAYER; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    return 0;
}

void *player_thread(void *player_id) {
    int sock = *(int *)player_id;
    char buf[BUF_SIZE];
    printf("Player %d: starting game\n", sock);

    while (1) {
        // Receive message from player
        ssize_t recv_size = recv(sock, buf, sizeof(buf), 0);
        if (recv_size == -1) {
            perror("recv");
            exit(1);
        }
        if (recv_size == 0) {
            printf("Player %d left\n", sock);
            close(sock);
            pthread_exit(NULL);
        }
        buf[recv_size] = '\0';
        printf("Player %d: received \"%s\"\n", sock, buf);

        // Update scores and broadcast to other players
        for (int i = 0; i < MAX_PLAYER; i++) {
            if (players[i] != sock) {
                sprintf(buf, "Player %d scored!\n", sock);
                ssize_t send_size = send(players[i], buf, strlen(buf), 0);
                if (send_size == -1) {
                    perror("send");
                    exit(1);
                }
                scores[i]++;
            }
        }

        // Check if the game is over
        int max_score = 0;
        for (int i = 0; i < MAX_PLAYER; i++) {
            if (scores[i] > max_score) {
                max_score = scores[i];
            }
        }
        if (max_score >= 10) {
            // End game
            for (int i = 0; i < MAX_PLAYER; i++) {
                sprintf(buf, "Game over!\n");
                ssize_t send_size = send(players[i], buf, strlen(buf), 0);
                if (send_size == -1) {
                    perror("send");
                    exit(1);
                }
            }
            printf("Game over!\n");
            exit(0);
        }
    }
}