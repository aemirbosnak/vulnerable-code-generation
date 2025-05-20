//GEMINI-pro DATASET v1.0 Category: Networking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

#define BACKLOG 10

int main(int argc, char **argv) {
    int sockfd, new_sockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Validate arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse port number
    portno = atoi(argv[1]);

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags < 0) {
        perror("fcntl(F_GETFL)");
        exit(EXIT_FAILURE);
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("fcntl(F_SETFL)");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the port
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(sockfd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Initialize client address length
    clilen = sizeof(cli_addr);

    // Accept connections in a loop
    while (1) {
        // Accept a new connection
        new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        // Check for errors
        if (new_sockfd < 0) {
            if (errno == EAGAIN) {
                // No connections to accept, continue loop
                continue;
            } else {
                perror("accept");
                exit(EXIT_FAILURE);
            }
        }

        // Fork a child process to handle the connection
        pid_t child_pid = fork();
        if (child_pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            // Child process

            // Close the listening socket
            close(sockfd);

            // Read from the client
            bzero(buffer, sizeof(buffer));
            n = read(new_sockfd, buffer, sizeof(buffer));
            if (n < 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Process the request
            printf("Received: %s\n", buffer);

            // Write to the client
            n = write(new_sockfd, "Hello, world!\n", 13);
            if (n < 0) {
                perror("write");
                exit(EXIT_FAILURE);
            }

            // Close the client socket
            close(new_sockfd);

            // Exit the child process
            exit(EXIT_SUCCESS);
        } else {
            // Parent process

            // Close the client socket
            close(new_sockfd);
        }
    }

    // Close the listening socket
    close(sockfd);

    return 0;
}