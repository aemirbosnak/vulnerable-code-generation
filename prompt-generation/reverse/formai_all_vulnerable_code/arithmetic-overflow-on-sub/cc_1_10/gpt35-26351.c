//FormAI DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, port, i;
    struct sockaddr_in servaddr;

    // Check for proper usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    char *ip_addr = argv[1];
    char *end;
    long int num_ip = strtol(ip_addr, &end, 10);

    if (num_ip == 0 && end == ip_addr) {
        fprintf(stderr, "Invalid IP address\n");
        return 1;
    } 

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip_addr);

    // Scan all ports between 1 and 65535
    for (port = 1; port <= 65535; port++) {

        // Set the port to scan
        servaddr.sin_port = htons(port);

        // Connect to the port
        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) {
            // If it connects, print it as an open port
            printf("Port %d: Open\n", port);

            // Close the socket
            close(sockfd);

            // Open a new socket
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}