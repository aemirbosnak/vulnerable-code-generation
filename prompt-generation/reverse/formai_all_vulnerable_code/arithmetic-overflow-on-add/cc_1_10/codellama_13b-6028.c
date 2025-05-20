//Code Llama-13B DATASET v1.0 Category: Smart home automation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <time.h>

#define PORT 8080
#define BUFLEN 512
#define TIMEOUT 2

int main() {
    int sockfd, new_fd;
    struct sockaddr_in my_addr, their_addr;
    socklen_t sin_size;
    char buffer[BUFLEN];
    int bytes_recv;
    fd_set readfds;
    struct timeval tv;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the address information
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero), 8);

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Initialize the set of file descriptors
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        // Set the timeout
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        // Select the file descriptor
        if (select(sockfd + 1, &readfds, NULL, NULL, &tv) == -1) {
            perror("select");
            exit(1);
        }

        // Check if there is an incoming connection
        if (FD_ISSET(sockfd, &readfds)) {
            new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
            if (new_fd == -1) {
                perror("accept");
                exit(1);
            }

            // Print the address of the incoming connection
            printf("New connection from %s\n", inet_ntoa(their_addr.sin_addr));

            // Read the data from the incoming connection
            bytes_recv = recv(new_fd, buffer, BUFLEN, 0);
            if (bytes_recv == -1) {
                perror("recv");
                exit(1);
            }

            // Print the received data
            printf("Received: %s\n", buffer);

            // Close the incoming connection
            if (close(new_fd) == -1) {
                perror("close");
                exit(1);
            }
        }
    }

    return 0;
}