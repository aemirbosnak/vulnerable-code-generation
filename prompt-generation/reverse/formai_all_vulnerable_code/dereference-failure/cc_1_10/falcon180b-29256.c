//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char **argv) {
    int listen_fd, conn_fd, addrlen;
    struct sockaddr_in listen_addr, conn_addr;
    char http_request[MAX_LINE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error: socket() failed\n");
        exit(1);
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error: bind() failed\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("Error: listen() failed\n");
        exit(1);
    }

    printf("HTTP proxy server started on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(conn_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &addrlen);
        if (conn_fd == -1) {
            printf("Error: accept() failed\n");
            continue;
        }

        while (1) {
            memset(http_request, 0, MAX_LINE);
            if (recv(conn_fd, http_request, MAX_LINE, 0) <= 0) {
                printf("Error: recv() failed\n");
                close(conn_fd);
                break;
            }

            printf("Received request: %s", http_request);

            if (send(conn_fd, http_request, strlen(http_request), 0) == -1) {
                printf("Error: send() failed\n");
                close(conn_fd);
                break;
            }
        }
    }

    close(listen_fd);
    return 0;
}