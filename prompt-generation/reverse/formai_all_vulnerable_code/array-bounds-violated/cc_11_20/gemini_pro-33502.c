//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <poll.h>
#include <errno.h>

#define MAX_CONNECTIONS 10
#define BUF_SIZE 1024

int main() {
    int sockfd, clientfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char buf[BUF_SIZE];
    int ret;

    // Create a server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5555);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Create a pollfd array to monitor the server socket and client sockets
    struct pollfd fds[MAX_CONNECTIONS + 1];
    fds[0].fd = sockfd;
    fds[0].events = POLLIN;

    // Main loop
    while (1) {
        // Poll for incoming connections or data on existing connections
        int nfds = poll(fds, MAX_CONNECTIONS + 1, -1);
        if (nfds < 0) {
            perror("poll");
            return EXIT_FAILURE;
        }

        // Handle incoming connections
        if (fds[0].revents & POLLIN) {
            client_addr_len = sizeof(client_addr);
            clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
            if (clientfd < 0) {
                perror("accept");
                continue;
            }

            // Add the new client socket to the pollfd array
            fds[nfds].fd = clientfd;
            fds[nfds].events = POLLIN;
            nfds++;
        }

        // Handle data on existing connections
        for (int i = 1; i < nfds; i++) {
            if (fds[i].revents & POLLIN) {
                // Read data from the client socket
                ret = read(fds[i].fd, buf, BUF_SIZE);
                if (ret < 0) {
                    perror("read");
                    close(fds[i].fd);
                    fds[i] = fds[nfds - 1];
                    nfds--;
                } else if (ret == 0) {
                    // Client closed the connection
                    close(fds[i].fd);
                    fds[i] = fds[nfds - 1];
                    nfds--;
                } else {
                    // Print the data received from the client
                    printf("Received data from client: %s", buf);

                    // Write data back to the client
                    ret = write(fds[i].fd, buf, ret);
                    if (ret < 0) {
                        perror("write");
                        close(fds[i].fd);
                        fds[i] = fds[nfds - 1];
                        nfds--;
                    }
                }
            }
        }
    }

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}