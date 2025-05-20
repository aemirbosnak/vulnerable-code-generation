//FormAI DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd, i, start_port, end_port, count;
    struct sockaddr_in target;

    if (argc != 4) {
        printf("Usage: %s <ip> <starting port> <ending port>\n", argv[0]);
        return 1;
    }

    // Retrieve target IP address and port range from command line arguments
    char *ip_address = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // Validate port range
    if (start_port < 1 || start_port > 65535 || end_port < 1 || end_port > 65535 || start_port > end_port) {
        printf("Invalid port range specified.\n");
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket: %s\n", strerror(errno));
        return 1;
    }

    // Set target IP address and port range
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    // Perform port scan
    count = 0;
    for (i = start_port; i <= end_port; ++i) {
        target.sin_port = htons(i);

        if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open.\n", i);
            ++count;
        } else {
            printf("Port %d is closed.\n", i);
        }
    }

    // Report on number of open ports found
    if (count == 0) {
        printf("No open ports found.\n");
    } else {
        printf("%d open port(s) found.\n", count);
    }

    // Clean up and exit
    close(sockfd);
    return 0;
}