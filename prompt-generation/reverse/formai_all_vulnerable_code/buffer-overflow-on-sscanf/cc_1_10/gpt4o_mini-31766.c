//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void *handle_client(void *client_socket);
void error(const char *msg);

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("Socket failed");
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Bind failed");
    }

    // Start listening for connections
    if (listen(server_fd, 10) < 0) {
        error("Listen failed");
    }
    printf("Proxy server listening on port %d\n", PORT);

    // Accepting connections in an infinite loop
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            error("Accept failed");
        }
        printf("Accepted a connection from client\n");

        // Create a new thread for handling client requests
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_fd) != 0) {
            error("Thread creation failed");
        }
        pthread_detach(thread_id);
    }

    close(server_fd);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    char method[16], url[256], protocol[16];

    // Read request from the client
    int read_size = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (read_size < 0) {
        perror("Recv failed");
        close(sock);
        return NULL;
    }
    buffer[read_size] = '\0';

    // Parse the HTTP request
    sscanf(buffer, "%s %s %s", method, url, protocol);

    // Open a socket to connect to the target server
    int target_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (target_fd < 0) {
        perror("Socket to target server failed");
        close(sock);
        return NULL;
    }

    // Extract the host and port information from the URL
    char *host = strstr(url, "://") ? strstr(url, "://") + 3 : url; // Skip "http://"
    char *port_str = strchr(host, ':');
    char *path = port_str ? strchr(host, '/') : NULL;

    char target_host[64];
    int target_port = 80; // Default HTTP port

    if (port_str) {
        strncpy(target_host, host, port_str - host);
        target_host[port_str - host] = '\0'; // null terminate the hostname
        target_port = atoi(port_str + 1);
        if (path) {
            path[0] = '\0'; // Temporarily terminate the hostname
        }
    } else {
        snprintf(target_host, sizeof(target_host), "%s", host);
        if (path) {
            path[0] = '/'; // If there is a path, keep the leading slash
        }
    }

    // Connect to the target server
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(target_port);
    target_addr.sin_addr.s_addr = inet_addr(target_host);

    if (connect(target_fd, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        perror("Connection to target server failed");
        close(sock);
        return NULL;
    }

    // Forward the request to the target server
    if (path) {
        snprintf(buffer, sizeof(buffer), "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", method, path, target_host);
    } else {
        snprintf(buffer, sizeof(buffer), "%s / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", method, target_host);
    }
    
    send(target_fd, buffer, strlen(buffer), 0);

    // Read the response from the target server and forward it to the client
    while ((read_size = recv(target_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        send(sock, buffer, read_size, 0);
    }

    // Clean up
    close(target_fd);
    close(sock);
    return NULL;
}

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}