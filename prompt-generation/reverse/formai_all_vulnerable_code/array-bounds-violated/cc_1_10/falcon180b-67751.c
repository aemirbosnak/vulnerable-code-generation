//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int socket_fd, client_socket_fd, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind server address
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    // Accept incoming connections
    printf("Server listening on port %d\n", SERVER_PORT);
    while (1) {
        client_socket_fd = accept(socket_fd, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Send welcome message
        send(client_socket_fd, "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0);

        // Receive data from client
        bytes_received = recv(client_socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            close(client_socket_fd);
            continue;
        }
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);

        // Send response to client
        strcpy(buffer, "Thank you for connecting!");
        send(client_socket_fd, buffer, strlen(buffer), 0);

        // Close client socket
        close(client_socket_fd);
    }

    return 0;
}