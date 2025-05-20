//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT_MIN 0
#define PORT_MAX 65535
#define IP_ADDR_LEN 16

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <start port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char ip_addr[IP_ADDR_LEN];
    int start_port;

    if (sscanf(argv[1], "%s", ip_addr) != 1) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (sscanf(argv[2], "%d", &start_port) != 1) {
        fprintf(stderr, "Invalid port number: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    if (start_port < PORT_MIN || start_port > PORT_MAX) {
        fprintf(stderr, "Invalid port number: %d\n", start_port);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(start_port);
    if (inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr) != 1) {
        fprintf(stderr, "Error converting IP address: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    for (int port = start_port; port <= PORT_MAX; port++) {
        serv_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
            printf("Port %d: Open\n", port);
        } else {
            if (errno == ECONNREFUSED) {
                printf("Port %d: Closed\n", port);
            } else {
                fprintf(stderr, "Error connecting to port %d: %s\n", port, strerror(errno));
            }
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}