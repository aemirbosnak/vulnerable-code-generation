//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024

// Function to scan a single port
void scan_port(int sock, int port) {
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    dest.sin_addr.s_addr = htonl(INADDR_ANY);

    if (connect(sock, (struct sockaddr*)&dest, sizeof(dest)) == 0) {
        char buf[BUF_SIZE];
        snprintf(buf, BUF_SIZE, "Port %d is open.\n", port);
        write(1, buf, strlen(buf));
    } else if (errno == ECONNREFUSED) {
        char buf[BUF_SIZE];
        snprintf(buf, BUF_SIZE, "Port %d is closed.\n", port);
        write(1, buf, strlen(buf));
    } else {
        char buf[BUF_SIZE];
        snprintf(buf, BUF_SIZE, "Error connecting to port %d: %s\n", port, strerror(errno));
        write(2, buf, strlen(buf));
    }
}

// Function to scan a range of ports
void scan_range(int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        char buf[BUF_SIZE];
        snprintf(buf, BUF_SIZE, "Error creating socket: %s\n", strerror(errno));
        write(2, buf, strlen(buf));
        return;
    }

    for (int i = start_port; i <= end_port; i++) {
        scan_port(sock, i);
    }

    close(sock);
}

// Main function
int main(int argc, char** argv) {
    if (argc < 3) {
        char buf[BUF_SIZE];
        snprintf(buf, BUF_SIZE, "Usage: %s <start_port> <end_port>\n", argv[0]);
        write(2, buf, strlen(buf));
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        char buf[BUF_SIZE];
        snprintf(buf, BUF_SIZE, "Invalid port range.\n");
        write(2, buf, strlen(buf));
        return 1;
    }

    scan_range(start_port, end_port);

    return 0;
}