//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    // Convert IP address from string to binary format
    char *ip_address = argv[1];
    unsigned long ip = inet_addr(ip_address);
    if (ip == INADDR_NONE) {
        printf("Invalid IP address\n");
        exit(1);
    }

    // Convert port range from string to integers
    char *port_range = argv[2];
    int start_port, end_port;
    sscanf(port_range, "%d-%d", &start_port, &end_port);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set socket options
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Loop through all ports in the specified range
    for (int port = start_port; port <= end_port; port++) {
        // Create socket address structure
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = ip;

        // Connect to the port
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }
    }

    // Close socket
    close(sock);

    return 0;
}