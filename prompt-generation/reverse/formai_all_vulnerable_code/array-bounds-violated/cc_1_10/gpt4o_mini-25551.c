//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_sock);

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 5) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Echo Server listening on port %d...\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        // Accept incoming connection
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected.\n");

        // Fork a new process to handle the client
        if (fork() == 0) {
            close(server_sock); // Close the listening socket in child process
            handle_client(client_sock);
            close(client_sock);
            exit(0);
        }
        close(client_sock); // Parent closes the socket
    }

    close(server_sock);
    return 0;
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    // Communicate with the client
    while (1) {
        // Read message from client
        int bytes_received = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received < 0) {
            perror("Error reading from socket");
            break;
        } else if (bytes_received == 0) {
            printf("Client disconnected.\n");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);

        // Check for exit condition
        if (strcmp(buffer, "exit\n") == 0) {
            printf("Exiting communication.\n");
            break;
        }

        // Echo back the message
        send(client_sock, buffer, bytes_received, 0);
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer for the next message
    }
}