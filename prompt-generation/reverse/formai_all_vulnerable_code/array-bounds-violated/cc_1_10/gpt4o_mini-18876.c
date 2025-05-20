//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: authentic
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

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Client[%d]: %s\n", client_socket, buffer);

        // Broadcast message to other clients
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != client_socket) { // Don't send message to the sender
                send(client_sockets[i], buffer, bytes_received, 0);
            }
        }
    }

    // Remove the client from the array and close the socket
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            for (int j = i; j < client_count - 1; j++) {
                client_sockets[j] = client_sockets[j + 1];
            }
            client_count--;
            break;
        }
    }
    close(client_socket);
    printf("Client[%d] disconnected.\n", client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failure");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failure");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failure");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", PORT);

    // Accept clients
    while (1) {
        addr_len = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len)) < 0) {
            perror("Accept failure");
            continue;
        }

        printf("New client connected: %d\n", client_socket);
        client_sockets[client_count++] = client_socket;

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void*)&client_socket) != 0) {
            perror("Failed to create thread");
        }
    }

    close(server_socket);
    return 0;
}