//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <Server Address> <Server Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create Proxy Socket
    int proxy_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sockfd == -1) {
        printf("Failed to create socket for proxy\n");
        exit(EXIT_FAILURE);
    }

    // Set proxy socket options
    int opt_enable = 1;
    if (setsockopt(proxy_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt_enable, sizeof(opt_enable)) < 0) {
        printf("Failed to set socket options for proxy\n");
        exit(EXIT_FAILURE);
    }

    // Bind proxy socket to localhost:8080
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(8080);

    if (bind(proxy_sockfd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        printf("Failed to bind socket for proxy\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(proxy_sockfd, SOMAXCONN) == -1) {
        printf("Failed to listen on proxy socket\n");
        exit(EXIT_FAILURE);
    }

    // Accept connections and handle requests
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sockfd = accept(proxy_sockfd, (struct sockaddr *)&client_addr, &client_len);

        if (client_sockfd == -1) {
            printf("Failed to accept client connection\n");
            continue;
        }

        char buffer[BUFFERSIZE];
        memset(buffer, 0, BUFFERSIZE);

        // Read HTTP Request
        if (recv(client_sockfd, buffer, BUFFERSIZE, 0) == -1) {
            printf("Failed to receive request from client\n");
            continue;
        }

        printf("Received request from client: %s\n", buffer);

        // Extract Host and Port from Request
        char *host_start = strstr(buffer, "Host: ") + 6;
        char *host_end = strstr(host_start, "\r\n");
        char *port_start = strstr(host_start, ":") + 1;

        int port = 80; // Default HTTP Port
        if (port_start < host_end) {
            char port_buffer[6];
            memset(port_buffer, 0, 6);
            strncpy(port_buffer, port_start, host_end - port_start);
            port = atoi(port_buffer);
        }

        char host[256];
        memset(host, 0, 256);
        strncpy(host, host_start, host_end - host_start);

        // Create Server Socket
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd == -1) {
            printf("Failed to create socket for server\n");
            continue;
        }

        // Connect to Server
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(argv[1]);
        server_addr.sin_port = htons(atoi(argv[2]));

        if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            printf("Failed to connect to server\n");
            close(server_sockfd);
            continue;
        }

        // Forward Request to Server
        if (send(server_sockfd, buffer, strlen(buffer), 0) == -1) {
            printf("Failed to send request to server\n");
            close(server_sockfd);
            continue;
        }

        memset(buffer, 0, BUFFERSIZE);

        // Read Response from Server
        if (recv(server_sockfd, buffer, BUFFERSIZE, 0) == -1) {
            printf("Failed to receive response from server\n");
            close(server_sockfd);
            continue;
        }

        printf("Received response from server: %s\n", buffer);

        // Forward Response to Client
        if (send(client_sockfd, buffer, strlen(buffer), 0) == -1) {
            printf("Failed to send response to client\n");
            close(server_sockfd);
            close(client_sockfd);
            continue;
        }

        close(server_sockfd);
        close(client_sockfd);
    }

    return 0;
}