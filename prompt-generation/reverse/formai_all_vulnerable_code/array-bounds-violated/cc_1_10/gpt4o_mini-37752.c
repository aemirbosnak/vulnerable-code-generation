//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

// Function to handle client interaction
void *client_handler(void *client_info) {
    char buffer[BUFFER_SIZE];
    client_t *client = (client_t *)client_info;
    int received_bytes;

    // Continuously receive messages from the client
    while ((received_bytes = recv(client->socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[received_bytes] = '\0'; // Null terminate the received string

        printf("Received from client [%d]: %s\n", client->socket, buffer);

        // Echo the message back to the client
        send(client->socket, buffer, received_bytes, 0);
    }

    if (received_bytes == 0) {
        printf("Client [%d] disconnected.\n", client->socket);
    } else {
        perror("recv failed");
    }

    close(client->socket);
    free(client);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_addr_len = sizeof(client_address);
    pthread_t thread_id;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; // Bind to any available interface
    server_address.sin_port = htons(8080); // Port number

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080...\n");

    // Main loop to accept clients
    while (1) {
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        if (new_client == NULL) {
            perror("Failed to allocate memory for client");
            continue;
        }

        // Accept client connection
        new_client->addr_len = client_addr_len;
        new_client->socket = accept(server_socket, (struct sockaddr *)&new_client->address, &new_client->addr_len);
        if (new_client->socket < 0) {
            perror("Accept failed");
            free(new_client);
            continue;
        }

        printf("Client [%d] connected.\n", new_client->socket);

        // Create a new thread to handle client interaction
        if (pthread_create(&thread_id, NULL, client_handler, (void *)new_client) != 0) {
            perror("Thread creation failed");
            free(new_client);
        }

        // Detach the thread to allow it to clean up after itself
        pthread_detach(thread_id);
    }

    // Close the server socket
    close(server_socket);
    return 0;
}