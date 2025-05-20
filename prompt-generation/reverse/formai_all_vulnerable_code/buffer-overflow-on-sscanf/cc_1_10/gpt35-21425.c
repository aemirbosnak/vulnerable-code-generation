//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PROXY_PORT 8080
#define BUFFER_SIZE 1024

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE], request[BUFFER_SIZE], response[BUFFER_SIZE];
    int server_socket, bytes_read, bytes_sent;

    // Read the client's request
    bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_read <= 0) {
        printf("Error: Failed to read client request\n");
        return;
    }

    // Parse the request to extract the URL
    sscanf(buffer, "%s", request);
    char* url = strstr(request, "http://");
    if (url == NULL) {
        printf("Error: Invalid request: %s\n", request);
        return;
    }
    url += strlen("http://");

    // Open a connection to the server
    struct sockaddr_in server_address;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error: Failed to create server socket\n");
        return;
    }
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(url);
    server_address.sin_port = htons(80);
    if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to connect to server\n");
        close(server_socket);
        return;
    }

    // Forward the request to the server
    bytes_sent = send(server_socket, buffer, bytes_read, 0);
    if (bytes_sent != bytes_read) {
        printf("Error: Failed to forward request to server\n");
        close(server_socket);
        return;
    }

    // Read the server's response
    bytes_read = recv(server_socket, response, BUFFER_SIZE, 0);
    if (bytes_read <= 0) {
        printf("Error: Failed to read response from server\n");
        close(server_socket);
        return;
    }

    // Forward the response to the client
    bytes_sent = send(client_socket, response, bytes_read, 0);
    if (bytes_sent != bytes_read) {
        printf("Error: Failed to forward response to client\n");
        close(server_socket);
        return;
    }

    // Close the connections
    close(server_socket);
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size = sizeof(client_address);

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error: Failed to create server socket\n");
        return 1;
    }

    // Bind the server socket to a specific port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PROXY_PORT);
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to bind server socket\n");
        return 1;
    }

    // Listen for incoming client connections
    if (listen(server_socket, 10) < 0) {
        printf("Error: Failed to listen for incoming connections\n");
        return 1;
    }

    // Accept incoming client connections and handle each request
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
        if (client_socket < 0) {
            printf("Error: Failed to accept incoming connection\n");
            break;
        }

        // Handle the client's request in a new thread
        handle_request(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}