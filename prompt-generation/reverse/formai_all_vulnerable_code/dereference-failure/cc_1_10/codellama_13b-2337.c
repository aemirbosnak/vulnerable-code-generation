//Code Llama-13B DATASET v1.0 Category: Simple Web Server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen = sizeof(client_addr);
    char buf[1024];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen on the socket
    if (listen(sockfd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Loop to receive and send data
    while (1) {
        // Accept the connection
        new_fd = accept(sockfd, (struct sockaddr *) &client_addr, &addrlen);
        if (new_fd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Receive the data
        int n = read(new_fd, buf, 1024);
        if (n < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        // Echo the data back to the client
        write(new_fd, buf, n);

        // Close the connection
        close(new_fd);
    }

    return 0;
}