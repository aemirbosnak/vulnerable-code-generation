//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TIMEOUT 1

int scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set timeout
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    
    // Setup server struct
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        close(sock);
        return 1; // Port is open
    } else {
        close(sock);
        if (errno == EINPROGRESS) {
            return 0; // Port is filtered
        }
        return -1; // Port is closed
    }
}

void print_port_status(int port, int status) {
    switch (status) {
        case 1:
            printf("Port %d: Open\n", port);
            break;
        case 0:
            printf("Port %d: Filtered\n", port);
            break;
        case -1:
            printf("Port %d: Closed\n", port);
            break;
        default:
            printf("Port %d: Unknown status\n", port);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <port_range>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    int start_port, end_port;

    // Parse port range from argument
    if (sscanf(argv[2], "%d-%d", &start_port, &end_port) != 2 ||
        start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Please specify like 20-80.\n");
        return EXIT_FAILURE;
    }

    printf("Scanning ports from %d to %d on IP %s...\n", start_port, end_port, ip);
    for (int port = start_port; port <= end_port; port++) {
        int result = scan_port(ip, port);
        print_port_status(port, result);
    }

    return EXIT_SUCCESS;
}