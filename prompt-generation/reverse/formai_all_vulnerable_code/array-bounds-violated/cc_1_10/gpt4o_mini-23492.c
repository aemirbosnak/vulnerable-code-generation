//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_count = 0;
int client_fds[MAX_CLIENTS];

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_fd);

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Define socket attributes
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d.\n", PORT);

    // Accept clients
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept");
            exit(EXIT_FAILURE);
        }

        if (client_count < MAX_CLIENTS) {
            client_fds[client_count++] = new_socket;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *)(intptr_t)new_socket);
        } else {
            const char *full_msg = "Server is full. Try again later.\n";
            send(new_socket, full_msg, strlen(full_msg), 0);
            close(new_socket);
        }
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_socket = (int)(intptr_t)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Handle messages from client
    while ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Client says: %s", buffer);
        
        // Remove newline from string for broadcasting
        buffer[strcspn(buffer, "\n")] = '\0';
        broadcast_message(buffer, client_socket);
    }

    // Handle disconnection
    close(client_socket);
    for (int i = 0; i < client_count; i++) {
        if (client_fds[i] == client_socket) {
            client_fds[i] = client_fds[--client_count];
            break;
        }
    }

    return NULL;
}

void broadcast_message(const char *message, int sender_fd) {
    char send_buffer[BUFFER_SIZE + 50];
    snprintf(send_buffer, sizeof(send_buffer), "Client %d: %s\n", sender_fd, message);

    for (int i = 0; i < client_count; i++) {
        if (client_fds[i] != sender_fd) {
            send(client_fds[i], send_buffer, strlen(send_buffer), 0);
        }
    }
}