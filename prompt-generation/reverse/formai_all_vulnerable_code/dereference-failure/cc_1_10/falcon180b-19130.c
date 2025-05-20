//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535

void scan_ports(int target_ip, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = target_ip;

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            char buffer[1024];
            snprintf(buffer, sizeof(buffer), "Port %d is open\n", port);
            write(1, buffer, strlen(buffer));
        } else {
            if (errno == ECONNREFUSED) {
                char buffer[1024];
                snprintf(buffer, sizeof(buffer), "Port %d is closed\n", port);
                write(1, buffer, strlen(buffer));
            } else {
                char buffer[1024];
                snprintf(buffer, sizeof(buffer), "Error connecting to port %d: %s\n", port, strerror(errno));
                write(2, buffer, strlen(buffer));
            }
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <target_ip> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int target_ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (target_ip == INADDR_NONE) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        return 1;
    }

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        fprintf(stderr, "Invalid port range\n");
        return 1;
    }

    scan_ports(target_ip, start_port, end_port);

    return 0;
}