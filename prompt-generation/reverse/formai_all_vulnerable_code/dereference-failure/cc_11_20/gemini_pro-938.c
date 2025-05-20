//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <localhost_port> <remote_host:port>\n", argv[0]);
        return 1;
    }

    // Parse the localhost port
    int localhost_port = atoi(argv[1]);
    if (localhost_port <= 0) {
        fprintf(stderr, "Invalid localhost port: %s\n", argv[1]);
        return 1;
    }

    // Parse the remote host and port
    char *remote_host;
    int remote_port;
    sscanf(argv[2], "%[^:]:%d", remote_host, &remote_port);
    if (strlen(remote_host) == 0 || remote_port <= 0) {
        fprintf(stderr, "Invalid remote host and port: %s\n", argv[2]);
        return 1;
    }

    // Create a socket for listening on the localhost port
    int localhost_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (localhost_socket == -1) {
        perror("socket");
        return 1;
    }

    // Set the socket to reuse the address
    int on = 1;
    if (setsockopt(localhost_socket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Bind the socket to the localhost port
    struct sockaddr_in localhost_addr;
    localhost_addr.sin_family = AF_INET;
    localhost_addr.sin_addr.s_addr = INADDR_ANY;
    localhost_addr.sin_port = htons(localhost_port);
    if (bind(localhost_socket, (struct sockaddr *) &localhost_addr, sizeof(localhost_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen on the localhost port
    if (listen(localhost_socket, SOMAXCONN) == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        // Accept a connection on the localhost port
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(localhost_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a socket for connecting to the remote host
        int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_socket == -1) {
            perror("socket");
            close(client_socket);
            continue;
        }

        // Connect to the remote host
        struct sockaddr_in remote_addr;
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr.s_addr = inet_addr(remote_host);
        remote_addr.sin_port = htons(remote_port);
        if (connect(remote_socket, (struct sockaddr *) &remote_addr, sizeof(remote_addr)) == -1) {
            perror("connect");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        // Forward data between the client and the remote host
        char buffer[BUFFER_SIZE];
        int n;
        while ((n = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
            int i;
            for (i = 0; i < n; i++) {
                buffer[i] = buffer[i] * 2;
            }
            write(remote_socket, buffer, n);
        }
        if (n == -1) {
            perror("read");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        // Close the client and remote sockets
        close(client_socket);
        close(remote_socket);
    }

    // Close the localhost socket
    close(localhost_socket);

    return 0;
}