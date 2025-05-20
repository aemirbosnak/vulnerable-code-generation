//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PORTS 100

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port range>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2) {
        fprintf(stderr, "Invalid port range: %s\n", port_range);
        return EXIT_FAILURE;
    }

    if (start_port < 0 || start_port > 65535 || end_port < 0 || end_port > 65535) {
        fprintf(stderr, "Invalid port range: %s\n", port_range);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket()");
        return EXIT_FAILURE;
    }

    printf("Scanning ports %d-%d on %s\n", start_port, end_port, ip_address);

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}