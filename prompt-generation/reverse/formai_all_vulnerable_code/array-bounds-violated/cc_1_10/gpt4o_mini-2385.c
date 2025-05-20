//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void broadcast_message(char *message, int sender_socket);

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set up server address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d\n", PORT);
    
    while (1) {
        // Accept new connections from clients
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }
        
        // Add the new socket to the array
        pthread_mutex_lock(&clients_mutex);
        if (client_count >= MAX_CLIENTS) {
            printf("Maximum clients reached. Connection rejected.\n");
            close(new_socket);
        } else {
            client_sockets[client_count++] = new_socket;
            printf("Client connected. Total clients: %d\n", client_count);

            pthread_t thread;
            pthread_create(&thread, NULL, handle_client, (void *)&new_socket);
            pthread_detach(thread);
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    return 0;
}

void *handle_client(void *arg) {
    int socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Handle client messages
    while ((read_size = recv(socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received message
        printf("Received: %s", buffer);

        // Broadcast the message to all connected clients
        broadcast_message(buffer, socket);
    }

    // Close the socket if there was an error
    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv failed");
    }
    
    // Remove socket from client list
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            close(socket);
            client_sockets[i] = client_sockets[--client_count]; // Remove and replace the last socket
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    return NULL;
}

void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}