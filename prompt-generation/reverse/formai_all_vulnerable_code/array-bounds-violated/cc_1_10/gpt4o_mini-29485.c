//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8888
#define BUFFER_SIZE 2048

void handle_client(int client_sock);
void error(const char *msg);

int main() {
    int server_sock, client_sock;
    socklen_t addr_len;
    struct sockaddr_in server_addr, client_addr;

    // Create a socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error("Error opening socket");
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(server_sock);
        error("Error binding socket");
    }

    // Listen for incoming connections
    listen(server_sock, 5);
    printf("Proxy server is running on port %d...\n", PORT);

    // Handle SIGINT to stop the server gracefully
    signal(SIGINT, SIG_DFL);

    while (1) {
        // Accept a connection
        addr_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sock < 0) {
            close(server_sock);
            error("Error accepting client connection");
        }

        // Handle the client in a separate function
        handle_client(client_sock);
    }

    // Close the server socket
    close(server_sock);
    return 0;
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int received_bytes;
    char method[8], url[256], protocol[16];
    char host[128], port[8];
    int port_num = 80;

    // Read the request from the client
    received_bytes = recv(client_sock, buffer, BUFFER_SIZE - 1, 0);
    if (received_bytes < 0) {
        close(client_sock);
        error("Error reading from client");
    }
    buffer[received_bytes] = '\0';

    // Parse the HTTP request line
    if (sscanf(buffer, "%7s %255s %15s", method, url, protocol) < 3) {
        close(client_sock);
        error("Invalid HTTP request");
    }

    // Extract host and port (if specified)
    if (sscanf(url, "http://%127[^:]:%7s", host, port) == 2) {
        port_num = atoi(port);
    } else if (sscanf(url, "http://%127[^/]", host) == 1) {
        // Default port 80
    } else {
        close(client_sock);
        error("Unsupported URL format");
    }

    // Create a socket for the destination server
    int dest_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (dest_sock < 0) {
        close(client_sock);
        error("Error creating destination socket");
    }

    // Set up the destination server address structure
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port_num);
    if (inet_pton(AF_INET, host, &dest_addr.sin_addr) <= 0) {
        close(dest_sock);
        close(client_sock);
        error("Invalid address for destination server");
    }

    // Connect to the destination server
    if (connect(dest_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        close(dest_sock);
        close(client_sock);
        error("Error connecting to destination server");
    }

    // Forward the HTTP request to the destination server
    send(dest_sock, buffer, received_bytes, 0);

    // Receive the response from the server
    while ((received_bytes = recv(dest_sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[received_bytes] = '\0';
        send(client_sock, buffer, received_bytes, 0);
    }

    // Clean up
    close(dest_sock);
    close(client_sock);
}

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}