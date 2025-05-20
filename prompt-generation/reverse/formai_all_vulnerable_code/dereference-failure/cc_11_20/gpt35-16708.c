//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int client_fd, server_fd, bytes_read, bytes_sent, port, proxy_fd;
    struct sockaddr_in client_addr, server_addr, proxy_addr;
    char buffer[BUFFER_SIZE];
    char *proxy_ip;

    if (argc < 4) {
        printf("Usage: %s <proxy_ip> <proxy_port> <server_address> <server_port>\n", argv[0]);
        exit(1);
    }

    proxy_ip = argv[1];
    port = atoi(argv[2]);

    // Setup a proxy server socket
    proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd < 0) {
        printf("Failed to create a proxy server socket!\n");
        exit(1);
    }

    // Bind the proxy server socket to the given IP address and port
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr(proxy_ip);
    proxy_addr.sin_port = htons(port);
    if (bind(proxy_fd, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0) {
        printf("Failed to bind the proxy server socket!\n");
        exit(1);
    }

    // Listen for incoming requests
    if (listen(proxy_fd, 5) < 0) {
        printf("Failed to listen on the proxy server socket!\n");
        exit(1);
    }

    printf("HTTP proxy server running on %s:%d\n", proxy_ip, port);

    while (1) {
        socklen_t client_len = sizeof(client_addr);
        // Accept incoming client requests
        client_fd = accept(proxy_fd, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd < 0) {
            printf("Failed to accept incoming client request!\n");
            continue;
        }

        printf("Accepted incoming client request from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Setup a server socket
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd < 0) {
            printf("Failed to create a server socket!\n");
            exit(1);
        }

        // Connect to the server
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(argv[3]);
        server_addr.sin_port = htons(atoi(argv[4]));
        if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            printf("Failed to connect to server!\n");
            exit(1);
        }

        printf("Connected to server %s:%s\n", argv[3], argv[4]);

        // Forward the client's request to the server
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = read(client_fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            printf("Failed to read from client socket!\n");
            continue;
        }

        bytes_sent = write(server_fd, buffer, bytes_read);
        if (bytes_sent != bytes_read) {
            printf("Failed to forward request to server!\n");
            continue;
        }

        printf("Forwarded request from client to server!\n");

        // Forward the server's response to the client
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = read(server_fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            printf("Failed to read from server socket!\n");
            continue;
        }

        bytes_sent = write(client_fd, buffer, bytes_read);
        if (bytes_sent != bytes_read) {
            printf("Failed to forward response to client!\n");
            continue;
        }

        printf("Forwarded response from server to client!\n");

        // Close the client and server sockets
        close(client_fd);
        close(server_fd);
        printf("Closed client and server sockets!\n");
    }

    return 0;
}