//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int connected_clients[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);
void remove_client(int socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    // Accepting and handling clients
    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        if (client_count < MAX_CLIENTS) {
            connected_clients[client_count++] = new_socket;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *)new_socket);
        } else {
            printf("Maximum clients connected. Connection refused.\n");
            close(new_socket);
        }
    }

    return 0;
}

// Function to handle client connections
void *handle_client(void *arg) {
    int socket = (int)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client: %s\n", buffer);
        broadcast_message(buffer, socket);
    }

    remove_client(socket);
    close(socket);
    return NULL;
}

// Function to broadcast messages to all clients
void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (connected_clients[i] != sender_socket) {
            send(connected_clients[i], message, strlen(message), 0);
        }
    }
}

// Function to remove client from the list
void remove_client(int socket) {
    for (int i = 0; i < client_count; i++) {
        if (connected_clients[i] == socket) {
            connected_clients[i] = connected_clients[--client_count];
            break;
        }
    }
    printf("Client disconnected. Total clients: %d\n", client_count);
}