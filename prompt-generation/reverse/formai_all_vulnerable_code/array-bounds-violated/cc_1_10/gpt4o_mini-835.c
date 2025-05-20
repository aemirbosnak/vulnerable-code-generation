//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int clients[MAX_CLIENTS];
int client_count = 0;

void broadcast_message(const char *message, int sender) {
    for(int i = 0; i < client_count; i++) {
        if(clients[i] != sender) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}

void *client_handler(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client: %s\n", buffer);
        broadcast_message(buffer, client_socket);
    }

    printf("Client disconnected.\n");
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    pthread_t tid;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started. Waiting for clients to connect...\n");

    while ((new_socket = accept(server_socket, (struct sockaddr *)&address, &addrlen)) >= 0) {
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = new_socket;
            printf("New client connected, total clients: %d\n", client_count);
            pthread_create(&tid, NULL, client_handler, (void *)&new_socket);
        } else {
            printf("Maximum clients connected, rejecting new client.\n");
            close(new_socket);
        }
    }

    return 0;
}