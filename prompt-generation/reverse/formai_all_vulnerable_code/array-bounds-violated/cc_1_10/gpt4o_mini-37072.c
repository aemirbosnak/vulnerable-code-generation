//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 5

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the received string
        printf("Client: %s\n", buffer);
        // Echo back the received message
        send(client_socket, buffer, bytes_read, 0);
    }
    if (bytes_read < 0) {
        error_handling("recv failed");
    }
    close(client_socket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handling("Socket creation failed");
    }

    // Bind the socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error_handling("setsockopt failed");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error_handling("Bind failed");
    }

    // Start listening for incoming connections
    if (listen(server_fd, BACKLOG) < 0) {
        error_handling("Listen failed");
    }
    
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept a client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            error_handling("Accept failed");
        }
        
        printf("Accepted new connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Handle the client in a separate process (optional: fork)
        if (fork() == 0) {
            close(server_fd); // Child process does not need the listening socket
            handle_client(new_socket);
            exit(0); // Exit child process
        }
        close(new_socket); // Parent process closes the connected socket
    }

    close(server_fd);
    return 0;
}