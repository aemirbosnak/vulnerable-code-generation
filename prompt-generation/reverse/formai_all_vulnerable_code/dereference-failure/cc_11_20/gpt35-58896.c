//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_CLIENTS 30

int main(int argc, char *argv[]) {

    // Check for valid arguments
    if (argc != 3) {
        printf("Usage: %s <server-ip-address> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket for the proxy server
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the proxy server details
    struct sockaddr_in proxy_address;
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = inet_addr(argv[1]);
    proxy_address.sin_port = htons(atoi(argv[2]));

    // Bind the proxy socket to the server details
    if (bind(proxy_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(proxy_socket, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Wait for clients to connect
    struct sockaddr_in client_address;
    socklen_t client_size = sizeof(client_address);

    int client_socket;
    char client_buffer[MAX_BUFFER_SIZE];

    while ((client_socket = accept(proxy_socket, (struct sockaddr *)&client_address, &client_size))) {

        if (fork() == 0) {
            // Child process - handle client requests

            printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

            // Set up a connection to the server
            int server_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (server_socket < 0) {
                perror("Error creating server socket");
                exit(1);
            }

            // Set the server details
            struct sockaddr_in server_address;
            server_address.sin_family = AF_INET;
            server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
            server_address.sin_port = htons(80); // HTTP port

            // Connect to the server
            if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
                perror("Error connecting to server");
                exit(1);
            }

            // Read client request
            memset(client_buffer, 0, MAX_BUFFER_SIZE);
            int read_size = recv(client_socket, client_buffer, MAX_BUFFER_SIZE, 0);
            if (read_size < 0) {
                perror("Error reading client request");
                exit(1);
            }

            // Forward client request to server
            if (send(server_socket, client_buffer, strlen(client_buffer), 0) < 0) {
                perror("Error forwarding request to server");
                exit(1);
            }

            // Read server response
            memset(client_buffer, 0, MAX_BUFFER_SIZE);
            read_size = recv(server_socket, client_buffer, MAX_BUFFER_SIZE, 0);
            if (read_size < 0) {
                perror("Error reading server response");
                exit(1);
            }

            // Forward server response to client
            if (send(client_socket, client_buffer, strlen(client_buffer), 0) < 0) {
                perror("Error forwarding response to client");
                exit(1);
            }

            // Close sockets and exit child process
            close(client_socket);
            close(server_socket);
            exit(0);

        } else {
            // Parent process - continue listening for incoming connections
            continue;
        }
    }

    // Close proxy socket
    close(proxy_socket);

    return 0;
}