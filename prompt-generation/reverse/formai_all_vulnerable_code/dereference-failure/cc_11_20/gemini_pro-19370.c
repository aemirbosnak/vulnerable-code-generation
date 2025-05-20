//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT_MIN 1
#define PORT_MAX 65535

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <Port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the IP address and port number from the command line.
    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Validate the IP address.
    if (!inet_aton(ip_address, NULL)) {
        fprintf(stderr, "Invalid IP address: %s\n", ip_address);
        return EXIT_FAILURE;
    }

    // Validate the port number.
    if (port_number < PORT_MIN || port_number > PORT_MAX) {
        fprintf(stderr, "Invalid port number: %d\n", port_number);
        return EXIT_FAILURE;
    }

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket to non-blocking mode.
    int flags = fcntl(sockfd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        close(sockfd);
        return EXIT_FAILURE;
    }
    flags |= O_NONBLOCK;
    if (fcntl(sockfd, F_SETFL, flags) == -1) {
        perror("fcntl");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Connect to the server.
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    if (inet_pton(AF_INET, ip_address, &server_address.sin_addr) == -1) {
        perror("inet_pton");
        close(sockfd);
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        if (errno != EINPROGRESS) {
            perror("connect");
            close(sockfd);
            return EXIT_FAILURE;
        }
    }

    // Wait for the connection to complete.
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    fd_set write_fds;
    FD_ZERO(&write_fds);
    FD_SET(sockfd, &write_fds);
    int select_result = select(sockfd + 1, NULL, &write_fds, NULL, &timeout);
    if (select_result == -1) {
        perror("select");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Check if the connection succeeded.
    int error;
    socklen_t error_length = sizeof(error);
    if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &error_length) == -1) {
        perror("getsockopt");
        close(sockfd);
        return EXIT_FAILURE;
    }
    if (error != 0) {
        errno = error;
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Print the port number.
    printf("Port %d is open\n", port_number);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}