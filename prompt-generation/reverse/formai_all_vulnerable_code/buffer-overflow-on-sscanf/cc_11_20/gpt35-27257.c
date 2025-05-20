//FormAI DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define TIMEOUT 2 // timeout in seconds

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        printf("Example: %s 192.168.0.1 1-1024\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse IP address
    char* ip_addr_str = argv[1];
    struct in_addr ip_addr;
    if (inet_pton(AF_INET, ip_addr_str, &ip_addr) == 0) {
        printf("Invalid IP address: %s\n", ip_addr_str);
        exit(EXIT_FAILURE);
    }

    // Parse port range
    char* port_range_str = argv[2];
    int port_start, port_end;
    if (sscanf(port_range_str, "%d-%d", &port_start, &port_end) != 2) {
        printf("Invalid port range: %s\n", port_range_str);
        exit(EXIT_FAILURE);
    }
    if (port_start < 1 || port_start > 65535 || port_end < 1 || port_end > 65535) {
        printf("Port range must be between 1 and 65535\n");
        exit(EXIT_FAILURE);
    }
    if (port_start > port_end) {
        printf("Invalid port range: %s\n", port_range_str);
        exit(EXIT_FAILURE);
    }

    // Create TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Loop over port range
    printf("Scanning port range %d-%d...\n", port_start, port_end);
    printf("Port\tStatus\n");
    for (int port = port_start; port <= port_end; port++) {
        // Set up socket address
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr = ip_addr;
        memset(&(addr.sin_zero), '\0', 8);

        // Try to connect
        if (connect(sock, (struct sockaddr*) &addr, sizeof(addr)) == 0) {
            // Connection successful
            printf("%d\tOpen\n", port);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock == -1) {
                perror("socket");
                exit(EXIT_FAILURE);
            }
            if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
                perror("setsockopt");
                exit(EXIT_FAILURE);
            }
            if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) == -1) {
                perror("setsockopt");
                exit(EXIT_FAILURE);
            }
        } else {
            // Connection failed
            printf("%d\tClosed\n", port);
        }
    }

    close(sock);
    return 0;
}