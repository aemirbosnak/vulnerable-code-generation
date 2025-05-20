//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast_message(const char *message, int ignore_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != ignore_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *handle_client(void *client_socket) {
    int socket = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client message: %s", buffer);
        broadcast_message(buffer, socket);
    }

    // Handle disconnection
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            client_sockets[i] = client_sockets[--client_count];
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(socket);
    printf("Client disconnected.\n");
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket failure");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failure");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failure");
        exit(EXIT_FAILURE);
    }
    printf("Chat server started. Waiting for connections...\n");

    // Infinite loop to accept clients
    while (1) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_socket < 0) {
            perror("Accept failure");
            exit(EXIT_FAILURE);
        }

        // Add client socket to the array
        pthread_mutex_lock(&clients_mutex);
        client_sockets[client_count++] = new_socket;
        pthread_mutex_unlock(&clients_mutex);
        printf("New client connected.\n");

        // Create a thread for handling client communication
        if (pthread_create(&tid, NULL, handle_client, (void *)&new_socket) != 0) {
            perror("Thread creation failure");
            exit(EXIT_FAILURE);
        }
        pthread_detach(tid);
    }

    close(server_socket);
    return 0;
}