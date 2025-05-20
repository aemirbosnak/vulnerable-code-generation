//GEMINI-pro DATASET v1.0 Category: Networking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Recursive function to send data to a client
int send_data(int sockfd, char *data, int len, int offset) {
    if (offset >= len) {
        return 0;
    }

    int bytes_sent = send(sockfd, data + offset, len - offset, 0);
    if (bytes_sent < 0) {
        return -1;
    }

    return send_data(sockfd, data, len, offset + bytes_sent);
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to an address and port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept a connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd < 0) {
        perror("accept");
        return EXIT_FAILURE;
    }

    // Send data to the client
    char *data = "Hello, world!";
    int len = strlen(data);
    if (send_data(client_sockfd, data, len, 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the client socket
    close(client_sockfd);

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}