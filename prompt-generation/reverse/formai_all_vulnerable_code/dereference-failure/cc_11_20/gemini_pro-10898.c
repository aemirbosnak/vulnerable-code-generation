//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netdb.h>

#define MAX_PORTS 1000
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check for valid arguments
    if (argc < 3) {
        printf("Usage: %s <target_ip> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Store arguments
    char *target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Check for valid port range
    if (start_port < 0 || start_port > 65535 || end_port < 0 || end_port > 65535 || start_port > end_port) {
        printf("Invalid port range\n");
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Get target IP address
    struct sockaddr_in target_addr;
    bzero(&target_addr, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(80);
    if (inet_aton(target_ip, &target_addr.sin_addr) == 0) {
        perror("inet_aton() failed");
        return EXIT_FAILURE;
    }

    // Connect to target IP address
    if (connect(sockfd, (struct sockaddr *) &target_addr, sizeof(target_addr)) < 0) {
        perror("connect() failed");
        return EXIT_FAILURE;
    }

    // Scan ports
    for (int port = start_port; port <= end_port; port++) {
        struct sockaddr_in addr;
        bzero(&addr, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        if (inet_aton(target_ip, &addr.sin_addr) == 0) {
            perror("inet_aton() failed");
            return EXIT_FAILURE;
        }

        int res = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));

        // Check if port is open
        if (res == 0) {
            printf("Port %d is open\n", port);
        }
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}