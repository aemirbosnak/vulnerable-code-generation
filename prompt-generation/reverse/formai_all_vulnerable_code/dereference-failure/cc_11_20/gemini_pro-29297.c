//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: ephemeral
// Ephemeral TCP/IP echo server

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the ephemeral port range
#define EPHEMERAL_PORT_START 49152
#define EPHEMERAL_PORT_END 65535

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert the port number to an integer
    int port = atoi(argv[1]);

    // Check if the port is within the ephemeral range
    if (port < EPHEMERAL_PORT_START || port > EPHEMERAL_PORT_END) {
        fprintf(stderr, "Invalid port number: %d\n", port);
        return EXIT_FAILURE;
    }

    // Create a new socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket to be reusable
    int reuseaddr = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind the socket to the ephemeral port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections and echo data back to the client
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Read data from the client
        char buffer[1024];
        ssize_t bytes_read = read(client_sockfd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            perror("read");
            close(client_sockfd);
            continue;
        }

        // Write data back to the client
        if (write(client_sockfd, buffer, bytes_read) == -1) {
            perror("write");
            close(client_sockfd);
            continue;
        }

        // Close the client socket
        close(client_sockfd);
    }

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}