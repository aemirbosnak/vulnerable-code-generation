//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void handle_client(int client_socket);
void forward_request(int client_socket, const char *host, const char *port, const char *request);
void extract_host_and_port(const char *request, char *host, char *port);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PORT);

    // Main server loop
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue; // Go back to listening for connections
        }
        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 1) {
        perror("Failed to receive data");
        return;
    }
    buffer[bytes_received] = '\0'; // Null terminate the request

    char host[256] = {0};
    char port[10] = "80"; // Default port
    extract_host_and_port(buffer, host, port);

    printf("Forwarding request to host: %s, port: %s\n", host, port);
    forward_request(client_socket, host, port, buffer);
}

void forward_request(int client_socket, const char *host, const char *port, const char *request) {
    int server_socket;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create a socket for the remote server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket for server");
        return;
    }

    // Get server details
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", host);
        close(server_socket);
        return;
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(atoi(port));

    // Connect to the remote server
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(server_socket);
        return;
    }

    // Forward the request to the server
    send(server_socket, request, strlen(request), 0);

    // Receive response from the server
    char response[BUFFER_SIZE];
    int response_length;
    while ((response_length = recv(server_socket, response, sizeof(response) - 1, 0)) > 0) {
        response[response_length] = '\0'; // Null terminate the response
        send(client_socket, response, response_length, 0);
    }

    if (response_length < 0) {
        perror("Failed to receive response from server");
    }

    close(server_socket);
}

void extract_host_and_port(const char *request, char *host, char *port) {
    sscanf(request, "GET http://%[^:/]:%s", host, port);
    if (strlen(port) == 0) {
        strcpy(port, "80"); // Default to port 80 if none is provided
    }
}