//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_PLAYERS 4
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    int player_id;
} player_t;

player_t players[MAX_PLAYERS];
int player_count = 0;

void *handle_client(void *arg) {
    player_t *player = (player_t *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Welcome message
    sprintf(buffer, "Welcome Player %d! Type 'exit' to leave.\n", player->player_id);
    send(player->sock, buffer, strlen(buffer), 0);
    
    while ((read_size = recv(player->sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }
        
        // Game logic can be added here
        sprintf(buffer, "Player %d says: %s", player->player_id, buffer);
        for (int i = 0; i < player_count; i++) {
            if (players[i].sock != player->sock) {
                send(players[i].sock, buffer, strlen(buffer), 0);
            }
        }
    }
    
    close(player->sock);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Poker game server started. Waiting for players...\n");

    while (player_count < MAX_PLAYERS) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        players[player_count].sock = new_socket;
        players[player_count].player_id = player_count + 1;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&players[player_count]);
        player_count++;
    }
    
    for (int i = 0; i < player_count; i++) {
        pthread_join(players[i].sock, NULL);
    }
    
    return 0;
}