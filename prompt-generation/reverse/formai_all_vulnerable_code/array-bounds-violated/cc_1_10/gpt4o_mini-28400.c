//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: real-life
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
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle communication with clients
void *handle_client(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client [%d]: %s\n", sock, buffer);

        // Broadcast message to other clients
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], buffer, bytes_received, 0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    // Remove the client from the list and close the socket
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            while (i < client_count - 1) {
                client_sockets[i] = client_sockets[i + 1];
                i++;
            }
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    close(sock);
    printf("Client [%d] disconnected.\n", sock);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t tid;

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        // Accept new client connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %d\n", new_socket);

        // Store client socket
        pthread_mutex_lock(&mutex);
        client_sockets[client_count++] = new_socket;
        pthread_mutex_unlock(&mutex);

        // Create a new thread for the client
        pthread_create(&tid, NULL, handle_client, (void *)&new_socket);
    }

    close(server_socket);
    return 0;
}