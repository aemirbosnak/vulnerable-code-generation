//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int port = 9090;
    int proxy_server_fd, client_fd, target_fd;
    struct sockaddr_in proxy_server_addr, client_addr, target_addr;
    char buffer[BUFFER_SIZE];

    // Initialize proxy server address
    memset(&proxy_server_addr, 0, sizeof(proxy_server_addr));
    proxy_server_addr.sin_family = AF_INET;
    proxy_server_addr.sin_port = htons(port);
    proxy_server_addr.sin_addr.s_addr = INADDR_ANY;

    // Create proxy server socket
    if ((proxy_server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error: Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind proxy server socket to local address and port
    if (bind(proxy_server_fd, (struct sockaddr *)&proxy_server_addr, sizeof(proxy_server_addr)) < 0) {
        perror("Error: Failed to bind socket to local address and port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(proxy_server_fd, 5) < 0) {
        perror("Error: Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server started on port %d\n", port);

    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);

        // Accept incoming client connection
        if ((client_fd = accept(proxy_server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Error: Failed to accept incoming client connection");
            continue;
        }

        // Get requested target server address and port from client
        memset(buffer, 0, sizeof(buffer));
        if (recv(client_fd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Error: Failed to receive data from client");
            close(client_fd);
            continue;
        }

        // Parse target server address and port from request
        char *host = strtok(buffer, " ");
        host = strtok(NULL, "//");
        host = strtok(NULL, "/");
        char *port_str = strstr(host, ":");
        char *path = strtok(NULL, " ");
        if (path == NULL) {
            path = "/";
        } else {
            strcat(path, "/");
        }

        // Set default port if not specified in request
        if (port_str == NULL) {
            port = 80;
        } else {
            port = atoi(port_str + 1);
            *port_str = '\0';
        }

        // Initialize target server address
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(port);
        if (inet_pton(AF_INET, host, &target_addr.sin_addr) <= 0) {
            perror("Error: Failed to parse target server address");
            close(client_fd);
            continue;
        }

        // Create target server socket
        if ((target_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Error: Failed to create socket");
            close(client_fd);
            continue;
        }

        // Connect to target server
        if (connect(target_fd, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
            perror("Error: Failed to connect to target server");
            close(client_fd);
            close(target_fd);
            continue;
        }

        // Forward HTTP request from client to target server
        if (send(target_fd, buffer, strlen(buffer), 0) < 0) {
            perror("Error: Failed to forward HTTP request from client to target server");
            close(client_fd);
            close(target_fd);
            continue;
        }

        // Receive HTTP response from target server and forward to client
        int bytes_received;
        while ((bytes_received = recv(target_fd, buffer, BUFFER_SIZE, 0)) > 0) {
            if (send(client_fd, buffer, bytes_received, 0) < 0) {
                perror("Error: Failed to forward HTTP response from target server to client");
                break;
            }
        }

        // Close client and target server sockets
        close(client_fd);
        close(target_fd);
    }

    return 0;
}