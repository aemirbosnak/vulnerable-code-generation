//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <local port> <remote address> <remote port>\n", argv[0]);
        return 1;
    }

    // Get local port, remote address, and remote port
    int local_port = atoi(argv[1]);
    const char *remote_address = argv[2];
    int remote_port = atoi(argv[3]);

    // Create listen socket
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        return 1;
    }

    // Set listen socket options
    int optval = 1;
    if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Bind listen socket to local port
    struct sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(local_port);
    if (bind(listen_sock, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen on listen socket
    if (listen(listen_sock, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections
    while (1) {
        // Accept client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        // Create remote socket
        int remote_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_sock == -1) {
            perror("socket");
            close(client_sock);
            continue;
        }

        // Connect remote socket to remote address and port
        struct sockaddr_in remote_addr;
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr.s_addr = inet_addr(remote_address);
        remote_addr.sin_port = htons(remote_port);
        if (connect(remote_sock, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
            perror("connect");
            close(client_sock);
            close(remote_sock);
            continue;
        }

        // Start proxying data between client and remote sockets
        int n;
        char buff[BUFF_SIZE];
        while ((n = read(client_sock, buff, BUFF_SIZE)) > 0) {
            if (write(remote_sock, buff, n) == -1) {
                perror("write");
                break;
            }
        }
        if (n == -1) {
            perror("read");
        }

        close(client_sock);
        close(remote_sock);
    }

    // Close listen socket
    close(listen_sock);

    return 0;
}