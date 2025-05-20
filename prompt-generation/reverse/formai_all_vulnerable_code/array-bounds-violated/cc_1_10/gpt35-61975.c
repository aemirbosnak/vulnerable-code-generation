//FormAI DATASET v1.0 Category: Chat server ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MSG_LENGTH 1024

// Global variables for clients
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

// Function to handle client messages
void handle_message(int client_socket) {
    char buffer[MAX_MSG_LENGTH];
    int read_size;
    while ((read_size = recv(client_socket, buffer, MAX_MSG_LENGTH, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received message from client(%d): %s", client_socket, buffer);
        // Broadcast message to all other clients
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }
    // Remove client from client list when disconnected
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] == client_socket) {
            printf("Client(%d) disconnected\n", client_socket);
            for (int j = i; j < num_clients-1; j++) {
                client_sockets[j] = client_sockets[j+1];
            }
            num_clients--;
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options (reuse address)
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections from clients
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started. Listening on port %d...\n", PORT);

    // Accept connections from clients
    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("New client(%d) connected from %s:%d\n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Add new client to client list
        client_sockets[num_clients++] = new_socket;

        // Create a new process to handle client messages
        if (fork() == 0) {
            handle_message(new_socket);
            exit(0);
        }
    }

    return 0;
}