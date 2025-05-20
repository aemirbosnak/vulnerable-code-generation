//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535

void print_usage(char *progname) {
    fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", progname);
    exit(1);
}

int is_valid_port(int port) {
    if (port <= 0 || port > 65535) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (!is_valid_port(start_port) ||!is_valid_port(end_port)) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(start_port);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid hostname\n");
        exit(1);
    }

    for (int port = start_port; port <= end_port; port++) {
        if (!is_valid_port(port)) {
            continue;
        }

        serv_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", port);
            } else if (errno == ETIMEDOUT) {
                printf("Port %d is filtered/dropped\n", port);
            } else {
                perror("connect");
            }
        } else {
            printf("Port %d is open\n", port);
            close(sock);
            break;
        }
    }

    return 0;
}