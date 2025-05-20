//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

// Constants
#define PORT_MIN 1
#define PORT_MAX 65535
#define BUFFER_SIZE 1024

// Function to scan a single port
int scan_port(const char *ip, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set up the socket address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the port
    int ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        close(sockfd);
        return -1;
    }

    // Read from the port
    char buffer[BUFFER_SIZE];
    int bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        close(sockfd);
        return -1;
    }

    // Print the port status
    printf("Port %d: %s\n", port, bytes_read > 0 ? "open" : "closed");

    // Close the socket
    close(sockfd);

    return 0;
}

// Function to scan a range of ports
int scan_ports(const char *ip, int port_min, int port_max) {
    for (int port = port_min; port <= port_max; port++) {
        scan_port(ip, port);
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port range>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the IP address and port range
    const char *ip = argv[1];
    int port_min, port_max;
    if (sscanf(argv[2], "%d-%d", &port_min, &port_max) != 2) {
        fprintf(stderr, "Invalid port range: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Check that the port range is valid
    if (port_min < PORT_MIN || port_min > PORT_MAX || port_max < PORT_MIN || port_max > PORT_MAX) {
        fprintf(stderr, "Invalid port range: %d-%d\n", port_min, port_max);
        return EXIT_FAILURE;
    }

    // Scan the ports
    scan_ports(ip, port_min, port_max);

    return EXIT_SUCCESS;
}