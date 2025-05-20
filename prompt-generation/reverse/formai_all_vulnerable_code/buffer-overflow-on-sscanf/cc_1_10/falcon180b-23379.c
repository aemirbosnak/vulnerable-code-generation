//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/select.h>

#define MAX_PORTS 65535
#define TIMEOUT 5000 // 5 seconds

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port)!= 2) {
        printf("Invalid port range\n");
        return 1;
    }

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    int max_fd;
    fd_set master_fds, read_fds;
    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    for (int i = start_port; i <= end_port; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("socket");
            return 1;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(i);
        inet_pton(AF_INET, ip, &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("%d - Closed\n", i);
            } else if (errno == ETIMEDOUT) {
                printf("%d - Timed out\n", i);
            } else {
                perror("connect");
            }
            close(sock);
            continue;
        }

        printf("%d - Open\n", i);
        close(sock);
    }

    return 0;
}