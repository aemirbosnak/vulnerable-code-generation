//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 1000

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 0 || start_port > 65535 || end_port < 0 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range\n");
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(start_port);
    if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid host address\n");
        return EXIT_FAILURE;
    }

    int num_open_ports = 0;
    for (int port = start_port; port <= end_port; port++) {
        addr.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
            num_open_ports++;
        }
    }

    close(sockfd);

    printf("Found %d open ports\n", num_open_ports);

    return EXIT_SUCCESS;
}