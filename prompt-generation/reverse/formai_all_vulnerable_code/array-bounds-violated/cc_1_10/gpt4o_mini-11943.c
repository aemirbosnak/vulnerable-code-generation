//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: accurate
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

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        int bytes_received = recv(client_socket, buffer, sizeof(buffer)-1, 0);
        if (bytes_received <= 0) {
            break; // client disconnected
        }
        buffer[bytes_received] = '\0'; // Null-terminate the received string

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, bytes_received, 0); // Send message to other clients
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(client_socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[--client_count]; // Remove socket from the list
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Socket creation
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        if (client_count < MAX_CLIENTS) {
            client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
            if (client_socket < 0) {
                perror("Accept failed");
                continue;
            }

            printf("Client connected: %d\n", client_socket);
            pthread_mutex_lock(&clients_mutex);
            client_sockets[client_count++] = client_socket; // Store client socket
            pthread_mutex_unlock(&clients_mutex);

            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, &client_socket);
            pthread_detach(tid);
        } else {
            printf("Max clients reached. Connection refused for a new client.\n");
            close(client_socket);
        }
    }

    close(server_socket);
    return EXIT_SUCCESS;
}