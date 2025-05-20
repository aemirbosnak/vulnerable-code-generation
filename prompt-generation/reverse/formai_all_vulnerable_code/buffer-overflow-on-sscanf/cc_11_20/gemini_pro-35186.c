//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <target IP> <port range>\n", argv[0]);
        return 1;
    }

    char *target_ip = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2) {
        printf("Invalid port range: %s\n", port_range);
        return 1;
    }

    if (start_port < 0 || start_port > 65535 || end_port < 0 || end_port > 65535 || start_port > end_port) {
        printf("Invalid port range: %s\n", port_range);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(start_port);
    if (inet_pton(AF_INET, target_ip, &target_addr.sin_addr) != 1) {
        printf("Invalid target IP: %s\n", target_ip);
        return 1;
    }

    printf("Scanning ports %d-%d on %s...\n", start_port, end_port, target_ip);
    for (int port = start_port; port <= end_port; port++) {
        target_addr.sin_port = htons(port);
        int ret = connect(sockfd, (struct sockaddr *) &target_addr, sizeof(target_addr));
        if (ret == 0) {
            printf("Port %d is open.\n", port);
        }
    }

    close(sockfd);
    return 0;
}