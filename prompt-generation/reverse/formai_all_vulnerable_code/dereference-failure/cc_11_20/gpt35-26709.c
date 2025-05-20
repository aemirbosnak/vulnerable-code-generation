//FormAI DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_PORTS 1024
#define TIMEOUT 5

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 3) {
        printf("Usage: %s <IP ADDRESS> [<START PORT>]\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = 1;

    if (argc == 3) {
        start_port = atoi(argv[2]);
        if (start_port < 1 || start_port > MAX_PORTS) {
            printf("Invalid start port number: %d (should be between 1 and %d)\n", start_port, MAX_PORTS);
            return 1;
        }
    }

    printf("Scanning %s ports %d-%d...\n", ip_address, start_port, MAX_PORTS);

    int sock;
    struct sockaddr_in target;

    // Create a socket for connecting to the target IP address
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the target
    if (connect(sock, (struct sockaddr*)&target, sizeof(target)) == 0) {
        printf("Target is online\n");
        close(sock);
        return 0;
    }

    // Scan the ports
    int port;
    for (port = start_port; port <= MAX_PORTS; port++) {

        // Create a new socket for each port
        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sock < 0) {
            printf("Error creating socket: %s\n", strerror(errno));
            continue;
        }

        // Set the socket options to timeout after a given period
        struct timeval timeout;
        memset(&timeout, 0, sizeof(timeout));
        timeout.tv_sec = TIMEOUT;
        if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
            printf("Error setting socket options: %s\n", strerror(errno));
            close(sock);
            continue;
        }

        // Set the target IP and port number
        target.sin_port = htons(port);

        // Connect to the target
        if (connect(sock, (struct sockaddr*)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", port);
        }

        close(sock);
    }

    printf("Scan complete\n");

    return 0;
}