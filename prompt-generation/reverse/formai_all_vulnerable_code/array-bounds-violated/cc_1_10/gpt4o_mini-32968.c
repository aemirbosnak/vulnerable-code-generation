//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_sock);

int client_sockets[MAX_CLIENTS];
int clients_count = 0;

int main() {
    int server_socket, new_client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Set socket options to allow reuse of the address
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        close(server_socket);
        exit(1);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on any available address
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(1);
    }

    printf("Chat server is running on port %d...\n", PORT);

    while (1) {
        new_client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (new_client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        if (clients_count < MAX_CLIENTS) {
            client_sockets[clients_count++] = new_client_socket;
            printf("Client connected: %d\n", new_client_socket);
    
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void*)&new_client_socket);
            pthread_detach(thread_id);
        } else {
            const char *message = "Chat room is full! Please try again later.\n";
            send(new_client_socket, message, strlen(message), 0);
            close(new_client_socket);
        }
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the message

        printf("Received from %d: %s", client_socket, buffer);

        // Broadcast the message to other clients
        broadcast_message(buffer, client_socket);
    }

    // Client disconnected
    printf("Client %d disconnected.\n", client_socket);
    close(client_socket);

    // Remove the client from the list
    for (int i = 0; i < clients_count; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[clients_count - 1];
            clients_count--;
            break;
        }
    }

    return NULL;
}

void broadcast_message(const char *message, int sender_sock) {
    for (int i = 0; i < clients_count; i++) {
        if (client_sockets[i] != sender_sock) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}