//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <address> <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind socket to port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[2]));
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for connections");
        exit(1);
    }

    printf("HTTP Proxy Server started at %s:%s\n", argv[1], argv[2]);

    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }

        printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive HTTP request from client
        char buffer[BUFFER_SIZE];
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("Error receiving data from client");
            continue;
        }

        // Parse HTTP request for hostname and path
        char *hostname = NULL, *path = NULL;
        if (sscanf(buffer, "GET http://%m[^/]/%ms", &hostname, &path) != 2) {
            perror("Error parsing HTTP request");
            close(client_socket);
            continue;
        }

        // Get IP address for hostname
        struct hostent *host = gethostbyname(hostname);
        if (host == NULL) {
            perror("Error getting IP address for hostname");
            close(client_socket);
            continue;
        }

        // Create socket to server
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket == -1) {
            perror("Error creating socket to server");
            close(client_socket);
            continue;
        }

        // Connect to server
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(80);
        server_address.sin_addr = *((struct in_addr*) host->h_addr);
        if (connect(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
            perror("Error connecting to server");
            close(client_socket);
            continue;
        }

        // Send HTTP request to server
        if (send(server_socket, buffer, bytes_received, 0) != bytes_received) {
            perror("Error sending data to server");
            close(server_socket);
            close(client_socket);
            continue;
        }

        // Receive HTTP response from server
        while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            // Send HTTP response to client
            if (send(client_socket, buffer, bytes_received, 0) != bytes_received) {
                perror("Error sending data to client");
                close(server_socket);
                close(client_socket);
                continue;
            }
        }

        close(server_socket);
        close(client_socket);
    }

    return 0;
}