//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define MAX_TRIES 3

int scan_port(const char *address, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, address, &server.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed.\n", port);
        } else {
            perror("connect");
        }
        return 1;
    }

    printf("Port %d is open.\n", port);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <address> <port_range>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    if (start_port > end_port) {
        fprintf(stderr, "Invalid port range.\n");
        return 1;
    }

    for (int i = start_port; i <= end_port; i++) {
        if (scan_port(argv[1], i) != 0) {
            break;
        }
    }

    return 0;
}