//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <time.h>

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket\n");
        return;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    // Set timeout for the scan
    struct timeval timeout;
    timeout.tv_sec = 1; // 1 second timeout
    timeout.tv_usec = 0;

    // Apply timeout to socket
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
    
    // Attempt to connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    char *port_range = argv[2];
    int start_port, end_port;
    
    // Parse port range input
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2) {
        printf("Invalid port range format. Use <start>-<end>\n");
        return 1;
    }

    printf("\nStarting the port scan on %s from %d to %d...\n\n", ip, start_port, end_port);
    time_t start_time = time(NULL);

    // Loop through the port range and scan each port
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
        // Adding a short delay so that we don't flood the network
        usleep(50000); // Sleep for 50ms
    }

    time_t end_time = time(NULL);
    printf("\nPort scan completed in %ld seconds.\n", end_time - start_time);
    return 0;
}