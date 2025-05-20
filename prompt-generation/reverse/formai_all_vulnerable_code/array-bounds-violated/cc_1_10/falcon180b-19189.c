//Falcon-180B DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 10
#define MAX_LINE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender_socket, char *message) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i]!= sender_socket) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}

void handle_client(int client_socket) {
    char buffer[MAX_LINE];
    while (1) {
        memset(buffer, 0, MAX_LINE);
        int bytes_received = recv(client_socket, buffer, MAX_LINE, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            return;
        }
        buffer[bytes_received - 1] = '\0';
        printf("[%d] %s\n", client_socket, buffer);
        broadcast(client_socket, buffer);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket\n");
        return 2;
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Failed to listen on socket\n");
        return 3;
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket!= -1) {
            printf("Client connected: %d\n", client_socket);
            clients[num_clients++] = client_socket;
            if (num_clients >= MAX_CLIENTS) {
                printf("Maximum number of clients reached\n");
                close(client_socket);
                continue;
            }
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
        }
    }

    return 0;
}