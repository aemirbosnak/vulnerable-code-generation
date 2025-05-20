//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256
#define PORT 8080

// Structure to hold client data
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

// Global variables
client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to broadcast messages to all clients
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle each client
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];

    // Receive messages from client
    while (1) {
        ssize_t bytes_received = recv(client->socket, buffer, sizeof(buffer)-1, 0);
        if (bytes_received <= 0) {
            break; // Client has disconnected
        }
        
        buffer[bytes_received] = '\0'; // Null-terminate the message
        printf("Client %d: %s", client->socket, buffer);
        broadcast_message(buffer, client->socket); // Broadcast the message
    }

    // Cleanup on disconnect
    close(client->socket);
    free(client);
    return NULL;
}

// Main server function
int main() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept new client connections
        client_t *new_client = malloc(sizeof(client_t));
        if (!new_client) {
            perror("Failed to allocate memory");
            continue;
        }

        new_client->socket = accept(server_socket, (struct sockaddr *)&new_client->address, &client_len);
        if (new_client->socket < 0) {
            perror("Accepting client failed");
            free(new_client);
            continue;
        }

        // Add client to the global array
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = new_client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create thread for handling the client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_client) != 0) {
            perror("Failed to create thread");
            close(new_client->socket);
            free(new_client);
        }
    }

    // Cleanup (not reached; server runs indefinitely)
    close(server_socket);
    return 0;
}