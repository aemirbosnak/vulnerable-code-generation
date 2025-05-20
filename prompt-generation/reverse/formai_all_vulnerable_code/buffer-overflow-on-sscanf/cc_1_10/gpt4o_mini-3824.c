//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define TIMEOUT 1
#define MAX_PORT 65535
#define MIN_PORT 1
#define BUFFER_SIZE 1024

void scan_port(const char *ip_address, int port) {
    int sock;
    struct sockaddr_in server;

    // Creating a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Setting the timeout for the socket
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    // Configuring the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    
    if (inet_pton(AF_INET, ip_address, &server.sin_addr) <= 0) {
        perror("Invalid IP address");
        close(sock);
        return;
    }

    // Attempting to connect to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d: OPEN\n", port);
    } else {
        printf("Port %d: CLOSED\n", port);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <PORT_RANGE>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int start_port, end_port;
    
    // Parsing the port range argument
    if (sscanf(argv[2], "%d-%d", &start_port, &end_port) != 2 ||
        start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Use format: <start_port>-<end_port> (1-65535)\n");
        exit(EXIT_FAILURE);
    }

    printf("Scanning IP: %s\n", ip_address);
    
    // Looping through the specified port range
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }

    printf("Port scan completed.\n");
    return 0;
}