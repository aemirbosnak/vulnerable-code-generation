//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define BUFFER_SIZE 1024

void scan_port(const char *ip_address, int port) {
    int sock;
    struct sockaddr_in server;
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }
    
    // Setting timeout for socket
    struct timeval timeout;
    timeout.tv_sec = 1; // 1 second timeout
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
    
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip_address);
    
    // Attempt to connect
    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
        printf("Port %d is OPEN\n", port);
    } else if (result < 0 && errno == EINPROGRESS) {
        printf("Port %d is OPEN (connection in progress)\n", port);
    } else {
        printf("Port %d is CLOSED\n", port);
    }
    
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Range>\n", argv[0]);
        fprintf(stderr, "Example: %s 127.0.0.1 1-100\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    char *port_range = argv[2];
    int start_port, end_port;

    // Parse input port range
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2 || 
        start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Must be between %d and %d.\n", MIN_PORT, MAX_PORT);
        return EXIT_FAILURE;
    }

    printf("Scanning IP: %s from port %d to %d...\n", ip_address, start_port, end_port);
    time_t start_time = time(NULL);

    // Scan each port in the specified range
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }

    time_t end_time = time(NULL);
    printf("Scan completed in %ld seconds.\n", end_time - start_time);
    
    return EXIT_SUCCESS;
}