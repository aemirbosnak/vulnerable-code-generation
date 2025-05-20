//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *handle_client(void *arg);
void broadcast_message(char *message, int sender_socket);
int client_count = 0;
int client_sockets[MAX_CLIENTS];

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat Server started on port %d...\n", PORT);

    while (1) {
        // Accept a new client
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, (void *)&new_socket);
        } else {
            printf("Max clients reached. Connection rejected.\n");
            close(new_socket);
        }
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate the received message
        printf("Message received: %s", buffer);
        broadcast_message(buffer, client_socket);
    }

    // Remove client from the list
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            close(client_socket);
            client_sockets[i] = client_sockets[--client_count];
            break;
        }
    }
    return NULL;
}

void broadcast_message(char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}