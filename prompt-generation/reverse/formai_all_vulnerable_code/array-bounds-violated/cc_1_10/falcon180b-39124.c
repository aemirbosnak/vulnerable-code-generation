//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define MAX_CLIENTS 10
#define TRUE 1
#define FALSE 0
#define SERVER_PORT 8080

int client_sockets[MAX_CLIENTS];
int num_clients = 0;
int game_started = FALSE;

void broadcast(int sender_socket, char message[50]) {
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i]!= sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void handle_client(int client_socket) {
    char buffer[50];
    while (1) {
        memset(buffer, 0, 50);
        int bytes_received = recv(client_socket, buffer, 50, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            client_sockets[--num_clients] = 0;
            break;
        }
        broadcast(client_socket, buffer);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server is listening on port %d\n", SERVER_PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full", strlen("Server is full"), 0);
            close(client_socket);
            continue;
        }
        client_sockets[num_clients++] = client_socket;
        if (num_clients == 2) {
            game_started = TRUE;
        }
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void*)handle_client, (void*)client_socket);
    }

    return 0;
}