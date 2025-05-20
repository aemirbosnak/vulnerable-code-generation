//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Custom error handling macro
#define ERROR(msg) { fprintf(stderr, "%s\n", msg); exit(1); }

// Function to get the port number from the command line arguments
int get_port(char *arg) {
    int port;
    if (sscanf(arg, "%d", &port) != 1) {
        ERROR("Invalid port number");
    }
    return port;
}

// Function to scan a single port
int scan_port(char *ip_addr, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        ERROR("Failed to create socket");
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        ERROR("Failed to set socket options");
    }

    // Set the sockaddr_in structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr) != 1) {
        ERROR("Invalid IP address");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        return 0;
    }

    // Close the socket
    close(sockfd);

    // Return 1 if the port is open
    return 1;
}

// Function to scan a range of ports
void scan_ports(char *ip_addr, int start_port, int end_port) {
    for (int port = start_port; port <= end_port; port++) {
        if (scan_port(ip_addr, port)) {
            printf("%d open\n", port);
        } else {
            printf("%d closed\n", port);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 3 && argc != 5) {
        ERROR("Usage: ./port_scanner <ip_address> <start_port> <end_port>");
    }

    // Get the IP address
    char *ip_addr = argv[1];

    // Get the start and end ports
    int start_port, end_port;
    if (argc == 3) {
        start_port = get_port(argv[2]);
        end_port = start_port;
    } else {
        start_port = get_port(argv[2]);
        end_port = get_port(argv[4]);
    }

    // Scan the ports
    scan_ports(ip_addr, start_port, end_port);

    return 0;
}