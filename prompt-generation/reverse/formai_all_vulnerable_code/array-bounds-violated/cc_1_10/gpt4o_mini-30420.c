//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr address;
    int addr_len;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to broadcast messages to all connected clients
void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle client connection
void *handle_client(void *arg) {
    client_t *cli = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(cli->socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0'; // Null-terminate the string
        printf("Received: %s", buffer);
        broadcast_message(buffer, cli->socket);
    }

    // Remove client and close socket
    close(cli->socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == cli) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(cli);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Chat server started on port %d\n", PORT);

    while (1) {
        client_t *cli = malloc(sizeof(client_t));
        if (!cli) {
            perror("Could not allocate memory for client");
            continue;
        }

        cli->addr_len = sizeof(client_addr);
        cli->socket = accept(server_socket, &cli->address, &cli->addr_len);
        if (cli->socket < 0) {
            free(cli);
            perror("Accept failed");
            continue;
        }

        // Add client to the clients array
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = cli;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread for handling the client
        if (pthread_create(&tid, NULL, handle_client, (void *)cli) != 0) {
            perror("Failed to create thread");
            close(cli->socket);
            free(cli);
        } else {
            pthread_detach(tid); // Detach the thread to avoid memory leaks
        }
    }

    // Close server socket (unreachable in this case)
    close(server_socket);
    return 0;
}