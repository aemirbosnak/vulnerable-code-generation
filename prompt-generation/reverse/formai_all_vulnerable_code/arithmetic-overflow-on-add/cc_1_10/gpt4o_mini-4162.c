//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

// Function to scan a single port
int scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set up the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    // Set a timeout for the connection
    struct timeval timeout;
    timeout.tv_sec = 1; // 1 second timeout
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    // Attempt to connect
    int result = connect(sock, (struct sockaddr*)&server, sizeof(server));
    if (result == 0) {
        close(sock);
        return 1; // Port is open
    } else if (errno == EINPROGRESS) {
        // Connection in progress, take it as open for this scan (you might want to test it)
        close(sock);
        return 1; // Port may be open
    }

    close(sock);
    return 0; // Port is closed
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <start_port-end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip = argv[1];
    int start_port, end_port;
    
    // Extract port range from the input
    if (sscanf(argv[2], "%d-%d", &start_port, &end_port) != 2) {
        fprintf(stderr, "Invalid port range format. Use start_port-end_port\n");
        exit(EXIT_FAILURE);
    }

    // Alerts the user about the scanning process
    printf("Scanning IP: %s\n", ip);
    printf("Scanning ports from %d to %d...\n", start_port, end_port);

    // Iterate through the port range and scan each one
    for (int port = start_port; port <= end_port; port++) {
        printf("Scanning port %d... ", port);
        int result = scan_port(ip, port);
        if (result == 1) {
            printf("Open\n");
        } else {
            printf("Closed\n");
        }
    }

    printf("Scanning complete.\n");
    return 0;
}