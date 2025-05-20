//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *socket_desc);
void broadcast_message(const char *message, int sender_socket);

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept a new client
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected: socket %d\n", new_socket);

        // Store the client socket
        client_sockets[client_count++] = new_socket;

        // Create a new thread for the client
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, (void *)&new_socket) != 0) {
            perror("Thread creation failed");
            close(new_socket);
            continue;
        }
    }

    close(server_fd);
    return 0;
}

void *handle_client(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received message: %s", buffer);
        broadcast_message(buffer, sock);
    }

    // Client disconnected
    close(sock);
    printf("Client disconnected: socket %d\n", sock);

    // Remove client socket from array (optional; not thread-safe)
    for (int i = 0; i < client_count; ++i) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[--client_count]; // Simple removal
            printf("Removed socket %d from client list\n", sock);
            break;
        }
    }
    
    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < client_count; ++i) {
        // Avoid sending the message back to the sender
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}