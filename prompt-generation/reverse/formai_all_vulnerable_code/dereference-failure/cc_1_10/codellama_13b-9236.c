//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: detailed
/*
 * C Port Scanner Example Program
 *
 * This program is a simple port scanner that uses the `socket` and `connect`
 * functions to scan a given IP address and port range for open ports.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 100
#define MAX_ADDRESS_LEN 16

int main(int argc, char **argv) {
    // Check for valid arguments
    if (argc != 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    // Parse IP address and port range
    char *ip_address = argv[1];
    char *port_range = argv[2];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up address structure
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(port_range));
    inet_pton(AF_INET, ip_address, &address.sin_addr);

    // Set up port range
    int start_port = atoi(strtok(port_range, "-"));
    int end_port = atoi(strtok(NULL, "-"));

    // Loop through ports and scan for open ones
    for (int port = start_port; port <= end_port; port++) {
        address.sin_port = htons(port);

        // Connect to the port
        if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
            perror("connect");
            continue;
        }

        // Check if the port is open
        if (send(sock, "test", 4, 0) == -1) {
            perror("send");
            continue;
        }

        // Print open port
        printf("Port %d is open\n", port);
    }

    // Close the socket
    close(sock);

    return 0;
}