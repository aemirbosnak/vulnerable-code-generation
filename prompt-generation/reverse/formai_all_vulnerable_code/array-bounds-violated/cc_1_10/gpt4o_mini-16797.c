//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t lock;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate the string
        printf("Message received: %s", buffer);

        // Broadcast the message to other clients
        pthread_mutex_lock(&lock);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != client_socket) { // Exclude sender
                send(client_sockets[i], buffer, bytes_read, 0);
            }
        }
        pthread_mutex_unlock(&lock);
    }

    // Remove client from the list when disconnected
    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[client_count - 1]; // Replace with last
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&lock);

    close(client_socket);
    printf("Client disconnected\n");
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t tid;

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
            printf("New client connected\n");

            // Add new socket to the list of clients
            pthread_mutex_lock(&lock);
            if (client_count < MAX_CLIENTS) {
                client_sockets[client_count++] = new_socket;
                pthread_create(&tid, NULL, handle_client, (void *)&new_socket);
            } else {
                printf("Max clients reached. Connection refused.\n");
                close(new_socket);
            }
            pthread_mutex_unlock(&lock);
        }
    }

    pthread_mutex_destroy(&lock);
    return 0;
}