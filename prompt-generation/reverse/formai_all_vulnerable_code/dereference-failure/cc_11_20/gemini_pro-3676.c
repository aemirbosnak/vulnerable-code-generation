//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    int sock_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char buf[BUFSIZE];
    int bytes_read, bytes_written;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    // Create a socket.
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address.
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // Connect to the server.
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Accept connections from clients.
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        // Read the request from the client.
        while ((bytes_read = read(client_fd, buf, BUFSIZE)) > 0) {
            // Write the request to the server.
            bytes_written = write(sock_fd, buf, bytes_read);
            if (bytes_written < 0) {
                perror("write");
                break;
            }
        }

        if (bytes_read < 0) {
            perror("read");
        }

        // Read the response from the server.
        while ((bytes_read = read(sock_fd, buf, BUFSIZE)) > 0) {
            // Write the response to the client.
            bytes_written = write(client_fd, buf, bytes_read);
            if (bytes_written < 0) {
                perror("write");
                break;
            }
        }

        if (bytes_read < 0) {
            perror("read");
        }

        // Close the connection to the client.
        close(client_fd);
    }

    // Close the socket.
    close(sock_fd);

    return 0;
}