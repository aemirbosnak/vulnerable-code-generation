//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr address;
    int addr_len;
} client_t;

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    printf("Client connected: %d\n", client->socket);
    
    while ((bytes_read = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received data
        printf("Received from client %d: %s\n", client->socket, buffer);
        
        // Echo the message back
        send(client->socket, buffer, bytes_read, 0);
    }

    printf("Client disconnected: %d\n", client->socket);
    close(client->socket);
    free(client);
    return NULL;
}

int main() {
    int server_socket, new_connection;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;
    
    // Creating socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        client_t *client = malloc(sizeof(client_t));
        if (!client) {
            perror("Failed to allocate memory for client");
            continue;
        }

        // Accept incoming connection
        client->socket = accept(server_socket, (struct sockaddr *)&client->address, &addr_len);
        if (client->socket < 0) {
            perror("Accept failed");
            free(client);
            continue;
        }

        // Create a new thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client) != 0) {
            perror("Thread creation failed");
            free(client);
            close(client->socket);
            continue;
        }

        // Detach the thread so it cleans up after itself
        pthread_detach(thread_id);
    }

    close(server_socket);
    return 0;
}