//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 12345
#define BUFFER_SIZE 256
#define CLIENT_LIMIT 10

int clients[CLIENT_LIMIT];
int client_count = 0;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];

    while (1) {
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Client says: %s\n", buffer);

        // Broadcast the message to all clients
        for (int i = 0; i < client_count; i++) {
            if (clients[i] != sock) {
                send(clients[i], buffer, bytes_received, 0);
            }
        }
    }

    close(sock);
    return NULL;
}

int main() {
    int server_socket, new_client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        new_client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (new_client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        if (client_count < CLIENT_LIMIT) {
            clients[client_count++] = new_client_socket;
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, (void *)&new_client_socket);
            printf("New client connected!\n");
        } else {
            printf("Client limit reached; rejecting new client.\n");
            close(new_client_socket);
        }
    }
    
    close(server_socket);
    return 0;
}