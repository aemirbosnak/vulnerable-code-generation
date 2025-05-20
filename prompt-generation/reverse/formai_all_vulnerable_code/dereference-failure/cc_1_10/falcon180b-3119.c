//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535

void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", program_name);
    exit(1);
}

void scan_ports(char *hostname, int start_port, int end_port) {
    int sockfd, port;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);
    char buffer[1024];

    for (port = start_port; port <= end_port; port++) {
        if (port == 25) {
            printf("Port %d: SMTP\n", port);
        } else if (port == 80) {
            printf("Port %d: HTTP\n", port);
        } else if (port == 443) {
            printf("Port %d: HTTPS\n", port);
        } else {
            printf("Port %d: Unknown\n", port);
        }

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, hostname, &server_addr.sin_addr);

        if (connect(sockfd, (struct sockaddr *)&server_addr, addrlen) == 0) {
            close(sockfd);
            printf("Port %d: Open\n", port);
        } else {
            close(sockfd);
            printf("Port %d: Closed\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    scan_ports(hostname, start_port, end_port);

    return 0;
}