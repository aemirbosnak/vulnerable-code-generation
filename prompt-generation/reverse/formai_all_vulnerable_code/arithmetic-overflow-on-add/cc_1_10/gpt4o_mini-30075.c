//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(client_socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        printf("Client sent: %s", buffer);
        
        // Echo back the received message to the client
        write(client_socket, buffer, bytes_read);
    }

    if (bytes_read == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("Error reading from socket");
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    fd_set read_fds;
    int max_sd;

    // Create a TCP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address configuration
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Clear the read_fds set
        FD_ZERO(&read_fds);

        // Add server socket to the read_fds set
        FD_SET(server_socket, &read_fds);
        max_sd = server_socket;

        // Wait for activity on the sockets
        if (select(max_sd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("Select failed");
            close(server_socket);
            exit(EXIT_FAILURE);
        }

        // Check if there's a new connection
        if (FD_ISSET(server_socket, &read_fds)) {
            if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length)) < 0) {
                perror("Accept failed");
                close(server_socket);
                exit(EXIT_FAILURE);
            }

            printf("New connection established.\n");
            handle_client(client_socket);
        }
    }

    close(server_socket);
    return 0;
}