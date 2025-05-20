//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void *handle_client(void *arg);
void broadcast_message(char *message, int sender_fd);

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t lock;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Configure the address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_mutex_lock(&lock);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            pthread_mutex_unlock(&lock);
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, (void *)&new_socket);
        } else {
            pthread_mutex_unlock(&lock);
            const char *msg = "Server is full. Try again later.\n";
            send(new_socket, msg, strlen(msg), 0);
            close(new_socket);
        }
    }

    // Cleanup
    pthread_mutex_destroy(&lock);
    close(server_fd);
    return 0;
}

void *handle_client(void *arg) {
    int socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client says: %s", buffer);
        broadcast_message(buffer, socket);
    }

    if (bytes_read == 0) {
        printf("Client disconnected\n");
    } else {
        perror("Recv failed");
    }

    // Remove client from list
    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_count; ++i) {
        if (client_sockets[i] == socket) {
            for (int j = i; j < client_count - 1; ++j) {
                client_sockets[j] = client_sockets[j + 1];
            }
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    close(socket);

    return NULL;
}

void broadcast_message(char *message, int sender_fd) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_fd) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&lock);
}