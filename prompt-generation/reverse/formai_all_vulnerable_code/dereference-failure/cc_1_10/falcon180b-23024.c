//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port, opt = 1;
    struct sockaddr_in sin;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port range>\n", argv[0]);
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        return 1;
    }

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &sin.sin_addr) <= 0) {
        printf("Invalid hostname or IP address\n");
        return 1;
    }

    for (port = 1; port <= MAX_PORTS; port++) {
        sin.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }
    }

    close(sock);
    return 0;
}