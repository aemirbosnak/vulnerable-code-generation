//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_TRIES 5

int main(int argc, char *argv[]) {
    int sock, i, j, port;
    struct sockaddr_in server;
    struct timeval tv;
    fd_set fds;
    char *host;

    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    host = argv[1];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = 0;
    server.sin_addr.s_addr = inet_addr(host);

    for (port = 1; port <= PORT_RANGE; port++) {
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
            continue;
        }

        printf("Port %d is open\n", port);

        tv.tv_sec = 3;
        tv.tv_usec = 0;
        FD_ZERO(&fds);
        FD_SET(sock, &fds);

        if (select(sock + 1, NULL, &fds, NULL, &tv) > 0) {
            printf("Port %d is filtered\n", port);
        }

        close(sock);
    }

    return 0;
}