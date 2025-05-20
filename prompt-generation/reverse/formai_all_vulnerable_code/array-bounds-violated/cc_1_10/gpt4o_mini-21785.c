//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: synchronous
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

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d: %s", client_socket, buffer);
        // Broadcast received message to all clients
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != client_socket) { // Don't send to the sender
                send(client_sockets[i], buffer, bytes_received, 0);
            }
        }
    }

    // Remove the client from the array after disconnecting
    close(client_socket);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[--client_count]; // Replace with last element
            break;
        }
    }
    printf("Client %d disconnected.\n", client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d.\n", PORT);

    while (1) {
        // Accept a new client
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
            perror("Client accept failed");
            continue; // Skip this iteration on failure
        }

        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_socket;
            printf("Client %d connected.\n", client_socket);

            // Create a new thread for the connected client
            if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket) != 0) {
                perror("Thread creation failed");
                close(client_socket);
                continue; // Skip this iteration on failure
            }
            pthread_detach(thread_id); // Detach the thread to free resources on exit
        } else {
            printf("Maximum clients reached. Rejecting client %d.\n", client_socket);
            close(client_socket); // Reject and close the socket if max clients reached
        }
    }

    // Close server socket
    close(server_socket);
    return 0;
}