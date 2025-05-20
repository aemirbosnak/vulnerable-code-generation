//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);
void remove_client(int socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t address_len = sizeof(client_address);
    
    // Creating socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Binding socket to PORT
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server is running on port %d...\n", PORT);

    while (1) {
        // Accepting a new client
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Locking to manage clients
        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_socket;
            printf("New client connected: socket %d\n", client_socket);
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, (void *)&client_socket);
        } else {
            printf("Max clients reached. Rejected socket %d\n", client_socket);
            close(client_socket);
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    return 0;
}

// Thread function to handle each client
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    
    // Client communication loop
    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received message
        printf("Message from socket %d: %s\n", client_socket, buffer);
        broadcast_message(buffer, client_socket);
    }

    // Client disconnected
    printf("Client disconnected: socket %d\n", client_socket);
    remove_client(client_socket);
    close(client_socket);
    return NULL;
}

// Broadcast incoming message to all clients except sender
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }

    pthread_mutex_unlock(&clients_mutex);
}

// Remove client socket from the list
void remove_client(int socket) {
    pthread_mutex_lock(&clients_mutex);
    
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            // Shift remaining sockets left
            for (int j = i; j < client_count - 1; j++) {
                client_sockets[j] = client_sockets[j + 1];
            }
            client_count--;
            break;
        }
    }
    
    pthread_mutex_unlock(&clients_mutex);
}