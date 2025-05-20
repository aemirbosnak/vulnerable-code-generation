//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';

        printf("Client[%d]: %s", client_socket, buffer);
        
        // Broadcast the message to all other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, bytes_received, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }
    
    // Remove client from the list and close the socket
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[client_count - 1];
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_length = sizeof(client_addr);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_socket, 3) == -1) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d\n", PORT);
    
    while (1) {
        // Accept incoming client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_length)) < 0) {
            perror("Acceptance failed");
            continue;
        }
        
        // Add the new client to the list
        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_socket;
            printf("Client[%d] connected\n", client_socket);
            pthread_t thread_id;
            if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket) != 0) {
                perror("Thread creation failed");
            }
        } else {
            printf("Max clients reached. Connection rejected: %d\n", client_socket);
            close(client_socket);
        }
        pthread_mutex_unlock(&clients_mutex);
    }
    
    // Close the server socket
    close(server_socket);
    return 0;
}