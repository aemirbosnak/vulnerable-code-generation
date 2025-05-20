//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

    if (bytes_received < 0) {
        perror("Error receiving request");
        close(client_socket);
        return;
    }

    buffer[bytes_received] = '\0';  // Null-terminate the buffer
    printf("Received request:\n%s\n", buffer);

    char *request_line = strtok(buffer, "\r\n");
    if (request_line == NULL) {
        close(client_socket);
        return;
    }

    char method[16], url[256], version[16];
    sscanf(request_line, "%s %s %s", method, url, version);

    // Extract the host from the URL
    char *host_start = strstr(url, "://");
    if (host_start) {
        host_start += 3; // Skip "://"
    } else {
        host_start = url;
    }

    char *host_end = strchr(host_start, '/');
    if (host_end) *host_end = '\0';  // Terminate at the end of host

    // Provide defaults
    char *hostname = host_start;
    int port = 80;

    // If the host has a port specified
    char *port_start = strchr(hostname, ':');
    if (port_start) {
        *port_start = '\0';
        port = atoi(port_start + 1);
    }

    // Set up the server connection
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to the target server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Forward the original request to the destination server
    send(server_socket, buffer, bytes_received, 0);

    // Read the server's response
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0); // Send to client
    }

    // Cleanup and closure
    close(server_socket);
    close(client_socket);
}

int main() {
    printf("🎉 Starting Simple HTTP Proxy on port %d 🎉\n", PORT);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Could not create socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("✅ Proxy is running, waiting for connections...\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }

        printf("🔗 Accepted new connection!\n");
        handle_client(client_socket);  // Handle the connected client
    }

    close(server_socket);
    return EXIT_SUCCESS;
}