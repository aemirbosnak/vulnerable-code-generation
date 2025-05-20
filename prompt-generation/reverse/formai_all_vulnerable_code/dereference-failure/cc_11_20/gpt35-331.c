//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <local_port> <remote_ip:remote_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse arguments
    int local_port = atoi(argv[1]);

    char *remote_ip_str = strtok(argv[2], ":");
    char *remote_port_str = strtok(NULL, ":");
    int remote_port = atoi(remote_port_str);

    struct in_addr remote_ip;
    if (inet_pton(AF_INET, remote_ip_str, &remote_ip) != 1) {
        perror("inet_pton() failed");
        exit(EXIT_FAILURE);
    }

    // Create local socket
    int local_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (local_sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Bind local socket
    struct sockaddr_in local_addr;
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(local_port);
    local_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(local_sock, (struct sockaddr *) &local_addr, sizeof(local_addr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // Listen on local socket
    if (listen(local_sock, 5) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(local_sock, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("accept() failed");
            continue;
        }

        // Connect to remote server
        int remote_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_sock < 0) {
            perror("socket() failed");
            close(client_sock);
            continue;
        }

        struct sockaddr_in remote_addr;
        memset(&remote_addr, 0, sizeof(remote_addr));
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(remote_port);
        memcpy(&remote_addr.sin_addr, &remote_ip, sizeof(remote_ip));

        if (connect(remote_sock, (struct sockaddr *) &remote_addr, sizeof(remote_addr)) < 0) {
            perror("connect() failed");
            close(client_sock);
            close(remote_sock);
            continue;
        }

        // Forward data between client and server
        char buffer[BUFFER_SIZE];
        int bytes_read;

        while ((bytes_read = read(client_sock, buffer, BUFFER_SIZE)) > 0) {
            if (write(remote_sock, buffer, bytes_read) < 0) {
                perror("write() failed");
                break;
            }
        }

        close(client_sock);
        close(remote_sock);
    }

    return 0;
}