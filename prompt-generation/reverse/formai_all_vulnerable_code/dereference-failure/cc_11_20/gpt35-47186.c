//FormAI DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int minPort = 0, maxPort = 0;

    // Check if arguments are provided
    if (argc < 3) {
        printf("Usage: %s <ip address> <min port> <max port>\n", argv[0]);
        return 1;
    }

    // Validate IP address
    struct sockaddr_in targetAddress;
    if (inet_pton(AF_INET, argv[1], &(targetAddress.sin_addr)) == 0) {
        printf("Invalid IP address\n");
        return 1;
    }

    // Validate min and max port values
    minPort = atoi(argv[2]);
    maxPort = atoi(argv[3]);
    if (minPort < 0 || minPort > 65535 || maxPort < 0 || maxPort > 65535 || maxPort < minPort) {
        printf("Invalid port range\n");
        return 1;
    }

    // Start scanning ports
    for (int port = minPort; port <= maxPort; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Error creating socket\n");
            return 1;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr = targetAddress.sin_addr;

        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
            // Port is closed
            close(sock);
            continue;
        } else {
            // Port is open
            printf("Port %d is open\n", port);
        }

        close(sock);
    }

    return 0;
}