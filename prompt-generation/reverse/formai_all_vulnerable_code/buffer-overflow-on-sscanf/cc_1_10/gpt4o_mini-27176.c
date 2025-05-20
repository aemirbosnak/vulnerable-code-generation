//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Read the client's request
    bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read <= 0) {
        perror("Failed to read from client");
        close(client_socket);
        return;
    }
    buffer[bytes_read] = '\0';

    // Extract the host and port from the HTTP request
    char method[16], url[256], version[16];
    sscanf(buffer, "%s %s %s", method, url, version);
    char host[256] = {0};
    int port = 80;

    if (strncmp(url, "http://", 7) == 0) {
        strcpy(host, url + 7);
    } else {
        snprintf(host, sizeof(host), "%s", url);
    }

    char *port_ptr = strchr(host, ':');
    if (port_ptr) {
        *port_ptr = '\0';
        port = atoi(port_ptr + 1);
    }

    // Create a socket to connect to the destination server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host); // Convert to IP

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Forward the request to the server
    send(server_socket, buffer, bytes_read, 0);

    // Read the server's response and send it back to the client
    while ((bytes_read = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }

    // Close the sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Failed to create socket");
        return 1;
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Failed to bind socket");
        close(proxy_socket);
        return 1;
    }

    // Start listening for clients
    if (listen(proxy_socket, 10) < 0) {
        perror("Failed to listen");
        close(proxy_socket);
        return 1;
    }

    printf("Proxy server listening on port %d\n", PORT);
    
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Failed to accept client");
            continue;
        }

        // Handle the client in a separate function
        handle_client(client_socket);
    }

    close(proxy_socket);
    return 0;
}