//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024
#define PORT 8080

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_mutex_lock(&client_mutex);
        client_sockets[client_count++] = new_socket;
        pthread_mutex_unlock(&client_mutex);

        printf("New client connected: socket %d\n", new_socket);
        // Create a thread for each client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)(intptr_t)new_socket) != 0) {
            perror("Thread creation failed");
        }
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_socket = (intptr_t)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Message from client (socket %d): %s", client_socket, buffer);
        broadcast_message(buffer, client_socket);
    }

    // Client disconnected
    printf("Client disconnected: socket %d\n", client_socket);
    close(client_socket);

    // Remove client socket from the list
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[--client_count]; // Replace with last socket
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);
    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        // Send the message to all clients except the sender
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&client_mutex);
}