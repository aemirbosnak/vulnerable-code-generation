//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define MAX_HOST_LEN 256

// Function to print usage information
void print_usage(char *progname) {
    fprintf(stderr, "Usage: %s <host> [port1,port2,...,portN]\n", progname);
    fprintf(stderr, "Example: %s example.com 22,80,443\n", progname);
}

// Function to scan a single port
int scan_port(char *host, int port) {
    int sockfd;
    struct sockaddr_in addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set up the socket address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return -1;
    }

    // Connect to the port
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        if (errno == ECONNREFUSED) {
            return 0;
        } else {
            perror("connect");
            close(sockfd);
            return -1;
        }
    }

    // Close the socket
    close(sockfd);

    return 1;
}

// Main function
int main(int argc, char **argv) {
    char *host;
    int ports[MAX_PORTS];
    int num_ports;
    int i, j, k;

    // Check for the correct number of arguments
    if (argc < 2) {
        print_usage(argv[0]);
        return -1;
    }

    // Get the host name
    host = argv[1];

    // Get the list of ports
    num_ports = 0;
    for (i = 2; i < argc; i++) {
        char *portstr = argv[i];
        int port;

        // Check if the port is valid
        if (sscanf(portstr, "%d", &port) != 1 || port < 0 || port > MAX_PORTS) {
            fprintf(stderr, "Invalid port: %s\n", portstr);
            continue;
        }

        // Add the port to the list
        ports[num_ports++] = port;
    }

    // Scan the ports
    for (i = 0; i < num_ports; i++) {
        int port = ports[i];
        int result = scan_port(host, port);

        // Print the results
        switch (result) {
            case 0:
                printf("Port %d is closed\n", port);
                break;
            case 1:
                printf("Port %d is open\n", port);
                break;
            case -1:
                fprintf(stderr, "Error scanning port %d\n", port);
                break;
        }
    }

    return 0;
}