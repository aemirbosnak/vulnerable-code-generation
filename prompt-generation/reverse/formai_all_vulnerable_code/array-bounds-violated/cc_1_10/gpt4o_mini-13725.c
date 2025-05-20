//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function declarations
void *client_handler(void *socket_desc);
void broadcast_message(const char *message, int sender_socket);

// Array to store connected client sockets
#define MAX_CLIENTS 100
int client_sockets[MAX_CLIENTS];
int client_count = 0;

// Mutex for client sockets array
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Define server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept a new client socket
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Store the client socket
        pthread_mutex_lock(&mutex);
        client_sockets[client_count++] = new_socket;
        pthread_mutex_unlock(&mutex);

        // Create a new thread for the client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void*)&new_socket) < 0) {
            perror("Could not create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Cleanup
    close(server_fd);
    return 0;
}

// Function to handle client communication
void *client_handler(void *socket_desc) {
    int client_socket = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Communication loop
    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[read_size] = '\0';  // Null terminate to print as a string
        printf("Client: %s\n", buffer);

        // Broadcast message to all clients
        broadcast_message(buffer, client_socket);
    }

    // Remove client socket from the list and close the socket
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[client_count - 1];
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    
    close(client_socket);
    printf("Client disconnected\n");
    return 0;
}

// Function to broadcast a message to all clients
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}