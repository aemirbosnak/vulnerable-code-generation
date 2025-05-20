//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define TIMEOUT 5000 // 5 seconds

// Function to check if a port is open
int check_port(int sock, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        close(sock);
        return 1; // Port is open
    } else if (errno == ECONNREFUSED) {
        close(sock);
        return 0; // Port is closed
    } else {
        close(sock);
        return -1; // Error
    }
}

// Function to scan a range of ports
void scan_ports(int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Scanning ports from %d to %d...\n", start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        int result = check_port(sock, port);

        if (result == 1) {
            printf("Port %d is open\n", port);
        } else if (result == 0) {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Start port cannot be greater than end port\n");
        exit(1);
    }

    if (start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range\n");
        exit(1);
    }

    scan_ports(start_port, end_port);

    return 0;
}