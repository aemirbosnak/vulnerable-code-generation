//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PORTS 65535

int scan_port(int sock, struct sockaddr_in *addr, int port) {
    int result;
    struct timeval timeout = { 1, 0 };

    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
    result = connect(sock, (struct sockaddr *)addr, sizeof(struct sockaddr_in));

    if (result == 0) {
        printf("Port %d is open\n", port);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Error on port %d: %s\n", port, strerror(errno));
    }

    return result;
}

int main() {
    int sock;
    struct sockaddr_in addr;
    int port = 1;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    while (port <= MAX_PORTS) {
        if (scan_port(sock, &addr, port)!= 0) {
            close(sock);
            exit(1);
        }
        port++;
    }

    close(sock);
    printf("Scan completed successfully!\n");
    return 0;
}