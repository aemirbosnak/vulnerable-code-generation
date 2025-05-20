//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: portable
/*
 * Port scanner example program
 *
 * Usage:
 *      port_scanner [hostname] [port range]
 *
 * Example:
 *      port_scanner google.com 80
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc < 3) {
        printf("Usage: %s [hostname] [port range]\n", argv[0]);
        return 1;
    }

    // Get hostname and port range from command-line arguments
    char *hostname = argv[1];
    int port_start = atoi(argv[2]);
    int port_end = atoi(argv[3]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Set up socket address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port_start);
    if (inet_pton(AF_INET, hostname, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Iterate over port range
    for (int port = port_start; port <= port_end; port++) {
        // Set port number in socket address structure
        addr.sin_port = htons(port);

        // Connect to host
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
        }
    }

    // Close socket
    close(sock);

    return 0;
}