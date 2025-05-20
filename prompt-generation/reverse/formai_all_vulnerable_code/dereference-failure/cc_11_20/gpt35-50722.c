//FormAI DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define TIMEOUT_SEC 1
#define MAX_PORTS 65535

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s host [port]\n", argv[0]);
        return 1;
    }

    const char* host = argv[1];
    int start_port = 1;
    int end_port = MAX_PORTS;

    if (argc > 2) {
        if (isdigit(argv[2][0])) {
            start_port = end_port = atoi(argv[2]);
        } else {
            fprintf(stderr, "Error: Invalid port number\n");
            return 1;
        }
    }

    if (argc > 3) {
        if (isdigit(argv[2][0]) && isdigit(argv[3][0])) {
            start_port = atoi(argv[2]);
            end_port = atoi(argv[3]);
            if (start_port < 1 || end_port > MAX_PORTS || start_port > end_port) {
                fprintf(stderr, "Error: Invalid port range\n");
                return 1;
            }
        } else {
            fprintf(stderr, "Error: Invalid port number\n");
            return 1;
        }
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host);

    if (addr.sin_addr.s_addr == 0xffffffff || addr.sin_addr.s_addr == 0) {
        fprintf(stderr, "Error: Invalid address\n");
        return 1;
    }

    printf("Scanning %s (%s)\n", host, inet_ntoa(addr.sin_addr));

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error: Failed to create socket");
        return 1;
    }

    fd_set fdset;
    struct timeval timeout;
    struct sockaddr_in sa;
    int i, j, ret;

    for (i = start_port; i <= end_port; i++) {
        memset(&sa, 0, sizeof(sa));
        sa.sin_family = AF_INET;
        sa.sin_addr.s_addr = inet_addr(host);
        sa.sin_port = htons(i);

        ret = connect(socket_fd, (struct sockaddr*)&sa, sizeof(sa));
        if (ret == -1 && errno != EINPROGRESS) {
            continue;
        }

        timeout.tv_sec = TIMEOUT_SEC;
        timeout.tv_usec = 0;

        FD_ZERO(&fdset);
        FD_SET(socket_fd, &fdset);

        ret = select(socket_fd+1, NULL, &fdset, NULL, &timeout);
        if (ret == 1) {
            int err;
            socklen_t len = sizeof(err);
            getsockopt(socket_fd, SOL_SOCKET, SO_ERROR, &err, &len);
            if (err == 0) {
                printf("Port %d open\n", i);
            }
        }

        close(socket_fd);
    }

    return 0;
}