//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Array to hold client sockets
int client_sockets[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to broadcast messages to all clients
void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle client connection
void *handle_client(void *arg) {
    int socket = *(int *)arg;
    char name[50];
    char buffer[BUFFER_SIZE];

    // Get client name
    recv(socket, name, sizeof(name), 0);
    printf("%s has joined the chat!\n", name);
    
    // Loop to constantly receive messages from clients
    while (1) {
        int bytes_received = recv(socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("%s has left the chat.\n", name);
            break;
        }

        // Broadcast the received message
        buffer[bytes_received] = '\0'; // NULL terminate the received message
        char message[BUFFER_SIZE + 50];
        snprintf(message, sizeof(message), "%s: %s", name, buffer);
        broadcast_message(message, socket);
    }

    // Remove client socket
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == socket) {
            client_sockets[i] = 0;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(socket);
    return NULL;
}

// Main function to set up the server
int main() {
    // Initialize list of client sockets to 0
    memset(client_sockets, 0, sizeof(client_sockets));

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for clients
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d! 🎉\n", PORT);
    while (1) {
        // Accept new connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }

        // Add new client socket to the list
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);
        printf("New client connected! 🤗\n");

        // Create a new thread for the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Failed to create thread");
        }
    }

    // Cleanup
    close(server_socket);
    return 0;
}