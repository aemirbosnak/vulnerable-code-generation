//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 65536

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./proxy <listen_port> <target_ip:target_port>\n");
        return 0;
    }

    // Parse command line arguments
    int listen_port = atoi(argv[1]);
    char target_ip[16];
    int target_port;
    sscanf(argv[2], "%[^:]:%d", target_ip, &target_port);

    // Create socket for listening
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        perror("Failed to create listening socket");
        return -1;
    }

    // Bind listening socket to specified port
    struct sockaddr_in server_addr;
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(listen_port);
    if (bind(listen_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind listening socket");
        return -1;
    }

    // Listen for incoming connections
    if (listen(listen_socket, 10) < 0) {
        perror("Failed to listen on listening socket");
        return -1;
    }
    printf("Listening on port %d\n", listen_port);

    while (1) {
        // Accept incoming connections
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_socket = accept(listen_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Failed to accept incoming connection");
            continue;
        }

        // Read request from client
        char buffer[BUFFER_SIZE];
        memset(buffer, '\0', BUFFER_SIZE);
        int bytes_read = read(client_socket, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            perror("Failed to read request from client");
            close(client_socket);
            continue;
        }

        // Extract host and port from request
        char host[256];
        int port;
        char *p = strstr(buffer, "Host: ");
        if (p != NULL) {
            sscanf(p+6, "%[^:\r\n]:%d", host, &port);
        } else {
            strcpy(host, target_ip);
            port = target_port;
        }

        // Create socket for connecting to target server
        int target_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (target_socket < 0) {
            perror("Failed to create target socket");
            close(client_socket);
            continue;
        }

        // Connect to target server
        struct sockaddr_in target_addr;
        memset(&target_addr, '\0', sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(host);
        target_addr.sin_port = htons(port);
        if (connect(target_socket, (struct sockaddr*)&target_addr, sizeof(target_addr)) < 0) {
            perror("Failed to connect to target server");
            close(client_socket);
            close(target_socket);
            continue;
        }

        // Write request to target server
        if (write(target_socket, buffer, bytes_read) < 0) {
            perror("Failed to write request to target server");
            close(client_socket);
            close(target_socket);
            continue;
        }

        // Read response from target server and send it back to client
        while (1) {
            memset(buffer, '\0', BUFFER_SIZE);
            bytes_read = read(target_socket, buffer, BUFFER_SIZE);
            if (bytes_read < 0) {
                perror("Failed to read response from target server");
                close(client_socket);
                close(target_socket);
                break;
            } else if (bytes_read == 0) {
                break;
            }
            if (write(client_socket, buffer, bytes_read) < 0) {
                perror("Failed to send response to client");
                close(client_socket);
                close(target_socket);
                break;
            }
        }

        // Close sockets
        close(client_socket);
        close(target_socket);
    }

    return 0;
}