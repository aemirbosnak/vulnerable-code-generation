//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

int main(int argc, char *argv[]) {
    // Check for correct command line arguments
    if (argc!= 2) {
        printf("Usage: %s <target_ip>\n", argv[0]);
        return 1;
    }

    // Convert IP address to integers
    unsigned int ip_addr = inet_addr(argv[1]);
    unsigned int port = atoi(argv[2]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) < 0) {
        perror("Error setting socket option");
        return 1;
    }

    // Connect to server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = ip_addr;
    server_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Select function to handle multiple file descriptors
    fd_set read_fds, write_fds;
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);
    FD_SET(sockfd, &read_fds);
    FD_SET(sockfd, &write_fds);
    int max_fd = sockfd;

    // Loop until all ports are scanned
    while (1) {
        // Wait for file descriptor to become readable or writable
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        int ret = select(max_fd + 1, &read_fds, NULL, NULL, &timeout);
        if (ret == -1) {
            perror("Error selecting file descriptors");
            return 1;
        }

        // Check if socket is ready for reading
        if (FD_ISSET(sockfd, &read_fds)) {
            // Read from server
            char buffer[1024];
            int bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
            if (bytes_read <= 0) {
                perror("Error reading from server");
                return 1;
            }

            // Print server response
            printf("Server response: %s\n", buffer);

            // Close socket
            close(sockfd);
            break;
        }

        // Check if socket is ready for writing
        if (FD_ISSET(sockfd, &write_fds)) {
            // Send data to server
            send(sockfd, "Hello, server!\n", 14, 0);
            if (send(sockfd, "How are you?\n", 14, 0) <= 0) {
                perror("Error sending to server");
                return 1;
            }

            // Close socket
            close(sockfd);
            break;
        }
    }

    return 0;
}