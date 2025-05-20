//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_PORT_NUM 65535

// Structure representing a port scan result
typedef struct {
    bool open;
    uint16_t port;
} PortScanResult;

// Function to scan a single port
PortScanResult scan_port(const char *host, uint16_t port) {
    int sockfd;
    struct sockaddr_in servaddr;
    
    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        exit(EXIT_FAILURE);
    }
    
    // Try to connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == 0) {
        printf("Port %hu is open on host %s\n", port, host);
        return (PortScanResult) { .open = true, .port = port };
    } else {
        return (PortScanResult) { .open = false, .port = port };
    }
    
    // Close the socket
    close(sockfd);
}

// Function to scan a range of ports on a host
void scan_ports(const char *host, uint16_t start_port, uint16_t end_port) {
    for (uint16_t port = start_port; port <= end_port; port++) {
        PortScanResult result = scan_port(host, port);
        if (result.open) {
            printf("Port %hu is open on host %s\n", result.port, host);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s host port_range\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *host = argv[1];
    char *port_range = argv[2];
    
    uint16_t start_port, end_port;
    if (sscanf(port_range, "%hu-%hu", &start_port, &end_port) != 2) {
        fprintf(stderr, "Invalid port range: %s\n", port_range);
        return EXIT_FAILURE;
    }
    
    if (start_port > end_port) {
        fprintf(stderr, "Invalid port range: start port must be less than or equal to end port\n");
        return EXIT_FAILURE;
    }
    
    if (start_port < 0 || start_port > MAX_PORT_NUM || end_port < 0 || end_port > MAX_PORT_NUM) {
        fprintf(stderr, "Invalid port range: port numbers must be between 0 and %hu\n", MAX_PORT_NUM);
        return EXIT_FAILURE;
    }
    
    scan_ports(host, start_port, end_port);
    
    return EXIT_SUCCESS;
}