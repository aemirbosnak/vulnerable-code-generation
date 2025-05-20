//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to check if a port is open
int is_port_open(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        return 0; // Socket creation failed
    }

    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        close(sock);
        return 0; // Connection failed, port is closed
    }

    // Port is open
    close(sock);
    return 1;
}

// Function to display scanning progress
void display_scanning_progress(int current, int total) {
    int progress = (current * 100) / total;
    printf("\rScanning Progress: [");

    for (int i = 0; i < 50; i++) {
        if (i < progress / 2) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%", progress);
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <PORT_RANGE>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip = argv[1];
    char *endptr;
    int start_port = strtol(argv[2], &endptr, 10);
    int end_port = strtol(endptr, NULL, 10);
    
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Error: Invalid port range.\n");
        exit(EXIT_FAILURE);
    }

    printf("Starting the port scan on %s from port %d to %d...\n", ip, start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        display_scanning_progress(port - start_port + 1, end_port - start_port + 1);
        int open = is_port_open(ip, port);
        if (open) {
            printf("\nPort %d is OPEN", port);
        } else {
            printf("\nPort %d is CLOSED", port);
        }
    }
    
    printf("\nScanning completed!\n");
    return 0;
}