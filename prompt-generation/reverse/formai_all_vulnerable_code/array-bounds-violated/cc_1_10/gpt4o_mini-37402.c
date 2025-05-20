//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void *handle_client(void *client_socket);
void send_message_to_all_clients(const char *message);
void remove_client(int socket);

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Client acceptance failed");
            continue;
        }

        pthread_mutex_lock(&mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count] = client_socket;
            client_count++;
            pthread_mutex_unlock(&mutex);
            
            // Create a new thread for the client
            pthread_t thread_id;
            if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket) != 0) {
                perror("Thread creation failed");
            }
            pthread_detach(thread_id); // Detach the thread to handle cleanup
        } else {
            pthread_mutex_unlock(&mutex);
            const char *message = "Server full. Try again later.\n";
            send(client_socket, message, strlen(message), 0);
            close(client_socket);
        }
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    
    while (1) {
        int bytes_read = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_read <= 0) {
            break; // Client disconnected or error
        }
        
        buffer[bytes_read] = '\0'; // Null-terminate the received string
        printf("Received: %s", buffer);
        
        // Broadcast the message to all clients
        send_message_to_all_clients(buffer);
    }
    
    // Remove the client once disconnected
    remove_client(sock);
    close(sock);
    return NULL;
}

void send_message_to_all_clients(const char *message) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        send(client_sockets[i], message, strlen(message), 0);
    }
    pthread_mutex_unlock(&mutex);
}

void remove_client(int socket) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            client_sockets[i] = client_sockets[client_count - 1]; // Replace with the last client
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
}