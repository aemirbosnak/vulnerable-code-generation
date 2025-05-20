//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int port = 8080; // default port
    char *ip_address = "127.0.0.1"; // default IP address
    int server_socket, client_socket, address_size, read_size;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Could not create server socket\n");
        return 1;
    }

    // Prepare server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port);

    // Bind server socket to address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not bind server socket to address and port\n");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        printf("Error: Could not listen on server socket\n");
        return 1;
    }

    printf("Proxy server listening on port %d...\n", port);

    // Accept incoming connections
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_size)) > 0) {
        printf("New client connection accepted: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Read client request
        if ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[read_size] = '\0';
            printf("--> Received client request:\n%s\n", buffer);

            // Forward request to server
            if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                printf("Error: Could not create server socket\n");
                return 1;
            }

            if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
                printf("Error: Could not connect to server\n");
                return 1;
            }

            if (send(server_socket, buffer, strlen(buffer), 0) < 0) {
                printf("Error: Could not forward request to server\n");
                return 1;
            }

            printf("--> Forwarded request to server:\n%s\n", buffer);

            // Read server response
            memset(buffer, 0, BUFFER_SIZE);
            while ((read_size = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
                // Forward response to client
                if (send(client_socket, buffer, read_size, 0) < 0) {
                    printf("Error: Could not forward response to client\n");
                    return 1;
                }

                // Clear buffer for next read
                memset(buffer, 0, BUFFER_SIZE);
            }

            close(server_socket);

            printf("--> Forwarded server response to client\n");
        }

        close(client_socket);

        printf("Connection with client closed\n");
    }

    return 0;
}