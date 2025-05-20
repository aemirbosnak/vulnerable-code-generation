//GEMINI-pro DATASET v1.0 Category: Networking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Defines the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Initializes the server socket
int initialize_server_socket(int port) {
    int server_socket;
    struct sockaddr_in server_addr;

    // Creates the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Sets the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Binds the server socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listens for incoming client connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    return server_socket;
}

// Accepts a client connection and returns the client socket
int accept_client_connection(int server_socket) {
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Accepts a client connection
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket == -1) {
        perror("accept");
        exit(1);
    }

    // Prints the client IP address and port
    printf("Client IP address: %s\n", inet_ntoa(client_addr.sin_addr));
    printf("Client port: %d\n", ntohs(client_addr.sin_port));

    return client_socket;
}

// Sends a message to a client
void send_message(int client_socket, char *message) {
    int message_len = strlen(message);

    // Sends the message to the client
    if (send(client_socket, message, message_len, 0) == -1) {
        perror("send");
        exit(1);
    }
}

// Receives a message from a client
char *receive_message(int client_socket) {
    char *message;
    int message_len;

    // Receives the message from the client
    message_len = recv(client_socket, NULL, 0, MSG_PEEK);
    if (message_len == -1) {
        perror("recv");
        exit(1);
    }

    // Allocates memory for the message
    message = malloc(message_len + 1);

    // Receives the message from the client
    if (recv(client_socket, message, message_len, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Adds a null terminator to the message
    message[message_len] = '\0';

    return message;
}

// Closes a client connection
void close_client_connection(int client_socket) {
    // Closes the client socket
    if (close(client_socket) == -1) {
        perror("close");
        exit(1);
    }
}

// Main function
int main(int argc, char *argv[]) {
    int server_socket;
    int client_socket;
    char *message;

    // Checks if the port number is specified
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Initializes the server socket
    server_socket = initialize_server_socket(atoi(argv[1]));

    // Main loop
    while (1) {
        // Accepts a client connection
        client_socket = accept_client_connection(server_socket);

        // Receives a message from the client
        message = receive_message(client_socket);

        // Prints the received message
        printf("Received message: %s\n", message);

        // Sends a message to the client
        send_message(client_socket, "Hello from the server!\n");

        // Closes the client connection
        close_client_connection(client_socket);
    }

    // Closes the server socket
    close(server_socket);

    return 0;
}