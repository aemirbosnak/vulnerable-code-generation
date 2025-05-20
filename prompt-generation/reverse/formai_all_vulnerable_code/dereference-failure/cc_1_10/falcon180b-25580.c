//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PORT_NUMBER 65535 // Maximum number of ports
#define DEFAULT_PORT 80 // Default port to scan
#define BUFFER_SIZE 1024 // Size of buffer

// Function to scan a single port and return whether it is open or closed
int scan_port(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    int res = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (res == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }
        close(sock);
        return -1;
    } else {
        printf("Port %d is open\n", port);
        close(sock);
        return 0;
    }
}

// Function to scan all ports in the specified range
void scan_ports(int start_port, int end_port) {
    for (int i = start_port; i <= end_port; i++) {
        scan_port(i);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORT_NUMBER) {
        printf("Invalid port range\n");
        return 1;
    }

    scan_ports(start_port, end_port);

    return 0;
}