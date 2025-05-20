//FormAI DATASET v1.0 Category: Chat server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_client_connection(int client_sockfd);

int main(int argc, char *argv[]) {
    int server_sockfd, client_sockfd, port_number;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len;

    // Check if port number is provided as a command line argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert port number string to integer
    port_number = atoi(argv[1]);

    // Create a TCP socket for the server
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    int optval = 1;
    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        fprintf(stderr, "Error: Could not set socket options\n");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    // Bind server socket to a port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);
    if (bind(server_sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        fprintf(stderr, "Error: Could not bind socket to port\n");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sockfd, 10) == -1) {
        fprintf(stderr, "Error: Could not listen for incoming connections\n");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server started. Waiting for connections on port %d...\n", port_number);

    // Loop indefinitely to accept incoming connections
    while (1) {
        client_len = sizeof(client_address);
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_len)) == -1) {
            fprintf(stderr, "Error: Could not accept incoming connection\n");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handle client connection in a separate function
        handle_client_connection(client_sockfd);

        close(client_sockfd);
        printf("Client disconnected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }

    close(server_sockfd);
    return 0;
}

void handle_client_connection(int client_sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received, bytes_sent;

    // Send welcome message to client
    bytes_sent = send(client_sockfd, "Welcome to the chat room!\nEnter your name: ", 45, 0);
    if (bytes_sent == -1) {
        fprintf(stderr, "Error: Could not send data to client\n");
        return;
    }

    // Receive name from client
    bytes_received = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Error: Could not receive data from client\n");
        return;
    }

    // Add null terminator to name
    buffer[bytes_received] = '\0';

    // Send greeting message to client
    char greeting[BUFFER_SIZE];
    sprintf(greeting, "Hello, %s!\n", buffer);
    bytes_sent = send(client_sockfd, greeting, strlen(greeting), 0);
    if (bytes_sent == -1) {
        fprintf(stderr, "Error: Could not send data to client\n");
        return;
    }

    while (1) {
        // Receive message from client
        bytes_received = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            fprintf(stderr, "Error: Could not receive data from client\n");
            return;
        }

        // Add null terminator to message
        buffer[bytes_received] = '\0';

        if (strcmp(buffer, "quit\n") == 0) {
            // Break out of loop if client sends quit command
            break;
        }

        // Send message to all connected clients
        char message[BUFFER_SIZE];
        sprintf(message, "%s: %s", buffer, greeting);
        bytes_sent = send(client_sockfd, message, strlen(message), 0);
        if (bytes_sent == -1) {
            fprintf(stderr, "Error: Could not send data to client\n");
            return;
        }
    }
}