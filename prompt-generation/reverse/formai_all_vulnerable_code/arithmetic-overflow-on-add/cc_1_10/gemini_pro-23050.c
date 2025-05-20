//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

// Grateful Port Scanner

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        return 1;
    }

    // Convert IP address to binary
    struct in_addr ip_addr;
    if (inet_aton(argv[1], &ip_addr) == 0) {
        printf("Invalid IP address\n");
        return 1;
    }

    // Convert port range to start and end ports
    int port_start, port_end;
    if (sscanf(argv[2], "%d-%d", &port_start, &port_end) != 2) {
        printf("Invalid port range\n");
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("Setsockopt failed");
        close(sockfd);
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = ip_addr;
    for (int port = port_start; port <= port_end; port++) {
        server_addr.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port);
        }
        else {
            printf("Port %d is closed\n", port);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}