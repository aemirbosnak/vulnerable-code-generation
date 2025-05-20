//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: active
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
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';

        // Broadcast the message to other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != 0 && client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, bytes_read, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Remove client from client_sockets
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = 0;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    close(client_socket);
    return NULL;
}

void setup_server_socket(int *server_socket) {
    struct sockaddr_in server_addr;

    // Create a socket
    if ((*server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(*server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(*server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(*server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(*server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);
}

int main() {
    int server_socket = 0, client_socket;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    struct sockaddr_in client_addr;

    // Initialize client sockets array
    memset(client_sockets, 0, sizeof(client_sockets));

    setup_server_socket(&server_socket);

    while (1) {
        // Accept a new client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Client accept failed");
            continue;
        }

        // Add client to the clients array
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread for the new client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Failed to create thread");
            close(client_socket);
        } else {
            pthread_detach(tid); // Detach the thread to free resources when done
        }
    }

    // Cleanup
    close(server_socket);
    return 0;
}