//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>

#define MAX_PORT 65535
#define MIN_PORT 1

void scanPort(const char *hostname, int port);
void displayPortStatus(int port, int isOpen);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <start-port-end-port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int startPort, endPort;

    // Parse the port range from the input
    if (sscanf(argv[2], "%d-%d", &startPort, &endPort) != 2 || startPort < MIN_PORT || endPort > MAX_PORT || startPort > endPort) {
        printf("Please provide a valid port range (1-65535) in the format: start-port-end-port\n");
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = 0; // initial, will set dynamically
    inet_pton(AF_INET, hostname, &server.sin_addr);

    printf("Scanning ports from %d to %d on host %s...\n", startPort, endPort, hostname);
    for (int port = startPort; port <= endPort; port++) {
        scanPort(hostname, port);
        usleep(100000); // Sleep for 0.1 seconds between each scan for a calm flow
    }

    printf("Port scanning completed. Peace be upon your connections.\n");
    return 0;
}

void scanPort(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server.sin_addr);

    // Set a timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = 1;  // 1 second timeout
    timeout.tv_usec = 0;

    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
    
    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result >= 0) {
        displayPortStatus(port, 1); // Port is open
    } else {
        displayPortStatus(port, 0); // Port is closed
    }

    close(sock); // Close the socket gracefully
}

void displayPortStatus(int port, int isOpen) {
    if (isOpen) {
        printf("Port %d is OPEN.\n", port);
    } else {
        printf("Port %d is CLOSED.\n", port);
    }
}