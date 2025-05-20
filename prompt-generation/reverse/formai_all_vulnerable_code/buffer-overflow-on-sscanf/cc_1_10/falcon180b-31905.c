//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port_range>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    char *port_range = argv[2];

    int min_port, max_port;
    if (sscanf(port_range, "%d-%d", &min_port, &max_port)!= 2) {
        die("Invalid port range");
    }

    if (min_port > max_port) {
        die("Invalid port range");
    }

    for (int port = min_port; port <= max_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            die("socket");
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
            die("inet_pton");
        }

        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
            close(sock);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error on port %d: %s\n", port, strerror(errno));
        }
    }

    return 0;
}