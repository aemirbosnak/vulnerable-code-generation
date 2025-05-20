//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define ERROR -1
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <proxy-port> <server-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int proxy_port = atoi(argv[1]);
    int server_port = atoi(argv[2]);

    struct sockaddr_in proxy_address, server_address;
    int proxy_socket, server_socket, optval = 1;

    // Create a proxy socket
    if ((proxy_socket = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
        perror("Error creating proxy socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address
    if (setsockopt(proxy_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == ERROR) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Bind proxy socket to address
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_address.sin_port = htons(proxy_port);
    if (bind(proxy_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) == ERROR) {
        perror("Error binding proxy socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for client connections
    if (listen(proxy_socket, MAX_CONNECTIONS) == ERROR) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    // Loop to handle client connections
    while (1) {
        char buffer[BUFFER_SIZE];
        int client_socket;

        // Accept client connection
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        if ((client_socket = accept(proxy_socket, (struct sockaddr *)&client_address, &client_address_len)) == ERROR) {
            perror("Error accepting client connection");
            continue;
        }

        // Create server socket
        if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
            perror("Error creating server socket");
            exit(EXIT_FAILURE);
        }

        // Connect to server
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // change to your desired server IP
        server_address.sin_port = htons(server_port);
        if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == ERROR) {
            perror("Error connecting to server");
            exit(EXIT_FAILURE);
        }

        // Loop to handle client requests and server responses
        while (1) {
            fd_set read_fds;
            FD_ZERO(&read_fds);
            FD_SET(client_socket, &read_fds);
            FD_SET(server_socket, &read_fds);

            // Check for activity on either socket
            if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) == ERROR) {
                perror("Error selecting socket");
                exit(EXIT_FAILURE);
            }

            // Check for data from client
            if (FD_ISSET(client_socket, &read_fds)) {
                int bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
                if (bytes_read == ERROR) {
                    perror("Error reading from client socket");
                    exit(EXIT_FAILURE);
                }
                if (bytes_read == 0) {
                    printf("Client disconnected\n");
                    break;
                }
                buffer[bytes_read] = '\0';
                printf("Received from client: %s", buffer);

                // Forward request to server
                if (send(server_socket, buffer, bytes_read, 0) == ERROR) {
                    perror("Error sending to server socket");
                    exit(EXIT_FAILURE);
                }
            }

            // Check for data from server
            if (FD_ISSET(server_socket, &read_fds)) {
                int bytes_read = recv(server_socket, buffer, BUFFER_SIZE, 0);
                if (bytes_read == ERROR) {
                    perror("Error reading from server socket");
                    exit(EXIT_FAILURE);
                }
                if (bytes_read == 0) {
                    printf("Server disconnected\n");
                    break;
                }
                buffer[bytes_read] = '\0';
                printf("Received from server: %s", buffer);

                // Forward response to client
                if (send(client_socket, buffer, bytes_read, 0) == ERROR) {
                    perror("Error sending to client socket");
                    exit(EXIT_FAILURE);
                }
            }
        }

        // Close sockets and reset buffers
        close(client_socket);
        close(server_socket);
        memset(buffer, 0, sizeof(buffer));
    }

    // Close proxy socket
    close(proxy_socket);

    return EXIT_SUCCESS;
}