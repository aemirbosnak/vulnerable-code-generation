//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void *handle_client(void *arg);
void send_message_to_all_clients(char *message, int exclude_sock);

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t lock;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set address family, IPv4, type of socket, and protocol
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started. Listening on port %d...\n", PORT);

    pthread_mutex_init(&lock, NULL);
    
    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_mutex_lock(&lock);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, (void *)&new_socket);
            pthread_detach(tid); // Detach thread to handle clients independently
        } else {
            printf("Max clients reached. Rejecting new connection.\n");
            close(new_socket);
        }
        pthread_mutex_unlock(&lock);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}

void *handle_client(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Message received: %s", buffer);
        send_message_to_all_clients(buffer, sock); // Send message to all clients except the sender
    }

    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[--client_count]; // Remove client from socket list
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    
    printf("Client disconnected.\n");
    close(sock);
    return NULL;
}

void send_message_to_all_clients(char *message, int exclude_sock) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != exclude_sock) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&lock);
}