//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
/*
 * Port Scanner - Single-Threaded Version
 *
 * This program is a simple port scanner that scans a given IP address
 * and reports which ports are open and which are closed.
 *
 * Usage: port_scan <ip_address> <start_port> <end_port>
 *
 * Example: port_scan 192.168.0.1 1 1000
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 1000

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Check if the port range is valid
    if (start_port < 1 || end_port > MAX_PORTS) {
        fprintf(stderr, "Invalid port range: %d-%d\n", start_port, end_port);
        return 1;
    }

    // Initialize socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set socket options
    int enable = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Initialize socket address structure
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(start_port);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // Scan ports
    for (int i = start_port; i <= end_port; i++) {
        // Set port number
        addr.sin_port = htons(i);

        // Connect to port
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            if (errno == ECONNREFUSED) {
                // Port is closed
                printf("Port %d is closed.\n", i);
            } else {
                // Error
                perror("connect");
                return 1;
            }
        } else {
            // Port is open
            printf("Port %d is open.\n", i);
        }
    }

    // Close socket
    close(sock);

    return 0;
}