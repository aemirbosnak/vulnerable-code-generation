//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];

void *client_handler(void *socket) {
    int client_socket = *(int *)socket;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the buffer

        // Broadcast the message to all clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != 0 && client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, read_size, 0);
            }
        }
    }

    // Cleanup
    close(client_socket);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = 0;
            break;
        }
    }
    return NULL;
}

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in address;

    // Initialize client sockets
    memset(client_sockets, 0, sizeof(client_sockets));

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the sockaddr_in structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

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
                break;
            }
        }

        pthread_t tid;
        // Create a new thread for the client
        if (pthread_create(&tid, NULL, client_handler, (void *)&client_socket) != 0) {
            perror("Thread creation failed");
        }
    }

    return 0;
}