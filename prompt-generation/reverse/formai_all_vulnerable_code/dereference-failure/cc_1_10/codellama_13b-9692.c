//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: complete
/*
 * TCP/IP Programming Example
 *
 * This program is a simple TCP server that listens on a specified port
 * for incoming connections. When a connection is established, it
 * reads the incoming data and sends it back to the client.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set address and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client;
        socklen_t client_len = sizeof(client);
        int client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        // Read incoming data
        char buf[1024];
        int bytes_read = read(client_sock, buf, sizeof(buf));
        if (bytes_read < 0) {
            perror("read");
            continue;
        }

        // Send data back to client
        if (write(client_sock, buf, bytes_read) < 0) {
            perror("write");
            continue;
        }

        // Close client socket
        close(client_sock);
    }

    // Close server socket
    close(sock);

    return 0;
}