//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 100

void *handle_client(void *client_socket);
void send_message_to_all_clients(const char* msg);
int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept client connections
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Lock for thread safety when manipulating client_sockets array
        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            printf("New client connected: %d\n", new_socket);
        } else {
            printf("Max clients reached. Rejecting new connection: %d\n", new_socket);
            close(new_socket);
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create thread for the new client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)&new_socket) != 0) {
            perror("Failed to create thread");
            close(new_socket);
        }
        pthread_detach(thread_id); // Detach the thread to allow cleanup after finishing
    }

    return 0;
}

// Function to handle communication with a client
void *handle_client(void *client_socket) {
    int sock = *(int*)client_socket;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0'; // Null terminate the data received
        printf("Received from client %d: %s", sock, buffer);
        send_message_to_all_clients(buffer);
    }

    // Close client socket and remove from client sockets array
    close(sock);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            // Remove this socket
            client_sockets[i] = client_sockets[--client_count]; // Swap with last
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    printf("Client disconnected: %d\n", sock);
    return NULL;
}

// Function to send message to all connected clients
void send_message_to_all_clients(const char* msg) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        send(client_sockets[i], msg, strlen(msg), 0);
    }
    pthread_mutex_unlock(&clients_mutex);
}