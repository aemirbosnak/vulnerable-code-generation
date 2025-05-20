//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void *client_handler(void *socket_desc);
void broadcast_message(char *message, int exclude_socket);

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the defined port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d...\n", PORT);
    
    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        pthread_mutex_lock(&clients_mutex);
        
        // Keep track of client sockets
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            printf("New client connected: socket fd %d\n", new_socket);
        } else {
            printf("Max clients connected. Rejecting: socket fd %d\n", new_socket);
            close(new_socket);
        }
        
        pthread_mutex_unlock(&clients_mutex);
        
        // Create a thread for the new client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&new_socket) < 0) {
            perror("could not create thread");
            return 1;
        }
    }
    
    return 0;
}

void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Client says: %s\n", buffer);
        broadcast_message(buffer, sock);
    }

    // Handle disconnection
    if (read_size == 0) {
        printf("Client disconnected: socket fd %d\n", sock);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    close(sock);

    pthread_mutex_lock(&clients_mutex);
    // Remove the client socket from the list
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[client_count - 1]; // Replace with last one
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    
    return 0;
}

void broadcast_message(char *message, int exclude_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        // Send message to all clients except the sender
        if (client_sockets[i] != exclude_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}