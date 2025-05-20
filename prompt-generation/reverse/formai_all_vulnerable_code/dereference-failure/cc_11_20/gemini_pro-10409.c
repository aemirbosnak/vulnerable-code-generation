//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define DEFAULT_PORT_RANGE 1024
#define MAX_PORT_RANGE 65535

struct port_range {
    uint16_t start;
    uint16_t end;
};

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname/IP> <port range>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "Error resolving hostname: %s\n", hstrerror(h_errno));
        return EXIT_FAILURE;
    }

    struct port_range range;
    char *port_range_str = argv[2];
    char *dash = strchr(port_range_str, '-');
    if (!dash) {
        range.start = atoi(port_range_str);
        range.end = range.start;
    } else {
        *dash = '\0';
        range.start = atoi(port_range_str);
        range.end = atoi(dash + 1);
    }

    if (range.start < 1 || range.start > MAX_PORT_RANGE ||
        range.end < 1 || range.end > MAX_PORT_RANGE) {
        fprintf(stderr, "Invalid port range: %s\n", argv[2]);
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
    addr.sin_port = htons(range.start);
    addr.sin_addr = *((struct in_addr *) host->h_addr);

    for (uint16_t port = range.start; port <= range.end; port++) {
        addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d: Closed\n", port);
            } else {
                perror("connect");
            }
        } else {
            printf("Port %d: Open\n", port);
            close(sockfd);
            break;
        }
    }

    return EXIT_SUCCESS;
}