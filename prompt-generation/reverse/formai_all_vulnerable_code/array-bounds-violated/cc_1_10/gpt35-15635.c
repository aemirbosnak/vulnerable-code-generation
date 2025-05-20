//FormAI DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PENDING_CONNECTIONS 10
#define MAX_BUFFER_SIZE 256

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    int port = atoi(argv[1]);
    int server_socket, client_socket, bytes_received, bytes_sent;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Create a socket, bind it to a specific port, and listen for incoming connections
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("An error occurred while creating the server socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("An error occurred while binding the server socket to port %d: %s\n", port, strerror(errno));
        return EXIT_FAILURE;
    }

    if (listen(server_socket, MAX_PENDING_CONNECTIONS) == -1) {
        printf("An error occurred while listening for incoming connections: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d...\n", port);

    while (true) {
        // Accept an incoming connection
        socklen_t client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket == -1) {
            printf("An error occurred while accepting an incoming connection: %s\n", strerror(errno));
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(client_address.sin_addr));

        // Receive data from the client
        bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0);
        if (bytes_received == -1) {
            printf("An error occurred while receiving data from the client: %s\n", strerror(errno));
            close(client_socket);
            continue;
        }
        
        buffer[bytes_received] = '\0';
        printf("Received %d bytes from the client: %s\n", bytes_received, buffer);

        // Send a response to the client
        bytes_sent = send(client_socket, "Hello, client!", strlen("Hello, client!"), 0);
        if (bytes_sent == -1) {
            printf("An error occurred while sending data to the client: %s\n", strerror(errno));
        }

        close(client_socket);
        printf("Client disconnected.\n");
    }

    return EXIT_SUCCESS;
}