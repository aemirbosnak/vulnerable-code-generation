//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 8080
#define BUF_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void handle_client(int client_fd) {
    char buffer[BUF_SIZE];
    
    // Read the request from the client
    int bytes_read = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read <= 0) {
        die("Failed to read request");
    }
    buffer[bytes_read] = '\0';  // Null terminate the received data

    // Display the request for curiosity
    printf("Received Request:\n%s\n", buffer);

    // Parse the request to extract the URL
    char method[10], url[256], http_version[20];
    sscanf(buffer, "%s %s %s", method, url, http_version);
    
    // Checking for only GET requests (for simplicity)
    if (strcmp(method, "GET") != 0) {
        fprintf(stderr, "Only GET method is supported!\n");
        close(client_fd);
        return;
    }

    // Opening the connection to the target server
    char *host_start = strstr(url, "//") + 2;  // Skip "http://"
    char *host_end = strstr(host_start, "/");
    if (!host_end) host_end = host_start + strlen(host_start); // No path

    char host[256];
    strncpy(host, host_start, host_end - host_start);
    host[host_end - host_start] = '\0';  // Null terminate the host string

    int target_port = 80; // Default HTTP port
    if (strstr(host, ":")) {
        char *port_start = strrchr(host, ':') + 1;
        target_port = atoi(port_start);
        *strrchr(host, ':') = '\0'; // Remove the port number from host
    }

    // Creating socket to connect to the target server
    int target_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (target_fd < 0) die("Failed to create socket");

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Connect to the target server
    if (connect(target_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection to target server failed");
    }

    // Forward the request to the target server
    send(target_fd, buffer, bytes_read, 0);

    // Read the response from the target server and send it back to the client
    while ((bytes_read = recv(target_fd, buffer, sizeof(buffer), 0)) > 0) {
        send(client_fd, buffer, bytes_read, 0);
    }

    // Close sockets
    close(target_fd);
    close(client_fd);
}

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) die("Failed to create socket");

    // Setting up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Failed to bind");
    }

    // Start listening for connections
    if (listen(server_fd, 10) < 0) {
        die("Failed to listen");
    }

    printf("Listening on port %d for HTTP requests...\n", PORT);

    // Accept client connections in a loop
    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            die("Failed to accept connection");
        }
        printf("Accepted a new connection...\n");

        // Handle the client in a new function
        handle_client(client_fd);
    }

    // Close the server socket (never reached in this case)
    close(server_fd);
    return 0;
}