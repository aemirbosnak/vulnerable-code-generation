//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int clients[MAX_CLIENTS];
pthread_mutex_t clients_lock;

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t tid;

    // Initialize mutex
    pthread_mutex_init(&clients_lock, NULL);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server address configuration
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for clients
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("Chat server started on port %d\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size)) < 0) {
            perror("Accept failed");
            continue;
        }
        printf("New client connected: %d\n", client_socket);

        // Lock clients array
        pthread_mutex_lock(&clients_lock);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == 0) {
                clients[i] = client_socket;
                break;
            }
        }
        pthread_mutex_unlock(&clients_lock);

        // Create thread for each client
        pthread_create(&tid, NULL, handle_client, (void *)&client_socket);
    }

    close(server_socket);
    pthread_mutex_destroy(&clients_lock);
    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0'; // Null-terminate the string
        printf("Message from client %d: %s\n", client_socket, buffer);
        broadcast_message(buffer, client_socket);
    }

    // Remove client from clients list
    pthread_mutex_lock(&clients_lock);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == client_socket) {
            clients[i] = 0; // Mark as available
            break;
        }
    }
    pthread_mutex_unlock(&clients_lock);

    printf("Client %d disconnected\n", client_socket);
    close(client_socket);
    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_lock);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != 0 && clients[i] != sender_socket) {
            send(clients[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_lock);
}