//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void fatal(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int is_valid_port(int port) {
    if (port <= 0 || port > 65535) {
        return 0;
    }
    return 1;
}

int connect_to_port(const char* host, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fatal("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        fatal("inet_pton");
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        close(sockfd);
        return -1;
    }

    return sockfd;
}

void scan_ports(const char* host, int start_port, int end_port) {
    for (int port = start_port; port <= end_port; port++) {
        if (!is_valid_port(port)) {
            continue;
        }

        int sockfd = connect_to_port(host, port);
        if (sockfd!= -1) {
            char buffer[BUFFER_SIZE];
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received > 0) {
                printf("Port %d is open.\n", port);
                close(sockfd);
            } else {
                fatal("recv");
            }
        } else {
            printf("Port %d is closed.\n", port);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    const char* host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    scan_ports(host, start_port, end_port);

    return 0;
}