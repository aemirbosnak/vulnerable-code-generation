//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 256

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';

        printf("Received: %s\n", buffer);

        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < client_count; i++) {
            if (clients[i] != client_socket) {
                send(clients[i], buffer, bytes_received, 0);
            }
        }
        pthread_mutex_unlock(&client_mutex);
    }

    close(client_socket);
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == client_socket) {
            clients[i] = clients[client_count - 1];
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);

    printf("Client disconnected. Goodbye!\n");
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("😊 Chat Server started! Waiting for clients to connect on port %d...\n", PORT);

    while (1) {
        // Accept new client
        if ((new_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("🎉 New client connected! (Socket: %d)\n", new_socket);

        // Add new client to the array
        pthread_mutex_lock(&client_mutex);
        clients[client_count++] = new_socket;
        pthread_mutex_unlock(&client_mutex);

        // Create a new thread for handling client
        if (pthread_create(&tid, NULL, handle_client, (void*)&new_socket) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    close(server_socket);
    return 0;
}