//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the string
        printf("Client Message: %s\n", buffer);
        
        // Broadcast message to all clients
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], buffer, read_size, 0);
            }
        }
        pthread_mutex_unlock(&client_mutex);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv failed");
    }

    close(sock);
    pthread_exit(NULL);
}

int main() {
    int server_sock, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 3) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);

    while ((new_socket = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len))) {
        printf("New client connected.\n");
        
        // Add to client list
        pthread_mutex_lock(&client_mutex);
        client_sockets[client_count++] = new_socket;
        pthread_mutex_unlock(&client_mutex);

        // Create a new thread for the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&new_socket) < 0) {
            perror("Could not create thread");
            return 1;
        }
    }

    if (new_socket < 0) {
        perror("Accept failed");
    }

    close(server_sock);
    return 0;
}