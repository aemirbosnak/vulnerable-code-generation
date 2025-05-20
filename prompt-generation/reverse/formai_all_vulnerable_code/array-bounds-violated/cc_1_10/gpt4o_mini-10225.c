//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

// Function declarations
void *client_handler(void *socket_desc);
void broadcast_message(const char *message, int sender_socket);

// Array to hold client sockets
int client_sockets[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Main function - entry point of the program
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        return 1;
    }
    
    // Configure server settings
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return 1;
    }
    
    // Listen for incoming connections
    listen(server_socket, 3);
    printf("Chat server is running on port %d\n", PORT);
    
    // Accept clients
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len))) {
        printf("Client connected: %d\n", client_socket);
        
        // Lock to update the clients array
        pthread_mutex_lock(&clients_mutex);
        if (num_clients < MAX_CLIENTS) {
            client_sockets[num_clients++] = client_socket;
        } else {
            printf("Max clients reached, rejecting: %d\n", client_socket);
            close(client_socket);
            pthread_mutex_unlock(&clients_mutex);
            continue;
        }
        pthread_mutex_unlock(&clients_mutex);
        
        // Create a new thread for the client
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, client_handler, (void *)&client_socket) < 0) {
            perror("Could not create thread");
            return 1;
        }
    }
    
    // Close server socket (not reached in this example)
    close(server_socket);
    return 0;
}

// Function to handle client communication
void *client_handler(void *socket_desc) {
    int client_socket = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;
    
    // Communication loop
    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate string
        printf("Received from %d: %s\n", client_socket, buffer);
        broadcast_message(buffer, client_socket);
    }
    
    // Client disconnected
    printf("Client disconnected: %d\n", client_socket);
    
    // Remove client from list and close the socket
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[num_clients - 1];
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(client_socket);
    return 0;
}

// Function to broadcast a message to all clients except the sender
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}