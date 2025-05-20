//FormAI DATASET v1.0 Category: Firewall ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <ip-address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_addr = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Set options for the server socket
    int opt_val = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof opt_val) == -1) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the IP address and port
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Set the server to listen for incoming connections
    if (listen(server_socket, SOMAXCONN) == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    // Loop to accept incoming connections
    struct sockaddr_in client_addr = {0};
    socklen_t client_addr_len = sizeof(client_addr);
    int client_socket;

    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) != -1) {
        char message[BUF_SIZE];

        // Read the incoming message from the client
        ssize_t bytes_read = recv(client_socket, message, BUF_SIZE, 0);
        if (bytes_read == -1) {
            perror("Error reading message from client");
            exit(EXIT_FAILURE);
        }

        message[bytes_read] = '\0';

        // Check to see if the message is blacklisted
        const char *blacklist[] = {"password", "creditcard", "secret"};
        bool is_blacklisted = false;

        for (int i = 0; i < sizeof(blacklist) / sizeof(*blacklist); i++) {
            if (strstr(message, blacklist[i]) != NULL) {
                is_blacklisted = true;
                break;
            }
        }

        // If the message is blacklisted, close the connection
        if (is_blacklisted) {
            close(client_socket);
            continue;
        }

        // Otherwise, send the message back to the client
        if (send(client_socket, message, strlen(message), 0) == -1) {
            perror("Error sending message to client");
            exit(EXIT_FAILURE);
        }
    }

    // Clean up
    close(server_socket);

    return 0;
}