//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_info;

client_info clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_lock;

// Function to broadcast messages to all connected clients
void broadcast_message(const char *message, int sender_sock) {
    pthread_mutex_lock(&clients_lock);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket != sender_sock) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_lock);
}

// Thread function to handle each client
void *client_handler(void *arg) {
    client_info client = *(client_info *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client.socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        printf("Received from client: %s", buffer);
        broadcast_message(buffer, client.socket);
    }

    // Remove client from the list after disconnect
    close(client.socket);
    pthread_mutex_lock(&clients_lock);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket == client.socket) {
            clients[i] = clients[client_count - 1];
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_lock);
    printf("Client disconnected\n");
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t tid;

    pthread_mutex_init(&clients_lock, NULL);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept new client connection
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Add new client to the list
        pthread_mutex_lock(&clients_lock);
        if (client_count < MAX_CLIENTS) {
            clients[client_count].socket = new_socket;
            clients[client_count].address = client_addr;
            client_count++;
            printf("New client connected: %d\n", new_socket);
        } else {
            printf("Max clients connected. Connection rejected: %d\n", new_socket);
            close(new_socket);
        }
        pthread_mutex_unlock(&clients_lock);

        // Create a new thread for the client
        if (pthread_create(&tid, NULL, client_handler, &clients[client_count - 1]) != 0) {
            perror("Thread creation failed");
        }
        pthread_detach(tid); // Detach thread to allow auto cleaning up
    }

    close(server_socket);
    pthread_mutex_destroy(&clients_lock);
    return 0;
}