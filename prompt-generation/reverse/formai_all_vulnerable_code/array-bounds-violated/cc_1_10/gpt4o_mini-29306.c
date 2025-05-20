//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: active
// chat_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];

void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void *client_handler(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Received: %s", buffer);
        broadcast_message(buffer, client_socket);
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in address;

    // Initialize all client sockets to 0
    memset(client_sockets, 0, sizeof(client_sockets));

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    // Main loop to accept incoming connections
    while (1) {
        addr_len = sizeof(address);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Add client socket to the array
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                printf("Client connected: %d\n", client_socket);
                break;
            }
        }

        // Fork a new process for each client
        if (fork() == 0) {
            // Handle client messages
            client_handler(&client_socket);
            exit(0);
        }
    }

    return 0;
}