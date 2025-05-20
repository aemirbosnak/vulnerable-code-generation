//FormAI DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define CONN_TIMEOUT 3

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("usage: %s <ip> <port_range>\n", argv[0]);
        exit(1);
    }

    // Parse IP address and port range
    char *ip_str = argv[1];
    char *port_range_str = argv[2];
    char *start_str = strtok(port_range_str, "-");
    char *end_str = strtok(NULL, "-");

    if (!start_str || !end_str) {
        printf("invalid port range\n");
        exit(1);
    }

    int start = atoi(start_str);
    int end = atoi(end_str);
    if (start <= 0 || start > 65535 || end <= 0 || end > 65535 || start > end) {
        printf("invalid port range\n");
        exit(1);
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set timeout for connect()
    struct timeval tv;
    tv.tv_sec = CONN_TIMEOUT;
    tv.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt");
        exit(1);
    }
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // Connect to IP addresses and port numbers in the given range
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_str);
    for (int port = start; port <= end; port++) {
        addr.sin_port = htons(port);
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            // Connection failed
            printf("port %d: closed\n", port);
        } else {
            // Connection succeeded
            printf("port %d: open\n", port);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (sock < 0) {
                perror("socket");
                exit(1);
            }
            if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
                perror("setsockopt");
                exit(1);
            }
            if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv)) < 0) {
                perror("setsockopt");
                exit(1);
            }
        }
    }

    // Close socket
    close(sock);

    return 0;
}