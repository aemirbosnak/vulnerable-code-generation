//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *socket_descriptor);
void broadcast_message(const char *message, int sender_socket);

int main() {
    int server_fd, client_socket, addr_len;
    struct sockaddr_in address;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting the address and port for the server
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
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

    printf("Chat Server started! Awaiting connections...\n");

    while (1) {
        addr_len = sizeof(address);
        // Accept an incoming connection
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len)) < 0) {
            perror("Accept failed");
            continue; // continue to next iteration on failure
        }

        // Add the new client socket to the list
        client_sockets[client_count++] = client_socket;

        // Create a thread for the newly connected client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Thread creation failed");
        }

        printf("Client connected, total clients: %d\n", client_count);
    }
    
    return 0;
}

void *handle_client(void *socket_descriptor) {
    int sock = *(int *)socket_descriptor;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Client greeting
    char welcome_message[] = "Welcome to the chat server!\n";
    send(sock, welcome_message, sizeof(welcome_message), 0);

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received data
        printf("Received: %s", buffer);
        
        // Broadcast message to all clients except sender
        broadcast_message(buffer, sock);
    }

    if (read_size == 0) {
        printf("Client disconnected, cleaning up...\n");
        close(sock);
    } else if (read_size == -1) {
        perror("Recv failed");
    }

    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}