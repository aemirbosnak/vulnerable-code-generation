//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void handle_request(int client_fd) {
    char buffer[BUFFER_SIZE];
    char method[16], url[256], protocol[16];

    // Read the request
    ssize_t request_size = recv(client_fd, buffer, BUFFER_SIZE - 1, 0);
    if (request_size < 0) {
        error("Failed to read request");
    }
    buffer[request_size] = '\0';

    // Parse the request line
    sscanf(buffer, "%s %s %s", method, url, protocol);
    printf("Request Method: %s \nRequest URL: %s \n", method, url);

    // Find the host from the URL
    char host[256];
    char *host_start = strstr(url, "://");
    if (host_start) {
        host_start += 3; // Skip past "://"
    } else {
        host_start = url; // In case of a URL without scheme
    }
    char *host_end = strchr(host_start, '/');
    if (host_end) {
        strncpy(host, host_start, host_end - host_start);
        host[host_end - host_start] = '\0';
    } else {
        strcpy(host, host_start);
    }

    // Create a socket to connect to the real server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        error("Could not create socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Default HTTP port
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change as needed

    // Connect to the server
    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connect to server failed");
    }

    // Forward the request to the server
    send(server_fd, buffer, request_size, 0);

    // Read the response from the server
    while ((request_size = recv(server_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[request_size] = '\0'; // Null-terminate the string
        send(client_fd, buffer, request_size, 0); // Send the response back to the client
    }

    // Clean up
    close(server_fd);
    close(client_fd);
}

int main() {
    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd < 0) {
        error("Could not create socket");
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all available interfaces
    proxy_addr.sin_port = htons(PORT);

    if (bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        error("Binding failed");
    }

    if (listen(proxy_fd, 5) < 0) {
        error("Listening failed");
    }

    printf("Proxy server is running on port %d...\n", PORT);
    
    while (1) {
        int client_fd = accept(proxy_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("Accept failed");
            continue;
        }
        handle_request(client_fd);
    }

    close(proxy_fd);
    return 0;
}