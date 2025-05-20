//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip_address> <start_port> [end_port]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = argc >= 4 ? atoi(argv[3]) : MAX_PORTS;

    if (start_port < 0 || start_port > 65535 || end_port < 0 || end_port > 65535) {
        fprintf(stderr, "Invalid port range specified\n");
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        return EXIT_FAILURE;
    }

    for (int port = start_port; port <= end_port; port++) {
        addr.sin_port = htons(port);
        int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        if (result == 0) {
            printf("Port %d is open\n", port);
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}