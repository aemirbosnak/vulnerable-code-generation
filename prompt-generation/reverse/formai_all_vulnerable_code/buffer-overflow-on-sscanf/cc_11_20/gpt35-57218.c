//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PROXY_PORT 8888
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int proxy_socket, client_socket;
    struct sockaddr_in proxy_address, client_address;
    char buffer[BUFFER_SIZE], requested_url[BUFFER_SIZE];

    // Set up proxy socket
    if ((proxy_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_address.sin_port = htons(PROXY_PORT);

    if (bind(proxy_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Failed to bind");
        exit(EXIT_FAILURE);
    }

    if (listen(proxy_socket, 1) < 0) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    printf("Proxy is listening on port %d...\n", PROXY_PORT);

    // Accept incoming connections
    while (1) {
        socklen_t client_address_length = sizeof(client_address);
        if ((client_socket = accept(proxy_socket, (struct sockaddr *)&client_address, &client_address_length)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        // Read request from client
        ssize_t read_count = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (read_count < 0) {
            perror("Failed to read from client");
            close(client_socket);
            continue;
        }

        // Extract requested URL
        sscanf(buffer, "GET http://%s HTTP/1.1", requested_url);
        printf("Requested URL: %s\n", requested_url);

        // Forward request to server and relay response to client
        int server_socket;
        struct sockaddr_in server_address;
        memset(&server_address, 0, sizeof(server_address));

        if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Failed to create socket");
            close(client_socket);
            continue;
        }

        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr(requested_url);
        server_address.sin_port = htons(80);

        if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
            perror("Failed to connect to server");
            close(client_socket);
            continue;
        }

        if (send(server_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Failed to forward request to server");
            close(client_socket);
            continue;
        }

        while ((read_count = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            if (send(client_socket, buffer, read_count, 0) < 0) {
                perror("Failed to relay response to client");
                break;
            }
        }

        if (read_count < 0) {
            perror("Failed to read from server");
        }

        close(server_socket);
        close(client_socket);
    }

    return 0;
}