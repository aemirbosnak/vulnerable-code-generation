//FormAI DATASET v1.0 Category: Chat server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_NUMBER     8080
#define BUFFER_SIZE     1024

int main(int argc, char** argv)
{
    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create a socket for listening
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket for listening");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int optval = 1;
    setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Initialize server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT_NUMBER);

    // Bind the socket to the server address
    if (bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind to server address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, 1) == -1) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT_NUMBER);

    // Accept incoming connections
    client_address_len = sizeof(client_address);
    if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_address, &client_address_len)) == -1) {
        perror("Failed to accept incoming connection");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Receive data from client
    while ((bytes_received = recv(client_socket_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received %d bytes: %s\n", bytes_received, buffer);

        // Echo back to client
        if (send(client_socket_fd, buffer, bytes_received, 0) == -1) {
            perror("Failed to send data to client");
            exit(EXIT_FAILURE);
        }
    }

    // Close sockets
    close(client_socket_fd);
    close(server_socket_fd);

    return 0;
}