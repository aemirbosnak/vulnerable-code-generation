//FormAI DATASET v1.0 Category: Networking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_PLAYERS 5
#define MAX_NAME_LEN 20

typedef struct {
    int socket_desc;
    char name[MAX_NAME_LEN];
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void *handle_client(void *arg) {
    Player *player = (Player *) arg;
    char message[100];

    while (true) {
        int read_size = recv(player->socket_desc, message, sizeof(message), 0);
        if (read_size == 0) {
            printf("Player %s disconnected.", player->name);
            close(player->socket_desc);
            pthread_exit(NULL);
        } else if (read_size > 0) {
            for (int i = 0; i < num_players; i++) {
                Player *other_player = &players[i];
                if (other_player != player) {
                    send(other_player->socket_desc, message, read_size, 0);
                }
            }
        }
    }
}

void accept_clients(int server_socket_desc) {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    while (num_players < MAX_PLAYERS) {
        int client_socket_desc = accept(server_socket_desc, (struct sockaddr *) &client_addr, &addr_len);
        if (client_socket_desc < 0) {
            printf("Failed to accept client.\n");
            continue;
        }

        if (num_players >= MAX_PLAYERS) {
            char message[] = "Max players reached.\n";
            send(client_socket_desc, message, sizeof(message), 0);
            close(client_socket_desc);
            continue;
        }
        
        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        // Request player name
        char name[MAX_NAME_LEN];
        char prompt[] = "Enter your name: ";
        send(client_socket_desc, prompt, sizeof(prompt), 0);
        int name_len = recv(client_socket_desc, name, MAX_NAME_LEN, 0);
        name[name_len - 1] = '\0';

        Player player = {
            .socket_desc = client_socket_desc,
        };
        strcpy(player.name, name);
        players[num_players] = player;
        num_players++;

        // Start thread to handle client
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &player);
    }
}

int main(int argc, char *argv[]) {
    // Create server socket
    int server_socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_desc == -1) {
        printf("Failed to create socket.\n");
        return 1;
    }

    // Bind socket to port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(8888),
    };
    if (bind(server_socket_desc, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket to port.\n");
        return 1;
    }

    // Listen for clients
    if (listen(server_socket_desc, MAX_PLAYERS) < 0) {
        printf("Failed to listen for clients.\n");
        return 1;
    }

    // Accept clients and start game
    printf("Waiting for clients to connect...\n");
    accept_clients(server_socket_desc);

    return 0;
}