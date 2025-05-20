//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define PORT_RANGE 1000
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip_addr = argv[1];
    char *port_range = argv[2];

    // Convert port range to integer
    int start_port = atoi(port_range);
    int end_port = start_port + PORT_RANGE;

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Set socket options
    int optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Create socket address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);
    server_addr.sin_port = htons(start_port);

    // Iterate over port range
    for (int port = start_port; port <= end_port; port++) {
        // Set port in socket address structure
        server_addr.sin_port = htons(port);

        // Connect to socket
        if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            printf("Port %d is closed\n", port);
            continue;
        }

        printf("Port %d is open\n", port);
    }

    // Close socket
    close(sock);

    return 0;
}