//Code Llama-13B DATASET v1.0 Category: Networking ; Style: brave
// Brave Networking Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF 1024
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Set up server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    // Set up server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        // Handle client connection
        char buf[MAX_BUF];
        int bytes_read = read(client_fd, buf, MAX_BUF);
        if (bytes_read < 0) {
            perror("read");
            close(client_fd);
            continue;
        }

        // Echo back message
        printf("Received: %s\n", buf);
        if (write(client_fd, buf, bytes_read) < 0) {
            perror("write");
            close(client_fd);
            continue;
        }

        close(client_fd);
    }

    return 0;
}