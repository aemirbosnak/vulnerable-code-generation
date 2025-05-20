//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <client/server>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Bind the socket to the port
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for connections
    if (strcmp(argv[1], "server") == 0) {
        if (listen(sockfd, 10) == -1) {
            perror("listen");
            return 1;
        }

        // Accept a connection
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            return 1;
        }

        // Read data from the client
        char buffer[1024] = {0};
        int n = read(client_sockfd, buffer, sizeof(buffer));
        if (n == -1) {
            perror("read");
            return 1;
        }

        // Write data to the client
        n = write(client_sockfd, buffer, strlen(buffer));
        if (n == -1) {
            perror("write");
            return 1;
        }

        // Close the client socket
        close(client_sockfd);
    } else if (strcmp(argv[1], "client") == 0) {
        // Connect to the server
        if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
            perror("connect");
            return 1;
        }

        // Send data to the server
        char buffer[1024] = "Hello, world!";
        int n = write(sockfd, buffer, strlen(buffer));
        if (n == -1) {
            perror("write");
            return 1;
        }

        // Read data from the server
        n = read(sockfd, buffer, sizeof(buffer));
        if (n == -1) {
            perror("read");
            return 1;
        }

        // Print the data from the server
        printf("Received: %s\n", buffer);

        // Close the socket
        close(sockfd);
    }

    return 0;
}