//FormAI DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORT 65535
#define TIMEOUT 3

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <target-ip> <port-range>\n", argv[0]);
        printf("Example: %s 192.168.0.1 80-443\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target_ip = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    sscanf(port_range, "%d-%d", &start_port, &end_port);

    if (start_port < 0 || end_port > MAX_PORT) {
        printf("Invalid port range: %d-%d\n", start_port, end_port);
        exit(EXIT_FAILURE);
    }

    printf("Scanning %s:%d-%d...\n", target_ip, start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        struct sockaddr_in target_addr = {0};
        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(port);
        target_addr.sin_addr.s_addr = inet_addr(target_ip);

        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);

        struct timeval timeout = {0};
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open!\n", port);
        }

        close(sockfd);
    }

    printf("Scanning complete!\n");

    return 0;
}