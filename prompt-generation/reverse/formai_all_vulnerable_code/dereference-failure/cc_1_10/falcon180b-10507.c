//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

// Function to print error message and exit program
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to print usage instructions
void usage() {
    printf("Usage:./program <IP_Address>\n");
}

// Function to scan for open ports on a given IP address
void scan_ports(char *ip_address) {
    int sock;
    struct sockaddr_in server;
    int port;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket failed");
    }

    // Set server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server.sin_addr);

    // Loop through each port
    for (port = 1; port <= 65535; port++) {
        // Connect to port
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open.\n", port);
        } else if (errno == ECONNREFUSED) {
            // Port is closed
        } else {
            error("connect failed");
        }

        // Close socket
        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        usage();
        return 1;
    }

    // Scan for open ports
    scan_ports(argv[1]);

    return 0;
}